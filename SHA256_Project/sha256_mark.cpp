#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdint>

// --- SHA256 Implementation ---
class SHA256 {
private:
    uint64_t bitlen = 0;
    uint32_t hash[8];
    std::vector<uint8_t> buffer;

    static inline uint32_t rotr(uint32_t x, uint32_t n) { return (x >> n) | (x << (32 - n)); }
    static inline uint32_t ch(uint32_t x, uint32_t y, uint32_t z) { return (x & y) ^ (~x & z); }
    static inline uint32_t maj(uint32_t x, uint32_t y, uint32_t z) { return (x & y) ^ (x & z) ^ (y & z); }
    static inline uint32_t sig0(uint32_t x) { return rotr(x, 7) ^ rotr(x, 18) ^ (x >> 3); }
    static inline uint32_t sig1(uint32_t x) { return rotr(x, 17) ^ rotr(x, 19) ^ (x >> 10); }
    static inline uint32_t ep0(uint32_t x) { return rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22); }
    static inline uint32_t ep1(uint32_t x) { return rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25); }

    void process() {
        uint32_t w[64];
        for (size_t i = 0; i < 16; ++i) {
            w[i] = (buffer[i*4] << 24) | (buffer[i*4+1] << 16) | (buffer[i*4+2] << 8) | buffer[i*4+3];
        }
        for (size_t i = 16; i < 64; ++i) {
            w[i] = sig1(w[i-2]) + w[i-7] + sig0(w[i-15]) + w[i-16];
        }

        uint32_t a = hash[0], b = hash[1], c = hash[2], d = hash[3];
        uint32_t e = hash[4], f = hash[5], g = hash[6], h = hash[7];

        static const uint32_t k[64] = {
            0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
            0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
            0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
            0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
            0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
            0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
            0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
            0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
        };

        for (size_t i = 0; i < 64; ++i) {
            uint32_t t1 = h + ep1(e) + ch(e, f, g) + k[i] + w[i];
            uint32_t t2 = ep0(a) + maj(a, b, c);
            h = g; g = f; f = e; e = d + t1;
            d = c; c = b; b = a; a = t1 + t2;
        }

        hash[0] += a; hash[1] += b; hash[2] += c; hash[3] += d;
        hash[4] += e; hash[5] += f; hash[6] += g; hash[7] += h;
        bitlen += 512;
        buffer.clear();
    }

public:
    SHA256() { reset(); }

    void reset() {
        bitlen = 0;
        const uint32_t init[8] = {
            0x6a09e667,0xbb67ae85,0x3c6ef372,0xa54ff53a,
            0x510e527f,0x9b05688c,0x1f83d9ab,0x5be0cd19
        };
        memcpy(hash, init, sizeof(init));
        buffer.clear();
    }

    void update(const std::string &data) {
        for (unsigned char c : data) {
            buffer.push_back(c);
            if (buffer.size() == 64) process();
        }
    }

    void finalize() {
        uint64_t totalBits = bitlen + buffer.size() * 8;
        buffer.push_back(0x80);
        while ((buffer.size() + 8) % 64 != 0) buffer.push_back(0x00);

        for (int i = 7; i >= 0; --i)
            buffer.push_back((totalBits >> (i*8)) & 0xFF);

        while (!buffer.empty()) process();
    }

    std::string digest() const {
        char buf[65];
        for (int i = 0; i < 8; i++)
            sprintf(buf + i*8, "%08x", hash[i]);
        buf[64] = 0;
        return std::string(buf);
    }
};

// --- Read file ---
std::string read_file(const std::string &filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open " << filename << std::endl;
        return "";
    }
    return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

// --- Main ---
int main() {
    std::string filename = "mark.txt";
    std::cout << "Reading Book of Mark from file: " << filename << std::endl;

    std::string text = read_file(filename);
    if (text.empty()) {
        std::cerr << "File is empty or could not be read." << std::endl;
        return 1;
    }

    SHA256 sha;
    sha.update(text);
    sha.finalize();

    std::cout << "SHA-256 hash of Book of Mark:" << std::endl;
    std::cout << sha.digest() << std::endl;

    return 0;
}
