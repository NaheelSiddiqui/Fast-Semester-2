#include <iostream>

using namespace std;

class Item {
private:
    string name;
    string writer;
    double cost;
    string publisher;
    int quantity;

public:
    Item() {}

    void inputDetails() {
        cout << "Enter item name: ";
        cin >> name;
        cout << "Enter writer: ";
        cin >> writer;
        cout << "Enter cost: ";
        cin >> cost;
        cout << "Enter publisher: ";
        cin >> publisher;
        cout << "Enter quantity: ";
        cin >> quantity;
    }

    void displayDetails() const {
        cout << "Name: " << name << ", Writer: " << writer << ", Cost: " << cost
             << ", Publisher: " << publisher << ", Quantity: " << quantity << endl;
    }

    string getName() const {
        return name;
    }
};

class Store {
private:
    Item inventory[100];
    int count;

public:
    Store() : count(0) {}

    void addItem() {
        if (count < 100) {
            inventory[count].inputDetails();
            count++;
        } else {
            cout << "No space for more items." << endl;
        }
    }

    void showItems() {
        if (count == 0) {
            cout << "No items in stock." << endl;
            return;
        }
        for (int i = 0; i < count; i++) {
            inventory[i].displayDetails();
        }
    }

    void findItem(const string& name) {
        for (int i = 0; i < count; i++) {
            if (inventory[i].getName() == name) {
                inventory[i].displayDetails();
                return;
            }
        }
        cout << "Item not found." << endl;
    }
};

int main() {
    Store myStore;
    int option;

    while (true) {
        cout << "\nStore Management System\n";
        cout << "1. Add Item\n";
        cout << "2. Show All Items\n";
        cout << "3. Search for an Item\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                myStore.addItem();
                break;
            case 2:
                myStore.showItems();
                break;
            case 3: {
                string searchName;
                cout << "Enter item name to search: ";
                cin >> searchName;
                myStore.findItem(searchName);
                break;
            }
            case 4:
                cout << "Exiting the system.\n";
                return 0;
            default:
                cout << "Invalid option! Try again.\n";
        }
    }

    return 0;
}
