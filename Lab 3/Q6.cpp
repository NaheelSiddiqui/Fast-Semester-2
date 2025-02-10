#include <iostream>
#include <string>
using namespace std;

class Matrix {
    private:
        int rows;
        int columns;
        int matrixID;
        int **elements;
    public:
        Matrix(int r, int c, int ID) {
            rows = r;
            columns = c;
            matrixID = ID;
            elements = new int*;
            for (int i=0; i<rows; i++) {
                elements[i] = new int[columns];
            }
            for (int i=0; i<rows; i++) {
                cout << "\nEnter elements for row " << i+1 << ": ";
                for (int j=0; j<columns; j++) {
                    cin >> elements[i][j];
                }
            }
        }
        int getRows() {
            return rows;
        }
        int getColumns() {
            return columns;
        }
        void changeElement(int row, int column) {
            int number;
            cout << "Enter new number";
            cin >> number;
            elements[row-1][column-1] = number;
        }
        void addMatrices(Matrix ID2) {
            if (this->columns != ID2.columns || this->rows != ID2.rows) {
                cout << "Matrices cannot be added";
            } else {
                cout << "Result of addition: \n";
                for (int i=0; i<rows; i++) {
                    for (int j=0; j<columns; j++) {
                        cout << this->elements[i][j] + ID2.elements[i][j] << " ";
                    }
                    cout << endl;
                }
            }
        }
        void multiplyMatrices(Matrix ID2) {
            if (this->columns != ID2.rows) {
                cout << "Matrices cannot be multiplied";
            } 
            else {
                for (int i=0; i < this->rows; i++) {
                    for (int j=0; j < ID2.columns; j++) {
                        int sum = 0;
                        for (int k=0; k < this->columns; k++) {
                            sum += this->elements[i][k] * ID2.elements[k][j];
                        }
                        cout << sum << " ";
                    }
                    cout << endl;
                }
            }
        }
        void displayMatrix(int ID) {
            cout << "Matrix " << ID << ":" << endl;
            for (int i=0; i<this->rows; i++) {
                for (int j=0; j<this->columns; j++) {
                    cout << this->elements[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    Matrix matrices[4] = {Matrix(3, 3, 1), Matrix(2, 2, 2), Matrix(3, 3, 3), Matrix(4, 2, 4)};
    cout << "1. Get rows\n2. Get columns\n3. Change elements\n4. Add matrices\n5. Multiply matrices (order matters)\n6. Display a matrix\n7. Exit program";
    int option, end = 1;
    int ID, ID1, ID2, rows, columns, row, column;
    while (end==1) {
        cout << "\nEnter option: ";
        cin >> option;
        switch (option) {
            case 1:
                cout << "Enter ID of matrix: ";
                cin >> ID;
                rows = matrices[ID-1].getRows();
                cout << "Matrix " << ID << " has " << rows << " rows";
                option = 0;
                break;
            case 2:
                cout << "Enter ID of matrix: ";
                cin >> ID;
                columns = matrices[ID-1].getColumns();
                cout << "Matrix " << ID << " has " << columns << " columns";
                option = 0;
                break;
            case 3:
                cout << "Enter ID of matrix: ";
                cin >> ID;
                cout << "Enter row number of element: ";
                cin >> row;
                cout << "Enter column number of element: ";
                cin >> column;
                matrices[ID-1].changeElement(row, column);
                option = 0;
                break;
            case 4:
                cout << "Enter ID of matrix 1: ";
                cin >> ID1;
                cout << "Enter ID of matrix 2: ";
                cin >> ID2;
                matrices[ID1-1].addMatrices(matrices[ID2-1]);
                option = 0;
                break;
            case 5:
                cout << "Enter ID of matrix 1: ";
                cin >> ID1;
                cout << "Enter ID of matrix 2: ";
                cin >> ID2;
                matrices[ID1-1].multiplyMatrices(matrices[ID2-1]);
                option = 0;
                break;
            case 6: 
                cout << "Enter ID of matrix 1: ";
                cin >> ID;
                matrices[ID-1].displayMatrix(ID);
                option = 0;
                break;
            case 7:
                end = 0;
                break;
            default:
                cout << "Incorrect input";
                break;
        }
    }
    return 0;
}