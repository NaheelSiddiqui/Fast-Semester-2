#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    float price;

public:
    Car(string m = "", float p = 0.0f) : model(m), price(p) {}

    string getModel() const { return model; }
    float getPrice() const { return price; }

    void setModel(string m) { model = m; }

    virtual void setPrice(float p) = 0;

    virtual void display() const {
        cout << "Car Model: " << model << " | Final Price: $" << price << endl;
    }

    virtual ~Car() {}
};

class Color : public Car {
private:
    string shade;

public:
    Color(string m, float p, string c) : Car(m, p), shade(c) {}

    void setColor(string c) { shade = c; }
    string getColor() const { return shade; }

    void setPrice(float p) override {
        price = p + (p * 0.07f);
    }

    void display() const override {
        Car::display();
        cout << "Color Variant: " << shade << endl;
    }
};

class Company : public Car {
private:
    string brand;

public:
    Company(string m, float p, string b) : Car(m, p), brand(b) {}

    void setCompany(string b) { brand = b; }
    string getCompany() const { return brand; }

    void setPrice(float p) override {
        price = p + 1200;
    }

    void display() const override {
        Car::display();
        cout << "Manufactured By: " << brand << endl;
    }
};

int main() {
    Color vehicleOne("Hatchback", 18000, "Midnight Blue");
    vehicleOne.setPrice(18000);
    cout << "=== Color Edition ===" << endl;
    vehicleOne.display();

    cout << endl;

    Company vehicleTwo("Crossover", 26000, "Hyundai");
    vehicleTwo.setPrice(26000);
    cout << "=== Company Edition ===" << endl;
    vehicleTwo.display();

    return 0;
}
