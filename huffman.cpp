#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// A Huffman tree node
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Comparison object for priority queue (min-heap)
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to print Huffman Codes using preorder traversal
void printCodes(Node* root, string code) {
    if (!root)
        return;

    // Print the code if it's a leaf node
    if (!root->left && !root->right) {
        cout << code << " ";
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

// Function to build Huffman Tree and print codes
void HuffmanCodes(char S[], int f[], int N) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Step 1: Create leaf nodes for each character and push into priority queue
    for (int i = 0; i < N; i++) {
        pq.push(new Node(S[i], f[i]));
    }

    // Step 2: Build the tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Step 3: Print Huffman Codes in preorder
    printCodes(pq.top(), "");
}

// Main function
int main() {
    string S = "abcdef";
    int f[] = {5, 9, 12, 13, 16, 45};
    int N = S.size();

    char chars[N];
    for (int i = 0; i < N; i++)
        chars[i] = S[i];

    HuffmanCodes(chars, f, N);
    cout << endl;
    return 0;
}
