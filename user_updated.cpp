#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// A structure to represent users
struct User {
    int id;
    string username;
    string password;
};

vector<User> users;

// Function to load users from file
void loadUsers() {
    ifstream file("users.txt");
    if (!file) {
        cout << "Error: Could not open users.txt!" << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.rfind(',');
        if (pos1 != string::npos && pos2 != string::npos && pos1 != pos2) {
            int id = stoi(line.substr(0, pos1));
            string username = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string password = line.substr(pos2 + 1);
            users.push_back({id, username, password});
        }
    }
    file.close();
}

// Function to register a new user
void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    int newId = users.size() + 1;
    users.push_back({newId, username, password});

    ofstream file("users.txt", ios::app);
    if (!file) {
        cout << "Error: Could not open users.txt!" << endl;
        return;
    }
    file << newId << "," << username << "," << password << endl;
    file.close();

    cout << "Registration successful! Your user ID is " << newId << endl;
}

// Function to log in
bool loginUser(int &loggedInId) {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    for (const auto &user : users) {
        if (user.username == username && user.password == password) {
            loggedInId = user.id;
            return true;
        }
    }
    return false;
}

// Function to display user menu
void userMenu() {
    int loggedInId = -1;
    if (!loginUser(loggedInId)) {
        cout << "Invalid username or password!" << endl;
        return;
    }
    cout << "Welcome, User ID: " << loggedInId << endl;
    // Add user functionalities here (e.g., borrow book, view borrowing history)
}

int main() {
    loadUsers();
    int choice;
    while (true) {
        cout << "1. Register
2. Login
3. Exit
Enter choice: ";
        cin >> choice;
        if (choice == 1) {
            registerUser();
        } else if (choice == 2) {
            userMenu();
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}