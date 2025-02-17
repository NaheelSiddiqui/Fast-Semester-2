#include <iostream>

using namespace std;

class Account {
private:
    double balance;

public:
    Account(double initialBalance) {
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0.0;
            cout << "Starting balance is invalid. Setting it to 0.0" << endl;
        }
    }

    void addFunds(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdrawFunds(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient balance for this withdrawal." << endl;
        }
    }

    double checkBalance() const {
        return balance;
    }
};

int main() {
    Account user(100.0);
    cout << "Opening Balance: $" << user.checkBalance() << endl;

    user.addFunds(50.0);
    cout << "After deposit: $" << user.checkBalance() << endl;

    user.withdrawFunds(30.0);
    cout << "After withdrawal: $" << user.checkBalance() << endl;

    user.withdrawFunds(150.0);
    cout << "Final balance: $" << user.checkBalance() << endl;

    return 0;
}
