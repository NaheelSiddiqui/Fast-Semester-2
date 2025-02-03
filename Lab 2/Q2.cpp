#include <iostream>
#include <string>
using namespace std;

void* addarr(int *array,int argc) {
    for(int i = 0; i < argc-1; i++) {
        array[i] += i;
    }
    return (void*)argc;
}

int main(int argc, char *argv[]) {
    int array[argc - 1];
    for (int i=0; i < argc-1; i++) {
        array[i] = stoi(argv[i+1]);    
    }
    
    addarr(array, argc);
    
    for (int i=0; i < argc-1; i++) {
        cout << array[i] << " ";
    }
    
    return 0;
}