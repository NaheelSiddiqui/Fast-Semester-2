#include <iostream>
#include <vector>

using namespace std;

class MenuItems {
    public:
        string name;
        double price;
        string type;

        MenuItems(string n, int p, string t) : name(n), price(p), type(t) {}
};

class CoffeeShop {
    public:
        string const name;
        vector<MenuItems*> menuItems;
        vector<MenuItems*> orders;

        CoffeeShop(string n) : name(n) {}

        void addToMenu(MenuItems* m) {
            menuItems.push_back(m);
            cout << "Item added to menu" << endl;
        }

        void addOrder(string find) {
            bool found = false;
            for (MenuItems* i : menuItems) {
                if (i->name == find) {
                    orders.push_back(i);
                    found = true;
                    cout << "Item found in menu. Added to order" << endl;
                    break;
                }
            }
            if (!found) {
                cout << "This item is currently unavailable!" << endl;
            }
        }

        void fulfillOrder() {
            if (orders.size() == 0) {
                cout << "All orders have been fulfilled" << endl;
            } else {
                for (MenuItems* i : orders) {
                    cout << "The " << i->name << " is ready" << endl;
                }
            }
        }

        int listOrders() {
            return orders.size();
        }

        double amountDue() {
            double total = 0;
            for (MenuItems* i : orders) {
                total += i->price;
            }
            return total;
        }

        string cheapestItem() {
            int minIteration = 0;
            double min = menuItems[0]->price;
            for (int i = 1; i < menuItems.size(); i++) {
                if (menuItems[i]->price < min) {
                    min = menuItems[i]->price;
                    minIteration = i;
                }
            }
            return menuItems[minIteration]->name;
        }

        vector<string> drinksOnly() {
            vector<string> drinks;
            for (MenuItems* i : menuItems) {
                if (i->type == "drink") {
                    drinks.push_back(i->name);
                }
            }
            return drinks;
        }

        vector<string> foodOnly() {
            vector<string> foodItems;
            for (MenuItems* i : menuItems) {
                if (i->type == "food") {
                    foodItems.push_back(i->name);
                }
            }
            return foodItems;
        }
};

int main() {
    MenuItems m1("Biryani", 300, "food"), m2("Roll", 150, "food"), m3("ColdDrink", 80, "drink"), m4("Water", 40, "drink");
    CoffeeShop drop("drop");

    drop.addToMenu(&m1);
    drop.addToMenu(&m2);
    drop.addToMenu(&m3);
    drop.addToMenu(&m4);

    drop.addOrder("Biryani");
    drop.fulfillOrder();

    double amount = drop.amountDue();
    cout << "Amount due = " << amount << endl;

    vector<string> food = drop.foodOnly();
    for (int i = 0; i < food.size(); i++) {
        cout << food[i] << endl;
    }

    return 0;
}  