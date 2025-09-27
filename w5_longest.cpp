#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string str1, str2;
	cout << "Enter first string: ";
	cin >> str1;
	cout << "Enter second string: ";
	cin >> str2;

	int len = str1.size(); 
	vector<vector<int>> lut(len + 1, vector<int>(len + 1, 0));

	int maxLen = 0;
	int endIndex = 0; 

   
	for (int i = 1; i <= len; i++) {
		for (int j = 1; j <= len; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				lut[i][j] = lut[i - 1][j - 1] + 1;
				if (lut[i][j] > maxLen) {
					maxLen = lut[i][j];
					endIndex = i;  
				}
			} else {
				lut[i][j] = 0;
			}
		}
	}

    
	cout << "\nLookup Table(lut):\n";
	for (int i = 0; i <= len; i++) {
		for (int j = 0; j <= len; j++) {
			cout << lut[i][j] << " ";
		}
		cout << endl;
	}

    
	string lcs = str1.substr(endIndex - maxLen, maxLen);
	cout << "\nLongest Common Substring: " << lcs << endl;
	cout << "Length: " << maxLen << endl;

	return 0;
}
