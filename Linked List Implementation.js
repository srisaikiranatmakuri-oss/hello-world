#include <iostream>
using namespace std;

// Node structure for non-zero elements
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

// Sparse Matrix implemented with Linked List
class SparseMatrix {
private:
    Node* head;

public:
    SparseMatrix() {
        head = nullptr;
    }

    // Insert a non-zero value
    void insert(int r, int c, int v) {
        if (v == 0) return; // Skip zero values
        Node* newNode = new Node(r, c, v);

        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    // Display stored sparse matrix elements
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

    // Example insertions (non-zero elements)
    sm.insert(0, 0, 10);
    sm.insert(0, 2, 5);
    sm.insert(1, 1, 8);
    sm.insert(3, 2, 12);

    cout << "Sparse Matrix (Linked List Representation):\n";
    sm.display();

    return 0;
}