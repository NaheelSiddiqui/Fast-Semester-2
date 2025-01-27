#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string name;
    float scores[5];
    cout << "Enter name: ";
    cin >> name;
    float average = 0;
    for (int i=0; i<5; i++) {
        cout << "Enter score " << i+1 << ": ";
        cin >> scores[i];
        average += scores[i];
    }
    average /= 5;
    cout << fixed << setprecision(2);
    cout << endl << "Student Name: " << name;
    cout << endl << "Scores: ";
    for (int i=0; i<5; i++) {
        cout << scores[i] << " ";
    }
    cout << endl << "Average score: " << average;
    return 0;
}