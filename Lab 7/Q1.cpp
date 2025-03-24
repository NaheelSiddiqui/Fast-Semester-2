#include <iostream>
using namespace std;

struct previousTransactions {
    bool withdraw;
    double amount;
};

class Account {
    protected:
        int accountNumber;
        double balance;
        string accountHolderName;
        previousTransactions *previous[10];
        static int totalAccounts;

    public:
        int getAccountNumber() { return accountNumber; }
        double getBalance() { return balance; }
        string getAccountHolderName() { return accountHolderName; }

        Account() : accountNumber(totalAccounts++), balance(0), accountHolderName("") { 
            for (int i = 0; i < 10; i++) previous[i] = NULL; 
        }
        Account(double b, string n) : accountNumber(totalAccounts++), balance(b), accountHolderName(n) { 
            for (int i = 0; i < 10; i++) previous[i] = NULL; 
        }

        void deposit(double d) { 
            balance += d; 
            for (int i = 0; i < 10; i++) {
                if (previous[i] == NULL) {
                    previous[i] = new previousTransactions;  // Allocate memory
                    previous[i]->withdraw = false;
                    previous[i]->amount = d;
                    return;
                }
            }   
            for (int i = 0; i < 9; i++) {
                previous[i] = previous[i + 1];
            }
            previous[9] = new previousTransactions;  // Allocate memory
            previous[9]->amount = d;
            previous[9]->withdraw = false;
        } 

        virtual void withdraw(double w) {
            if (w > balance) cout << "Not enough funds" << endl;
            else {
                balance -= w;
                cout << "$" << w << " withdrawn, $" << balance << " remaining" << endl;
                for (int i = 0; i < 10; i++) {
                    if (previous[i] == NULL) {
                        previous[i] = new previousTransactions;  // Allocate memory
                        previous[i]->withdraw = true;
                        previous[i]->amount = w;
                        return;
                    }
                }   
                for (int i = 0; i < 9; i++) {
                    previous[i] = previous[i + 1];
                }
                previous[9] = new previousTransactions;  // Allocate memory
                previous[9]->amount = w;
                previous[9]->withdraw = true;
            }
        }

        virtual void calculateInterest() {}

        void printStatement() {
            cout << "Account Number: " << accountNumber << ", Holder Name: " << accountHolderName << endl;
            cout << "Last 10 transactions: " << endl;
            for (int i = 0; previous[i] != NULL; i++) {
                cout << "$" << previous[i]->amount;
                if (previous[i]->withdraw) cout << " withdrawn";
                else cout << " deposited";
                cout << endl;
            }
        }

        void getAccountInfo() { cout << "Name: " << accountHolderName << ", Current Balance: " << balance << ", Account Number: " << accountNumber << endl; }

        ~Account() {
            for (int i = 0; i < 10; i++) {
                if (previous[i] != NULL) {
                    delete previous[i];  // Free the allocated memory
                }
            }
        }
};

int Account::totalAccounts = 0; // initialization of static variable


class SavingsAccount : public Account {
    private:
        double interestRate;
        double minBalance;

    public: 
        SavingsAccount() : Account(), interestRate(0), minBalance(0) {}
        SavingsAccount(double b, string n, double r, double min) : Account(b, n), interestRate(r), minBalance(min) {}

        void calculateInterest() override {
            cout << "$" <<  interestRate / 100 * balance  << " are added to your savings account as interest" << endl;
            balance += (interestRate / 100 * balance);
        }

        void withdraw(double w) override {
            if ((balance - w) < minBalance) cout << "Cannot withdraw as going below minimum account balance" << endl;
            else Account::withdraw(w);
        }
};

class CheckingAccount : public Account {
    private:
        double overdraftLimit;
        double overdraftUsed;
        bool overdraftStatus;

    public:
        CheckingAccount() : Account(), overdraftLimit(0), overdraftUsed(0), overdraftStatus(false) {}
        CheckingAccount(double b, string n, double ol, double ou, bool os) : Account(b, n), overdraftLimit(ol), overdraftUsed(ou), overdraftStatus(os) {}

        void withdraw(double w) override {
            if (w > balance) {
                if (w > (balance + (overdraftLimit - overdraftUsed))) cout << "Can't withdraw this amount even with overdraft" << endl;
                else {
                    overdraftUsed += (w - balance);  // Correct overdraft logic
                    balance = 0;
                    cout << "$" << w << " withdrawn using overdraft" << endl;
                }
            } else {
                Account::withdraw(w);
            }
        }
};

class FixedDepositAccount : public Account {
    private:
        bool maturityDate; // false if dues not met by the date
        double fixedInterestRate;
    
    public:
        FixedDepositAccount() : Account(), maturityDate(false), fixedInterestRate(0) {}
        FixedDepositAccount(double b, string n, bool m, double f) : Account(b, n), maturityDate(m), fixedInterestRate(f) {}

        void calculateInterest() override {
            cout << "$" <<  fixedInterestRate / 100 * balance  << " are added to your savings account as interest" << endl;
            balance += (fixedInterestRate / 100 * balance);
        }

        void withdraw(double w) override {
            if (maturityDate) Account::withdraw(w);
            else cout << "Clear your dues first, maturity date has passed" << endl;
        }
};

int main() {
    Account acc1(1000, "Alice");
    SavingsAccount sAcc1(1500, "Bob", 5, 500);
    CheckingAccount cAcc1(2000, "Charlie", 500, 100, false);
    FixedDepositAccount fAcc1(2000, "David", true, 6);

    acc1.deposit(500);
    sAcc1.deposit(200);
    cAcc1.deposit(300);
    
    sAcc1.withdraw(400);  // Should work
    cAcc1.withdraw(2200); // Should use overdraft
    fAcc1.withdraw(500);  // Should work

    sAcc1.calculateInterest();
    fAcc1.calculateInterest();
    
    acc1.getAccountInfo();
    sAcc1.getAccountInfo();
    cAcc1.getAccountInfo();
    fAcc1.getAccountInfo();
    
    return 0;
}
