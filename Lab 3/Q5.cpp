#include <iostream>
#include <string>
using namespace std;

class Book {
    private:
        string name;
        int ISBN;
        string author;
        string publisher;
    public:
        string getName() {
            return name;
        }
        int getISBN() {
            return ISBN;
        }
        string getAuthor() {
            return author;
        }
        string getPublisher() {
            return publisher;
        }
        void setDetails(string bookName, int bookISBN, string bookAuthor, string bookPublisher) { // constructor
            name = bookName;
            ISBN = bookISBN;
            author = bookAuthor;
            publisher = bookPublisher;
        }
};

int main() {
    Book array[5];
    for (int i=0; i<5; i++) {
        string bookName;
        int bookISBN;
        string bookAuthor;
        string bookPublisher;
        cout << "Enter book " << i+1 << " name: ";
        cin >> bookName;
        cout << "Enter book " << i+1 << " ISBN: ";
        cin >> bookISBN;
        cout << "Enter book " << i+1 << " author: ";
        cin >> bookAuthor;
        cout << "Enter book " << i+1 << " publisher: ";
        cin >> bookPublisher;
        array[i].setDetails(bookName, bookISBN, bookAuthor, bookPublisher);
    }

    cout << "Instructions\n1. Get book name\n2. Get book ISBN number\n3. Get book author\n4. Get book publisher\n5. Get all book info\n6. Exit program";
    int option = 0, i = 0;
    int end = 1;
    while (end == 1) {
        cout << "\nEnter choice: ";
        cin >> option;
        cout << "Enter book's array number: ";
        cin >> i;
        string name, author, publisher;
        int ISBN;
        switch (option) {
            case 1: 
                name = array[i].getName();
                cout << "Name = " << name;  
                break;   
            case 2:
                ISBN = array[i].getISBN();
                cout << "ISBN = " << ISBN;
                break;
            case 3:
                author = array[i].getAuthor();
                cout << "Author = " << author;
                break;
            case 4:
                publisher = array[i].getPublisher();
                cout << "Publisher = " << publisher;
                break;
            case 5:
                name = array[i].getName();
                ISBN = array[i].getISBN();
                author = array[i].getAuthor();
                publisher = array[i].getPublisher();
                cout << "The book is " << name << ", with ISBN number " << ISBN << ", written by " << author << " and published by " << publisher;
                break;
            case 6:
                end = 0;
                break;
            default:
                cout << "Incorrect input";
                break;
        }
    }

    return 0;
}