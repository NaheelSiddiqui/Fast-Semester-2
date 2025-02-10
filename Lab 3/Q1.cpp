#include <iostream>
#include <string>
using namespace std;

class User {
    public:
        int age;
        string name;
};

int main() {
    User person1;
    person1.name = "Teo";
    person1.age = 24;
    cout << "My name is " << person1.name << " and I'm " << person1.age << " years old";

    return 0;
}