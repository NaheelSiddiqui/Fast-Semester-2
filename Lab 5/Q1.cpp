#include<iostream>
using namespace std;

class Engine{
    public:
        void startEngine() {
            cout << "Engine has started" << endl;
        }
        
        void stopEngine() {
            cout << "Engine has stopped" << endl;
        }
        
        ~Engine() {
            // Destructor for Engine class
        }
};

class Car{
    private: 
        Engine engine;

    public:
        void start() {
            engine.startEngine();
        }

        void stop() {
            engine.stopEngine();
        }

        ~Car() {
            // Destructor for Car class
        }
};

int main(){
    Car myCar;
    myCar.start();
    myCar.stop();

    return 0;
}