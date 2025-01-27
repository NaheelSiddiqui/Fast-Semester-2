#include <iostream>
#include <string>
using namespace std;

int main() {
    string movieName;
    int adultTickets, adultPrice;
    int childTickets, childPrice;
    float perc;
    cout << "Enter movie name: ";
    cin >> movieName;
    cout << endl << "Enter number of adult tickets: ";
    cin >> adultTickets;
    cout << endl << "Enter price of an adult ticket: ";
    cin >> adultPrice;
    cout << endl << "Enter number of children's tickets: ";
    cin >> childTickets;
    cout << endl << "Enter price of a children's ticket: ";
    cin >> childPrice;
    cout << endl << "Enter percentage to donate: ";
    cin >> perc;
    int grossAmount = (adultTickets*adultPrice) + (childPrice*childTickets);
    float donation = (perc/100) * grossAmount;
    float finalAmount = grossAmount - donation;
    cout << "Movie Name: " << movieName << endl << "Number of Tickets Sold: " << adultTickets + childTickets << endl << "Gross Amount: " << grossAmount << endl << "Percentage of amount donated: " << perc << "%" << endl << "Amount donated: " << donation << endl << "Net Sale: " << finalAmount;

    return 0;
}