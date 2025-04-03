#include <iostream>
using namespace std;

class Shape {
    private:
        double area;

    public:
        Shape(double a = 0) : area(a) {}

        Shape operator+(const Shape& other) {
            return Shape(this->area + other.area);
        }

        void display() {
            cout << "Area = " << area << endl;
        }
};


int main() {
    Shape first(20.6);
    Shape second(35.2);

    cout << "First";
    first.display();
    cout << "Second";
    second.display();
    Shape third = first + second;

    cout << "After adding = shapes: ";
    third.display();

    return 0;
}