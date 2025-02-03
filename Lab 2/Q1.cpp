#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int array[argc-1];
    for (int i=0; i<5; i++) {
        array[i] = atoi(argv[i+1]);
    }
    int sum = 0;
    for (int i=0; i<(argc-1); i++) {
        sum += array[i];
    }
    cout << "Sum of elements = " << sum;

    return 0;
}