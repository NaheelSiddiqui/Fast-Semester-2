#include <iostream>

using namespace std;

class Car {
private:
    int horsepower;
    int seatingCapacity;
    int noOfSpeakers;

public:
    Car(int hp, int seats, int num) : horsepower(hp), seatingCapacity(seats), noOfSpeakers(num) {}

    void updateAttributes(int& hp_ref, int& seats_ref, int& speakers_ref, int hp, int seats, int speakers) const {
        hp_ref = hp;
        seats_ref = seats;
        speakers_ref = speakers;
    }

    int& get_hp_ref() { return horsepower; }
    int& get_seats_ref() { return seatingCapacity; }
    int& get_speakers_ref() { return noOfSpeakers; }

    void display() const {
        cout << "Engine HP: " << horsepower << "\n";
        cout << "Seating Capacity: " << seatingCapacity << "\n";
        cout << "Number of Speakers: " << noOfSpeakers << "\n";
    }
};

int main() {
    Car car1(150, 6, 6);
    car1.display();
    car1.updateAttributes(car1.get_hp_ref(), car1.get_seats_ref(), car1.get_speakers_ref(), 300, 10, 8);
    
    cout << "\nAfter Updating\n";

    car1.display();

    car1.display();
    
    return 0;
}