#include <iostream>
#include <string>
using namespace std;

typedef struct data {
    int ID;
    string name;
} data;

int main() {
    int number;
    cout << "Enter number of structs you want to create: ";
    cin >> number;
    data *array = new data[number];
    for (int i=0; i<number; i++) {
        cout << "Enter ID of person " << i+1 << ": ";
        cin >> array[i].ID;
        cout << "Enter name of person " << i+1 << ": ";
        cin >> array[i].name;
    }

    for (int i=0; i < number-1; i++) {
        for (int j=0; j < number-1-i; j++) {
            if (array[j].ID > array[j+1].ID) {
                data temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    for (int i=0; i<number; i++) {
        cout << array[i].ID << " - " << array[i].name << endl;
    }
    
    cout << endl << endl;

    for (int i=0; i<number-1; i++) {
        for (int j=0; j < number-1-i; j++) {
            if (array[j].name[0] > array[j+1].name[0]) {
                data temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    for (int i=0; i<number; i++) {
        cout << array[i].ID << " - " << array[i].name << endl;
    }

    delete[] array;

    return 0;
}