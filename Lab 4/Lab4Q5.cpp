#include <iostream>
#include <string>

using namespace std;

class Cafe {
private:
    string shopName;
    struct Item {
        string name;
        string category;
        double cost;
    };

    Item menu[100];
    string orderList[100];
    int menuCount = 0;
    int orderCount = 0;

public:
    Cafe(const string& name) : shopName(name) {}

    void addItemToMenu(const string& name, const string& category, double cost) {
        if (menuCount < 100) {
            menu[menuCount].name = name;
            menu[menuCount].category = category;
            menu[menuCount].cost = cost;
            menuCount++;
            cout << name << " has been added to the menu." << endl;
        } else {
            cout << "Menu is at full capacity." << endl;
        }
    }

    void placeOrder(const string& itemName) {
        for (int i = 0; i < menuCount; i++) {
            if (menu[i].name == itemName) {
                if (orderCount < 100) {
                    orderList[orderCount] = itemName;
                    orderCount++;
                    cout << itemName << " has been ordered." << endl;
                    return;
                }
            }
        }
        cout << "Item is not available." << endl;
    }

    string processOrder() {
        if (orderCount == 0) {
            return "All orders have been processed";
        } else {
            string currentOrder = orderList[0];
            for (int i = 0; i < orderCount - 1; i++) {
                orderList[i] = orderList[i + 1];
            }
            orderCount--;
            return currentOrder + " is ready";
        }
    }

    void showOrders() {
        if (orderCount == 0) {
            cout << "No orders have been placed yet." << endl;
        } else {
            cout << "Pending Orders: ";
            for (int i = 0; i < orderCount; i++) {
                cout << orderList[i] << " ";
            }
            cout << endl;
        }
    }

    double calculateTotal() {
        double total = 0;
        for (int i = 0; i < orderCount; i++) {
            for (int j = 0; j < menuCount; j++) {
                if (menu[j].name == orderList[i]) {
                    total += menu[j].cost;
                }
            }
        }
        return total;
    }

    string getCheapestItem() {
        if (menuCount == 0) {
            return "Menu is empty";
        }

        string cheapestItem = menu[0].name;
        double minPrice = menu[0].cost;

        for (int i = 1; i < menuCount; i++) {
            if (menu[i].cost < minPrice) {
                minPrice = menu[i].cost;
                cheapestItem = menu[i].name;
            }
        }
        return cheapestItem;
    }

    void showDrinks() {
        bool found = false;
        for (int i = 0; i < menuCount; i++) {
            if (menu[i].category == "drink") {
                cout << menu[i].name << " ";
                found = true;
            }
        }
        if (!found) cout << "No drinks available.";
        cout << endl;
    }

    void showFood() {
        bool found = false;
        for (int i = 0; i < menuCount; i++) {
            if (menu[i].category == "food") {
                cout << menu[i].name << " ";
                found = true;
            }
        }
        if (!found) cout << "No food available.";
        cout << endl;
    }
};

int main() {
    Cafe myCafe("Brewed Awakening");

    int option;
    string item, category;
    double price;
    
    while (true) {
        cout << "\n--- Cafe Management ---\n";
        cout << "1. Add Item to Menu\n";
        cout << "2. Place Order\n";
        cout << "3. Process Order\n";
        cout << "4. View Orders\n";
        cout << "5. View Total Due\n";
        cout << "6. View Cheapest Item\n";
        cout << "7. View Drinks\n";
        cout << "8. View Food\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter item name: ";
                cin >> item;
                cout << "Enter category (food/drink): ";
                cin >> category;
                cout << "Enter price: ";
                cin >> price;
                myCafe.addItemToMenu(item, category, price);
                break;
            case 2:
                cout << "Enter item name to order: ";
                cin >> item;
                myCafe.placeOrder(item);
                break;
            case 3:
                cout << myCafe.processOrder() << endl;
                break;
            case 4:
                myCafe.showOrders();
                break;
            case 5:
                cout << "Total due: $" << myCafe.calculateTotal() << endl;
                break;
            case 6:
                cout << "Cheapest item: " << myCafe.getCheapestItem() << endl;
                break;
            case 7:
                cout << "Drinks: ";
                myCafe.showDrinks();
                break;
            case 8:
                cout << "Food: ";
                myCafe.showFood();
                break;
            case 9:
                cout << "Exiting the system." << endl;
                return 0;
            default:
                cout << "Invalid option. Try again." << endl;
        }
    }

    return 0;
}
