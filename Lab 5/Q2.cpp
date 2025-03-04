#include<iostream>
#include<vector>
using namespace std;

class Car {
    private:
        int car_id;
        string model_name;

    public:
        Car(int id, string name) : car_id(id), model_name(name) {}

        string getModel() {
            return model_name;
        }

        int getId() {
            return car_id;
        }
};

class Garage {
    private:
        vector<Car*> parked_cars;

    public: 
        void parkCar(Car* c) {
            parked_cars.push_back(c);
        }

        void showParkedCars() {
            for(Car* c : parked_cars) {
                cout << c->getModel() << " , " << c->getId() << '\n';
            }
        }
};

int main() {
    Car car1(100, "Corolla"), car2(110, "Civic");
    Garage g;
    g.parkCar(&car1);
    g.parkCar(&car2);
    g.showParkedCars();

    return 0;
}
