#include <iostream>
#include <string>
using namespace std;

class Date {
    private:
        int day;
        int month;
        int year;
    public:
        void setDate(int d, int m, int y) {
            day = d;
            month = m;
            year = y;
        }
        void displayDate() {
            cout << "Date: " << day << "/" << month << "/" << year;
        }
};

int main() {
    Date dateTest;
    dateTest.setDate(31, 10, 2005);
    dateTest.displayDate();
    
    return 0;
}