#include <iostream>
using namespace std;

class Shape {
public:
    virtual void getArea() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    void getArea() override {
        double area = length * width;
        cout << "Rectangle Area = " << area << endl;
    }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    void getArea() override {
        double area = 0.5 * base * height;
        cout << "Triangle Area = " << area << endl;
    }
};

int main() {
    Shape *s1, *s2;

    s1 = new Rectangle(5.0, 10.0);
    s2 = new Triangle(4.0, 6.0);

    s1->getArea();
    s2->getArea();

    delete s1;
    delete s2;

    return 0;
}
