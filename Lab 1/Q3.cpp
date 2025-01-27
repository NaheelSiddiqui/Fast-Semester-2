#include <iostream>
#include<string>
#include<iomanip>

using namespace std;

int main() {
    int consumerID, units;
    string consumerName;

    cout << "Enter consumer ID: ";
    cin >> consumerID;
    cout << "Enter consumer name: ";
    cin >> consumerName;
    cout << "Enter units Consumed: ";
    cin >> units;

    float charges = 0;

    if (units < 200) {
        charges = 16.20;
    } 
    else if (units >= 200 && units < 300) {
        charges = 20.10;
    } 
    else if (units >= 300 && units < 500) {
        charges = 27.10;
    } 
    else if (units >= 500) {
        charges = 35.90;
    } 
    else {
        cout << "Invalid Input" << endl;
        return 0;
    }

    float bill = units * charges;
    float surcharge = 0;

    if (bill > 18000) {
        surcharge = bill * 0.15;
    }

    float netAmount = bill + surcharge;

    cout << fixed << setprecision(2);

    cout << "Consumer ID: " << consumerID << endl << "Consumer Name: " << consumerName << endl << "Units Consumed: " << units << endl << "Charges per unit: " << charges << endl << "Surcharge Amount (only if total > 18000): " << surcharge << endl << "Net Amount Paid By Customer: " << netAmount;

    return 0;
}