#include <iostream>
#include <string>
using namespace std;

typedef struct Employee {
    string empName;
    int empID;
    double salary;
} Employee;

typedef struct Organization {
    string orgName;
    string orgNumber;
    struct Employee {
        string empName;
        int empID;
        double salary;
    } emp;
} Organization;

int main() {
    Organization org;

    org.orgName = "NU-Fast";
    org.orgNumber = "NUFAST123ABC";
    org.emp.empID = 127;
    org.emp.empName = "Linus Sebastian";
    org.emp.salary = 400000;

    cout << "The size of structure organisation : " << sizeof(org) << " bytes" << endl;
    cout << "Organisation Name : " << org.orgName << endl;
    cout << "Organisation Number : " << org.orgNumber << endl;
    cout << "Employee id : " << org.emp.empID << endl;
    cout << "Employee name : " << org.emp.empName << endl;
    cout << "Employee Salary : " << org.emp.salary << endl;

    return 0;
}