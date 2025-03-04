#include <iostream>
#include <windows.h>

using namespace std;

class Blend {
    public:
        void blendJuice() { 
            cout << "Blending..." << endl;
            Sleep(4000);
        }
};

class Grind {
    public:
        void grindJuice() {
            cout << "Grinding..." << endl;
            Sleep(5000);
        }
};

class JuiceMaker {
    private:
        Blend b1;
        Grind g1;
    public: 
        void makeJuice() {
            b1.blendJuice();
            g1.grindJuice();
            cout << "Juice is ready" << endl;
        }
};

int main() {
    JuiceMaker j1;
    j1.makeJuice();
    return 0;
}