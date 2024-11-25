#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

// Seminar structure to store seminar details
struct Seminar {
    int id;
    string title;
    string date;
    string description;
    string speaker;
};

vector<Seminar> seminars;

// Function to load seminars from file
void loadSeminars() {
    ifstream file("seminars.txt");
    if (!file) {
        cout << "Error: Could not open seminars.txt!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        size_t pos3 = line.find(',', pos2 + 1);
        size_t pos4 = line.find(',', pos3 + 1);

        if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos && pos4 != string::npos) {
            int id = stoi(line.substr(0, pos1));
            string title = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string date = line.substr(pos2 + 1, pos3 - pos2 - 1);
            string description = line.substr(pos3 + 1, pos4 - pos3 - 1);
            string speaker = line.substr(pos4 + 1);
            seminars.push_back({id, title, date, description, speaker});
        }
    }
    file.close();
}

// Function to add a seminar
void addSeminar() {
    int id = seminars.size() + 1;
    string title, date, description, speaker;
    cout << "Enter seminar title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter seminar date (YYYY-MM-DD): ";
    getline(cin, date);
    cout << "Enter seminar description: ";
    getline(cin, description);
    cout << "Enter seminar speaker: ";
    getline(cin, speaker);

    seminars.push_back({id, title, date, description, speaker});

    ofstream file("seminars.txt", ios::app);
    if (!file) {
        cout << "Error: Could not open seminars.txt!" << endl;
        return;
    }
    file << id << "," << title << "," << date << "," << description << "," << speaker << endl;
    file.close();

    cout << "Seminar added successfully!" << endl;
}

// Function to view all seminars
void viewSeminars() {
    cout << "Seminars List:" << endl;
    for (const auto &seminar : seminars) {
        cout << seminar.id << ". " << seminar.title << " on " << seminar.date << " by " << seminar.speaker << endl;
    }
}

// Function to manage blacklisting
void manageBlacklisting() {
    cout << "Blacklist functionality to be implemented here!" << endl;
}

// Function to manage overdue tracking
void manageOverdue() {
    cout << "Overdue tracking functionality to be implemented here!" << endl;
}

// Admin menu function
void adminMenu() {
    loadSeminars();

    int choice;
    while (true) {
        cout << endl << "Admin Menu" << endl;
        cout << "1. Add Seminar" << endl;
        cout << "2. View Seminars" << endl;
        cout << "3. Manage Blacklisting" << endl;
        cout << "4. Manage Overdue Tracking" << endl;
        cout << "5. Exit Admin Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            addSeminar();
        } else if (choice == 2) {
            viewSeminars();
        } else if (choice == 3) {
            manageBlacklisting();
        } else if (choice == 4) {
            manageOverdue();
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }
}