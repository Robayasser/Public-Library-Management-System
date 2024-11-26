#include <iostream>
#include "library.h"

int main() {
    Library library;
    library.loadData(); // Load data at startup

    int choice;
    do {
        std::cout << "\nPublic Library Management System";
        std::cout << "\n1. Admin Login";
        std::cout << "\n2. User Login";
        std::cout << "\n3. Exit";
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                library.adminLogin();
                break;
            case 2:
                library.userLogin();
                break;
            case 3:
                library.saveData(); // Save data at closure
                std::cout << "Exiting system. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
