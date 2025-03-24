#include <iostream>
#include <vector>
using namespace std;

class Course;

class Person {
protected:
    string name, id, address, phone, email;
public:
    Person(string name, string id, string address, string phone, string email)
        : name(name), id(id), address(address), phone(phone), email(email) {}

    virtual void showDetails() const {
        cout << "Name: " << name << "\nID: " << id << "\nAddress: " << address
             << "\nPhone: " << phone << "\nEmail: " << email << endl;
    }

    virtual void updateDetails(string newAddress, string newPhone, string newEmail) {
        address = newAddress;
        phone = newPhone;
        email = newEmail;
    }

    virtual ~Person() {}
};

class Student : public Person {
private:
    vector<string> enrolledCourses;
    double GPA;
    int yearOfEnrollment;
public:
    Student(string name, string id, string address, string phone, string email, int year, double GPA)
        : Person(name, id, address, phone, email), yearOfEnrollment(year), GPA(GPA) {}

    void enrollInCourse(const string& course) {
        enrolledCourses.push_back(course);
    }

    void showDetails() const override {
        Person::showDetails();
        cout << "Year of Enrollment: " << yearOfEnrollment << "\nGPA: " << GPA << "\nCourses Enrolled: ";
        for (const string& course : enrolledCourses) {
            cout << course << " ";
        }
        cout << endl;
    }
};

class Professor : public Person {
private:
    string department;
    vector<string> taughtCourses;
    double salary;
public:
    Professor(string name, string id, string address, string phone, string email, string dept, double salary)
        : Person(name, id, address, phone, email), department(dept), salary(salary) {}

    void assignCourse(const string& course) {
        taughtCourses.push_back(course);
    }

    void showDetails() const override {
        Person::showDetails();
        cout << "Department: " << department << "\nSalary: $" << salary << "\nCourses Taught: ";
        for (const string& course : taughtCourses) {
            cout << course << " ";
        }
        cout << endl;
    }
};

class Staff : public Person {
private:
    string department;
    string position;
    double salary;
public:
    Staff(string name, string id, string address, string phone, string email, string dept, string pos, double salary)
        : Person(name, id, address, phone, email), department(dept), position(pos), salary(salary) {}

    void showDetails() const override {
        Person::showDetails();
        cout << "Department: " << department << "\nPosition: " << position << "\nSalary: $" << salary << endl;
    }
};

class Course {
private:
    string courseId, courseName, instructor, schedule;
    int credits;
public:
    Course(string courseId, string courseName, int credits, string instructor, string schedule)
        : courseId(courseId), courseName(courseName), credits(credits), instructor(instructor), schedule(schedule) {}

    void addStudent(Student& student) {
        student.enrollInCourse(courseName);
    }

    void showCourseDetails() const {
        cout << "Course ID: " << courseId << "\nCourse Name: " << courseName
             << "\nCredits: " << credits << "\nInstructor: " << instructor
             << "\nSchedule: " << schedule << endl;
    }
};

int main() {
    Student student1("Alice", "S123", "123 St", "123-456", "alice@email.com", 2022, 3.8);
    Professor professor1("Dr. Smith", "P456", "456 St", "456-789", "smith@email.com", "CS", 75000);
    Staff staff1("Mr. Johnson", "ST789", "789 St", "789-123", "johnson@email.com", "Admin", "Manager", 50000);
    Course course1("CS101", "Intro to CS", 3, "Dr. Smith", "MWF 9 AM");

    professor1.assignCourse("Intro to CS");

    course1.addStudent(student1);

    cout << "\n--- Student Details ---\n";
    student1.showDetails();
    
    cout << "\n--- Professor Details ---\n";
    professor1.showDetails();

    cout << "\n--- Staff Details ---\n";
    staff1.showDetails();

    cout << "\n--- Course Details ---\n";
    course1.showCourseDetails();

    return 0;
}
