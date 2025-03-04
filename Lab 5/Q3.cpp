#include <iostream>
#include <vector>

using namespace std;

class Book {
    public:
        string name;
        string author;
        int isbn;

        Book(string n, string a, int i) : name(n), author(a), isbn(i) {}
};

class Catalog {
    private:
        vector<Book*> index;

    public: 
        void addBook(Book* b) {
            index.push_back(b);
        }

        void removeBook(int isbn) {
            bool found = false;
            for (auto i = index.begin(); i != index.end(); i++) {
                if ((*i)->isbn == isbn) {
                    index.erase(i);
                    cout << "Book removed" << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Book not found" << endl;
            }
        }

        void findBook(int isbn) {
            bool found = false;
            for (auto i = index.begin(); i != index.end(); i++) {
                if ((*i)->isbn == isbn) {
                    cout << "Book name: " << (*i)->name << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Book not found" << endl;
            }
        }
};

class Library {
    private:
        Catalog catalog;
        vector<Book*> books;
        string name;
        string address;
    
    public:
        Library(string n, string a) : name(n), address(a) {}
    
        void addBook(Book* book) {
            books.push_back(book);
            catalog.addBook(book);
            cout << "Book added" << endl;
        }
    
        void removeBook(int isbn) {
            for (auto i = books.begin(); i != books.end(); ++i) {
                if ((*i)->isbn == isbn) {
                    books.erase(i);
                    catalog.removeBook(isbn);
                    cout << "Book removed" << endl;
                    break;
                }
            }
        }
    
        void findBookInCatalog(int isbn) {
            catalog.findBook(isbn);
        }
};

int main() {
    Library l1("School Library", "School's Address");

    Book b1("Book1", "Author1", 101);
    Book b2("Book2", "Author2", 202);

    l1.addBook(&b1);
    l1.addBook(&b2);

    l1.findBookInCatalog(101);
    l1.findBookInCatalog(100);

    return 0;
}