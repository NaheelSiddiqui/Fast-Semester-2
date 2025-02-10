#include <iostream>
#include <string>
using namespace std;

class Glass {
    public:
        int liquidLevel;
        void Drink(int drink) {
            if (drink <= 200) {
                liquidLevel -= drink;
            } else {
                cout << "Not possible\n";
            }
        }
        void Refill() {
            liquidLevel = 200;
        }
};

int main() {
    cout << "Instructions:\nEnter 1 to drink\nEnter 2 to display current level\nEnter 3 to exit";

    Glass cup;
    cup.liquidLevel = 200;
    int option;
    int end = 1;
    while (end == 1) {
        cout << "\nEnter choice: ";
        cin >> option;
        switch (option) {
            case 1:
                int drink;
                cout << "Enter amount to drink: ";
                cin >> drink;
                cup.Drink(drink);
                if (cup.liquidLevel < 100) {
                    cup.liquidLevel = 200;
                }
                break;
            case 2:
                cout << "Current Level = " << cup.liquidLevel;
                break;
            case 3:
                cout << "Exiting with glass filled to " << cup.liquidLevel << "ml";
                end = 0;
                break;
            default:
                cout << "Wrong input";
                break;
        }
    }
    return 0;
}