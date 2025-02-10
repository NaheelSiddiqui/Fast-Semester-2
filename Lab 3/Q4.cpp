#include <iostream>
#include <string>
using namespace std;

class Employee {
    private:
        string firstName;
        string lastName;
        double salary;
    public:
        Employee(string fname, string lname, double sal) {
            firstName = fname;
            lastName = lname;
            if (sal < 0) {
                salary = 0.0;
            } else {
                salary = sal;
            }
        }
        void giveRaise() {
            salary *= 1.1;
        }
        void displaySalary() {
            cout << "\nSalary = " << salary;
        }
};

int main() {
    Employee emp1("Naheel", "Siddiqui", 200000);
    Employee emp2("Elon", "Musk", -200);

    emp1.displaySalary();
    emp2.displaySalary();

    emp1.giveRaise();
    emp2.giveRaise();

    emp1.displaySalary();
    emp2.displaySalary();

    return 0;
}