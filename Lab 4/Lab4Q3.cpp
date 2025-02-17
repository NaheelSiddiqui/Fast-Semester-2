#include <iostream>
#include <string>

using namespace std;

class Invoice {
private:
    string number;
    string description;
    int quantity;
    double itemPrice;

public:
    Invoice(string number, string description, int quantity, double itemPrice)
        : number(number), description(description), quantity(quantity), itemPrice(itemPrice) {
        if (this->quantity < 0) this->quantity = 0;
        if (this->itemPrice < 0) this->itemPrice = 0.0;
    }

    double calTotal() const {
        return quantity * itemPrice;
    }
};

int main() {
    Invoice order("1234", "Hammer", 5, 10.5);
    cout << "Total Invoice Amount: $" << order.calTotal() << endl;
    return 0;
}
