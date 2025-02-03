#include <iostream>
#include <stdexcept>
using namespace std;

void resize (int*& array, int *arraySize) {
    int newSize = (*arraySize) * 2;
    int* newArr = new int[newSize];

    for (int i = 0; i < (*arraySize); i++) {
        newArr[i] = array[i];
    }

    delete[] array;
    array = newArr; // new location
    (*arraySize) = newSize;
}

void resizeArray (int*& array, int* size, int count) {
    int* newArr = new int[count];
    for (int i = 0; i < count; i++) {
        newArr[i] = array[i];
    }

    delete[] array;
    array = newArr; // new location
    (*size) = count;
}

int main() {
    int arraySize = 5;
    int count = 0;
    int *array = new int[arraySize];

    while (1) {
        int value;
        cout << "Enter an integer (-1 to stop): ";
        cin >> value;

        if (value == -1) {
            break;
        }

        if (count >= arraySize) {
            resize(array, &arraySize);
        }

        array[count] = value;
        count++;
    }

    resizeArray(array, &arraySize, count); // at end so arraySize become = count

    for (int i=0; i < count; i++) {
        cout << "Element " << i+1 << ": " << array[i] << endl;
    }

    delete[] array;

    return 0;
}