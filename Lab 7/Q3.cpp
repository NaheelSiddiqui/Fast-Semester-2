#include <iostream>

using namespace std;

class Currency {
    protected:
        double amount;
        char currencySymbol;
        string currencyCode;
        double exchangeRate;
    
    public:
        Currency() : amount(0), currencySymbol('\0'), currencyCode(""), exchangeRate(0) {}
        Currency(double a, char cs, string cc, double e) : amount(a), currencySymbol(cs), currencyCode(cc), exchangeRate(e) {} // automatically to dollar as dollar is base

        virtual double convertToBase() {
            return amount * exchangeRate;
        }
    
        virtual double convertTo(double targetExchangeRate) {
            return amount * targetExchangeRate;
        }
    
        double getExchangeRate() {
            return exchangeRate;
        }
    
        virtual void displayCurrency() {
            cout << currencySymbol << amount << " (" << currencyCode << ")";
        }
};

class Dollar : public Currency {
    public:
        Dollar(double a) : Currency(a, '$', "USD40", 1.0) {}

        double convertToBase() override { 
            return amount; 
        }

        void displayCurrency() override {
            Currency::displayCurrency();
        }
};

class Euro : public Currency {
    public:
        Euro(double a) : Currency(a, 'E', "E202", 0.9) {} // 1 dollar = 0.9 euro

        double convertToBase() override { 
            return amount / exchangeRate; // euro to dollar
        }

        void displayCurrency() override {
            Currency::displayCurrency();
            cout << ", $1 = €" << exchangeRate << endl;
        }
};

class Rupees : public Currency {
    public:
        Rupees(double a) : Currency(a, 'R', "R101", 275) {} // 1 dollar = 275 pkr

        double convertToBase() override { 
            return amount / exchangeRate; // rupees to dollar
        }

        void displayCurrency() override {
            Currency::displayCurrency();
            cout << ", $1 = ₹" << exchangeRate << endl;
        }
};

int main() {
    Dollar dollar(100); // 100 USD
    Euro euro(50);     
    Rupees rupees(200000);    

    double convertedToEURO = dollar.convertTo(euro.getExchangeRate());
    double convertedToPKR = dollar.convertTo(rupees.getExchangeRate());

    cout << "100 USD in EURO: " << convertedToEURO << " EUR\n";
    cout << "100 USD in PKR: " << convertedToPKR << " PKR\n";

    double convertEuro = euro.convertToBase();
    cout << "Euro = $" << convertEuro << endl;

    double convertPKR = rupees.convertToBase();
    cout << "PKR = $" << convertPKR << endl;

    return 0;
}