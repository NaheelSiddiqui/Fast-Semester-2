#include<iostream>
using namespace std;

class Student {
    public:
        virtual int getTuition(string classification, int hours) = 0;
        virtual ~Student() {}
};

class GraduateStudent: public Student {
    private:
        string dissertationArea;

    public:
        void assignTopic(string area) { dissertationArea = area; }
        string fetchTopic() { return dissertationArea; }

        int getTuition(string classification, int hours) override {
            int fee = 0;
            if (classification == "Undergraduate") {
                fee = 200 * hours;
            } else if (classification == "Graduate") {
                fee = 300 * hours;
            } else if (classification == "Doctoral") {
                fee = 400 * hours;
            }
            return fee;
        }
};

int main() {
    GraduateStudent learner;
    learner.assignTopic("AI in Healthcare");
    cout << "Research Area: " << learner.fetchTopic() << endl;

    string academicLevel;
    int enrolledCredits;

    cout << "Input academic classification (Undergraduate / Graduate / Doctoral): ";
    cin >> academicLevel;
    cout << "Input total credit hours: ";
    cin >> enrolledCredits;

    double calculatedFee = learner.getTuition(academicLevel, enrolledCredits);
    cout << "Tuition Due: $" << calculatedFee << endl;

    return 0;
}
