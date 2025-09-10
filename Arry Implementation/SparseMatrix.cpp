#include <iostream>
using namespace std;


struct Element {
    int rIndex, cIndex, data;
    Element* link;

    Element(int r, int c, int val) {
        rIndex = r;
        cIndex = c;
        data = val;
        link = nullptr;
    }
};


class MatrixLL {
private:
    Element* start;

public:
    MatrixLL() {
        start = nullptr;
    }

   
    void addNode(int r, int c, int val) {
        if (val == 0) return;  // ignore zeros
        Element* node = new Element(r, c, val);

        if (!start) {
            start = node;
        } else {
            Element* temp = start;
            while (temp->link) temp = temp->link;
            temp->link = node;
        }
    }

   
    void printMatrix() {
        Element* ptr = start;
        cout << "Row | Col | Value\n";
        cout << "-----------------\n";
        while (ptr) {
            cout << ptr->rIndex << "   | " << ptr->cIndex << "   | " << ptr->data << endl;
            ptr = ptr->link;
        }
    }
};

int main() {
    MatrixLL matrix;

   
    matrix.addNode(0, 1, 7);
    matrix.addNode(1, 3, 15);
    matrix.addNode(2, 2, 9);
    matrix.addNode(4, 0, 11);

    cout << "Sparse Matrix (Linked List Form):\n";
    matrix.printMatrix();

    return 0;
}
