#include <iostream>
using namespace std;

struct Element 
{
    int row;
    int col;
    int value;
    Element* next;
};

class SparseMatrix 
{
private:
    int totalRows;
    int totalCols;
    Element* head;

public:
    SparseMatrix(int rows, int cols) {
        totalRows = rows;
        totalCols = cols;
        head = nullptr;
    }

    void addElement(int r, int c, int val) 
    {
        if (r < 0 || r >= totalRows || c < 0 || c >= totalCols) 
        {
            cout << "Invalid position (" << r << "," << c << "). Skipping this element.\n";
            return;
        }
        Element* newNode = new Element{r, c, val, nullptr};
        if (!head) 
        {
            head = newNode;
        } else 
        {
            Element* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void displayMatrix() 
    {
        Element* temp = head;
        for (int i = 0; i < totalRows; i++) 
        {
            for (int j = 0; j < totalCols; j++) 
            {
                if (temp && temp->row == i && temp->col == j) 
                {
                    cout << temp->value << " ";
                    temp = temp->next;
                } else 
                {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main() 
{
    int rows, cols, nonZero;

    cout << "Enter number of rows and columns: ";
    if (!(cin >> rows >> cols) || rows <= 0 || cols <= 0) 
    {
        cout << "Invalid matrix size.\n";
        return 1;
    }

    cout << "Enter number of non-zero elements: ";
    if (!(cin >> nonZero) || nonZero < 0) 
    {
        cout << "Invalid number of non-zero elements.\n";
        return 1;
    }

    SparseMatrix matrix(rows, cols);

    for (int i = 0; i < nonZero; i++) 
    {
        int r, c, val;
        cout << "Enter row, column, value for element " << i + 1 << ": ";
        if (!(cin >> r >> c >> val)) 
        {
            cout << "Invalid input. Exiting.\n";
            return 1;
        }
        matrix.addElement(r, c, val);
    }

    cout << "\nMatrix form:\n";
    matrix.displayMatrix();

    return 0;
}
