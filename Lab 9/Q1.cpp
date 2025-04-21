#include <iostream>
using namespace std;

class Wallet {
    private:
        double balance;
        double todayDeposit, todayWithdrawal;
        static const double depositLimit;
        static const double withdrawalLimit;
    
    public: 
        Wallet(double b) : balance(b), todayWithdrawal(0), todayDeposit(0) {}
        Wallet() : balance(0) {}

        void deposit(double b) {
            if (todayDeposit + b > depositLimit) {
                cout << "Amount exceeding daily deposit limit" << endl;
                return;
            } else {
                balance += b;
                todayDeposit += b;
                cout << "Successfully deposited Rs. " << b << endl;
            }
        }

        void withdraw(double w) {
            if (todayWithdrawal + w > withdrawalLimit) {
                cout << "Amount exceeding daily withdrawal limit" << endl;
                return;
            } else if (w > balance) {
                cout << "Not enough funds in account" << endl;
                return;
            } else {
                balance -= w;
                todayWithdrawal += w;
                cout << "Successfully withdrawn Rs. " << w << endl;
            }
        }

        void resetDailyActions() {
            todayDeposit = 0;
            todayWithdrawal = 0;
        }

        double getBalance() { return balance; }
        
};

const double Wallet::depositLimit = 35000;
const double Wallet::withdrawalLimit = 20000;

class User {
    private:
        string name;
        int age;
        int userID;
        static int currentTotal;
        Wallet wallet;

    public:
        User(string n, int a, Wallet w) : name(n), age(a), userID(currentTotal++), wallet(w) {}

        void depositFundsInAccount() {
            double d;
            cout << "Enter amount to deposit: ";
            cin >> d;
            wallet.deposit(d);
        }

        void withdrawFundsFromAccount() {
            double w;
            cout << "Enter amount to withdraw: ";
            cin >> w;
            wallet.withdraw(w);
        }

        void checkBalance() {
            cout << "Your balance is Rs. " << wallet.getBalance() << endl; 
        }
};

int User::currentTotal = 0;

int main() {
    Wallet wallet1(10000);
    User alice("Alice", 30, wallet1);

    Wallet wallet2(5000); 
    User bob("Bob", 25, wallet2);

    alice.checkBalance();
    alice.depositFundsInAccount();   
    alice.withdrawFundsFromAccount(); 
    alice.checkBalance();

    cout << "------" << endl;

    bob.checkBalance();
    bob.depositFundsInAccount();  
    bob.withdrawFundsFromAccount(); 
    bob.checkBalance();

    return 0;
}