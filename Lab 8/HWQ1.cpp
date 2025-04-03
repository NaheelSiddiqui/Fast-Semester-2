#include <iostream>
using namespace std;

class Number {
    private:
        int value;
        
    public:
        Number(int v) : value(v) {}

        Number& operator--() {
            value *= 4;
            return *this;
        }

        Number operator--(int) {
            Number a = *this; 
            value /= 4;
            return a;
        }

        void display() const {
            cout << "Value = " << value << endl;
        }
};

int main() {
    Number number(6);

    cout << "Original: ";
    number.display();

    cout << "After Postfix = ";
    number--; 
    number.display();


    cout << "After Prefix = ";
    --number; 
    number.display();

    return 0;
}