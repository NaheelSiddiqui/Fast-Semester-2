#include <iostream>

using namespace std;

class Circle {
    
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calArea() const {
        return 3.14 * radius * radius;
    }

    double calPerimeter() const {
        return 2 * 3.14 * radius;
    }
};

int main() {
    Circle shape(5);
    cout << "Area: " << shape.calArea() << endl;
    cout << "Perimeter: " << shape.calPerimeter() << endl;
    return 0;
}
