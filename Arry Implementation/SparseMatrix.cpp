#include <iostream>
using namespace std;

// Node to store non-zero elements
struct Node {
    int row, col, value;
    Node* next;
    
    Node(int r, int c, int v) {
        row = r;
        col = c;
        value = v;
        next = nullptr;
    }
};

// Sparse Matrix 
class SparseMatrix {
private:
    Node* head;

public:
    SparseMatrix() {
        head = nullptr;
    }

    // Insert  non-zero value into the sparse matrix
    void insert(int r, int c, int v) {
        if (v == 0) return; 
        Node* newNode = new Node(r, c, v);

        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    // Display elements
    void display() {
        Node* temp = head;
        cout << "Row  Col  Value\n";
        while (temp) {
            cout << temp->row << "    " << temp->col << "    " << temp->value << endl;
            temp = temp->next;
        }
    }
};

int main() {
    SparseMatrix sm;

    // Example: Insert non-zero elements
    sm.insert(0, 0, 5);
    sm.insert(0, 3, 8);
    sm.insert(1, 1, 3);
    sm.insert(3, 2, 6);

    cout << "Sparse Matrix Representation (Linked List):\n";
    sm.display();

    return 0;
}