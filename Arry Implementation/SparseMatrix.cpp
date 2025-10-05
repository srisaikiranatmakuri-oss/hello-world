#include <iostream>
using namespace std;


struct Node {
    int r, c, data;
};

class SparseArray {
private:
    int totalRows, totalCols, nonZeroCount;
    Node* arr;

public:
  
    SparseArray(int rows, int cols, int count) {
        totalRows = rows;
        totalCols = cols;
        nonZeroCount = count;
        arr = new Node[nonZeroCount];
    }

   
    ~SparseArray() {
        delete[] arr;
    }

   
    void inputValues() {
        cout << "Enter row, column, value for " << nonZeroCount << " elements:\n";
        for (int i = 0; i < nonZeroCount; i++) {
            cin >> arr[i].r >> arr[i].c >> arr[i].data;
        }
    }

   
    void printMatrix() {
        int index = 0;
        for (int i = 0; i < totalRows; i++) {
            for (int j = 0; j < totalCols; j++) {
                if (index < nonZeroCount && arr[index].r == i && arr[index].c == j) {
                    cout << arr[index].data << " ";
                    index++;
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int m, n, k;
    cout << "How many rows and columns do you want: ";
    cin >> m >> n;

    cout << "Enter overall non-zero elements: ";
    cin >> k;

    SparseArray matrix(m, n, k);
    matrix.inputValues();

    cout << "\nMatrix form:\n";
    matrix.printMatrix();

    return 0;
}
