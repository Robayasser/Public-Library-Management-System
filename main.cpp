#include <iostream>
#include "Admin.h"
#include "User.h"

using namespace std;

void adminMenu() {
    int choice;

    while (true) {
        cout << endl << "Admin Menu" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. View All Books" << endl;
        cout << "3. View Books by Category" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            addBook();
        } else if (choice == 2) {
            viewBooks();
        } else if (choice == 3) {
            viewBooksByCategory();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }
}

void userMenu() {
    int choice;

    while (true) {
        cout << endl << "User Menu" << endl;
        cout << "1. Search Books" << endl;
        cout << "2. Borrow a Book" << endl;
        cout << "3. View Borrowing History" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            searchBooks();
        } else if (choice == 2) {
            borrowBook();
        } else if (choice == 3) {
            viewBorrowHistory();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }
}

int main() {
    int choice;

    while (true) {
        cout << endl << "Welcome to the Public Library Management System" << endl;
        cout << "1. Admin" << endl;
        cout << "2. User" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            adminMenu();
        } else if (choice == 2) {
            userMenu();
        } else if (choice == 3) {
            cout << "Exiting. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
