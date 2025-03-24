#include <iostream>
#include <cmath>

using namespace std;

class Shape {
    protected:
        double xPos, yPos;
        double borderThickness;
        string colour;
    
    public: 
        Shape() : xPos(0), yPos(0), borderThickness(0), colour("") {}
        Shape(double x, double y, double b, string c) : xPos(x), yPos(y), borderThickness(b), colour(c) {}

        virtual void draw() {
            cout << "Drawing a shape, with position (" << xPos << ", " << yPos << ") and colour " << colour << endl;
        }

        virtual void calculateArea() {}
        virtual void calculatePerimeter() {}

};

class Circle : public Shape {
    private:
        double radius;

    public:
        Circle() : Shape(), radius(0) {}
        Circle(double x, double y, double b, string c, double r) : Shape(x, y, b, c), radius(r) {}

        void draw() override {
            cout << "Drawing circle with center (" << xPos << ", " << yPos << "), radius " << radius << ", and colour " << colour << endl;
        }

        void calculateArea() override {
            cout << "Area : " << radius * radius * 3.14 << endl;
        }

        void calculatePerimeter() override {
            cout << "Perimeter : " << 2 * 3.14 * radius << endl;
        }
};


class Rectangle : public Shape {
    private:
        double width;
        double height;
        double topLeftX, topLeftY;

    public:
        Rectangle() : Shape(), width(0), height(0), topLeftX(0), topLeftY(0) {}
        Rectangle(double x, double y, double b, string c, double w, double h, double tx, double ty) : Shape(x, y, b, c), width(w), height(h), topLeftX(tx), topLeftY(ty) {}

        void draw() override {
            cout << "Drawing rectangle with top left corner (" << topLeftX << ", " << topLeftY << "), width " << width << ", height " << height << ", and colour " << colour << endl;
        }

        void calculateArea() override {
            cout << "Area : " << width * height << endl;
        }

        void calculatePerimeter() override {
            cout << "Perimeter : " << (2 * width) + (2 * height) << endl;
        }
};


class Triangle : public Shape {
    private:
        double sideA, sideB, sideC;

    public:
        Triangle() : Shape(), sideA(0), sideB(0), sideC(0) {}
        Triangle(double x, double y, double b, string c, double a, double b1, double c1) : Shape(x, y, b, c), sideA(a), sideB(b1), sideC(c1) {}

        void draw() override {
            cout << "Drawing triangle with top sides " << sideA << ", " << sideB << ", " << sideC << ", and colour " << colour << endl;
        }

        void calculateArea() override {
            double s = (sideA + sideB + sideC) / 2;
            cout << "Area : " << sqrt(s * (s - sideA) * (s - sideB) * (s - sideC)) << endl;
        }

        void calculatePerimeter() override {
            cout << "Perimeter : " << sideA + sideB + sideC << endl;
        }
};


class Polygon : public Shape {
    private:
        int sides;
        double length;

    public:
        Polygon() : Shape(), sides(0), length(0) {}
        Polygon(double x, double y, double b, string c, double s, double l) : Shape(x, y, b, c), sides(s), length(l) {}

        void draw() override {
            cout << "Drawing polygon with " << sides << " sides, each of length " << length << ", with colour " << colour << endl;
        }

        void calculateArea() override {
            cout << "Area : " << (sides * length * length) / (4 * tan(M_PI / sides)) << endl;
        }

        void calculatePerimeter() override {
            cout << "Perimeter : " << sides * length << endl;
        }
};


int main() {
    Circle circle(0, 0, 2, "Yellow", 7);
    Rectangle rectangle(2, 2, 1.5, "Blue", 7, 3, 0, 1);
    Triangle triangle(1, 1, 2, "Orange", 3, 3, 3);
    Polygon polygon(3, 3, 2, "Red", 5, 4);

    circle.calculateArea();
    circle.calculatePerimeter();

    rectangle.calculateArea();
    rectangle.calculatePerimeter();

    triangle.calculateArea();
    triangle.calculatePerimeter();

    polygon.calculateArea();
    polygon.calculatePerimeter();

    return 0;
}