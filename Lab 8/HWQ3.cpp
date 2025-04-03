#include <iostream>

using namespace std;

class Person {
    protected:
        int employeeID;

    public:
        Person(int id = 0) : employeeID(id) {}

        int getEmployeeID() const {
            return employeeID;
        }

        virtual double calculateBonus() const = 0;

        virtual void showData() const {
            cout << "Employee ID: " << employeeID << endl;
        }

        virtual ~Person() {}
};

class Admin : public Person {
    protected:
        string fullName;
        double salary;
        
    public:
        Admin(int id, string empName, double monthlySalary) : Person(id), fullName(empName), salary(monthlySalary) {}

        double calculateBonus() const override {
            return salary * 0.05 * 12;
        }

        void showData() const override {
            Person::showData();
            cout << "Name: " << fullName << endl;
            cout << "Monthly Salary: $" << salary << endl;
            cout << "Annual Bonus: $" << calculateBonus() << endl;
        }
};

class Accounts : public Person {
    protected:
        string fullName;
        double salary;

    public:
        Accounts(int id, string empName, double monthlySalary) : Person(id), fullName(empName), salary(monthlySalary) {}

        double calculateBonus() const override {
            return salary * 0.05 * 12;
        }

        void showData() const override {
            Person::showData();
            cout << "Name: " << fullName << endl;
            cout << "Monthly Salary: $" << salary << endl;
            cout << "Annual Bonus: $" << calculateBonus() << endl;
        }
};


int main() {
    Admin adminEmployee(101, "Naheel", 3500.0);
    Accounts accountsEmployee(102, "Attaullah", 3000.0);

    Person* employees[2] = { &adminEmployee, &accountsEmployee };

    cout << "\nEmployee Details:\n";
    for (int i = 0; i < 2; i++) {
        employees[i]->showData();
        cout << endl << endl;
    }

    return 0;
}