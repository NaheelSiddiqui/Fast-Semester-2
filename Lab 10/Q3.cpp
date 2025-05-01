#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

struct Product {
    int id;
    string name;
    double price;
};

struct User {
    int id;
    string name;
};

map<int, vector<int>> userProducts;

void createDummyData() {
    ofstream products("products.txt");
    products << "1 Laptop 999.99\n";
    products << "2 Phone 699.99\n";
    products << "3 Tablet 399.99\n";
    
    ofstream users("users.txt");
    users << "1 Linus\n";
    users << "2 Alice\n";
    
    ofstream up("user_products.txt");
    up << "1 1\n";
    up << "1 2\n";
    up << "2 3\n";
}

vector<string> getProductsForUser(const string& userName) {
    ifstream users("users.txt");
    int userId = -1;
    string name;
    while (users >> userId >> name) {
        if (name == userName) break;
    }
    
    if (userId == -1) return {};
    
    ifstream up("user_products.txt");
    int uid, pid;
    vector<int> productIds;
    while (up >> uid >> pid) {
        if (uid == userId) productIds.push_back(pid);
    }
    
    ifstream products("products.txt");
    int id;
    string pname;
    double price;
    vector<string> result;
    while (products >> id >> pname >> price) {
        for (int pid : productIds) {
            if (pid == id) result.push_back(pname);
        }
    }
    
    return result;
}

int main() {
    createDummyData();
    auto products = getProductsForUser("Linus");
    for (const auto& p : products) {
        cout << p << endl;
    }
    return 0;
}
