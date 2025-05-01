#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> readTasks() {
    ifstream file("todo.txt");
    vector<string> tasks;
    string task;
    while (getline(file, task)) {
        tasks.push_back(task);
    }
    return tasks;
}

void writeTasks(const vector<string>& tasks) {
    ofstream file("todo.txt");
    for (const auto& task : tasks) {
        file << task << endl;
    }
}

void addTask(const string& task) {
    ofstream file("todo.txt", ios::app);
    file << "[ ] " << task << endl;
}

void markDone(int index) {
    auto tasks = readTasks();
    if (index >= 0 && index < tasks.size()) {
        if (tasks[index].find("[ ]") == 0) {
            tasks[index].replace(0, 3, "[X]");
        }
    }
    writeTasks(tasks);
}

void showTasks() {
    auto tasks = readTasks();
    for (int i = 0; i < tasks.size(); i++) {
        cout << i << ": " << tasks[i] << endl;
    }
}

int main() {
    cout << "1. Add task\n2. View tasks\n3. Mark done\nChoice: ";
    int choice;
    cin >> choice;
    cin.ignore();
    
    if (choice == 1) {
        string task;
        cout << "Enter task: ";
        getline(cin, task);
        addTask(task);
    } else if (choice == 2) {
        showTasks();
    } else if (choice == 3) {
        showTasks();
        cout << "Enter task number: ";
        int num;
        cin >> num;
        markDone(num);
    }
    
    return 0;
}
