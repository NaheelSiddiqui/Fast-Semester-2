#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    float weightkg, weightlb; 
    cout << "Enter your weight in kilograms: ";
    cin >> weightkg;
    weightlb = weightkg * 2.2;

    cout << fixed << setprecision(2);

    cout << weightkg << " kilograms equals " << weightlb << " pounds" << endl;
    return 0;
}
