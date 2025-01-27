#include <iostream>
#include <string>
using namespace std;

int main() {
    float array[20];
    for (int i=0; i<20; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> array[i];
    }
    float max = 0, iOfMax;
    for (int i=0; i<20; i++) {
        if (array[i] > max) {
            max = array[i];
            iOfMax = i;
        }
    }
    max = 0;
    for (int i=0; i<20; i++) {
        if (i != iOfMax) {
            if (array[i] > max) {
                max = array[i];
            }
        }
    }
    cout << endl << "Second highest number = " << max;
    return 0;
}