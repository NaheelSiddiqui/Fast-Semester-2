#include <iostream>
using namespace std;

class Student {
    private:
        const int rollNo;

    public:
        Student(int r) : rollNo(r) {}

        void display() const {
            cout << "Student Roll No: " << this->rollNo << endl;
        }
};

int main() {
    int rollNo;
    cout << "Enter Student Roll Number: ";
    cin >> rollNo;

    Student s1(rollNo);
    s1.display();

    return 0;
}