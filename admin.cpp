#include "admin.h"
#include "user.h"
#include <iostream>
#include <map> // Include the map header

// Function to manage books
void Admin::manageBooks(std::vector<Book> &books) {
  int choice;
  do {
    std::cout << "\nBook Management:";
    std::cout << "\n1. Add Book";
    std::cout << "\n2. Edit Book";
    std::cout << "\n3. Delete Book";
    std::cout << "\n4. View All Books";
    std::cout << "\n5. Return to Main Menu";
    std::cout << "\nEnter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1: {
      Book book;
      std::cout << "Enter book title: ";
      std::cin >> book.title;
      std::cout << "Enter book author: ";
      std::cin >> book.author;
      std::cout << "Enter book category: ";
      std::cin >> book.category;
      book.isBorrowed = false;
      books.push_back(book);
      std::cout << "Book added successfully!\n";
      break;
    }
    case 2:
      std::cout << "Editing books is not implemented yet.\n";
      break;
    case 3:
      std::cout << "Deleting books is not implemented yet.\n";
      break;
    case 4:
      std::cout << "Books in library:\n";
      for (const auto &book : books) {
        std::cout << "Title: " << book.title << ", Author: " << book.author
                  << ", Category: " << book.category
                  << ", Borrowed: " << (book.isBorrowed ? "Yes" : "No") << "\n";
      }
      break;
    case 5:
      std::cout << "Returning to Main Menu...\n";
      break;
    default:
      std::cout << "Invalid choice. Try again.\n";
    }
  } while (choice != 5);
}

// Function to manage seminars
void Admin::manageSeminars(std::vector<Seminar> &seminars) {
  int choice;
  do {
    std::cout << "\nSeminar Management:";
    std::cout << "\n1. Add Seminar";
    std::cout << "\n2. View All Seminars";
    std::cout << "\n3. Return to Main Menu";
    std::cout << "\nEnter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1: {
      Seminar seminar;
      std::cout << "Enter seminar title: ";
      std::cin >> seminar.title;
      std::cout << "Enter seminar description: ";
      std::cin >> seminar.description;
      std::cout << "Enter speaker name: ";
      std::cin >> seminar.speaker;
      seminars.push_back(seminar);
      std::cout << "Seminar added successfully!\n";
      break;
    }
    case 2:
      std::cout << "Seminars in library:\n";
      for (const auto &seminar : seminars) {
        std::cout << "Title: " << seminar.title
                  << ", Description: " << seminar.description
                  << ", Speaker: " << seminar.speaker << "\n";
      }
      break;
    case 3:
      std::cout << "Returning to Main Menu...\n";
      break;
    default:
      std::cout << "Invalid choice. Try again.\n";
    }
  } while (choice != 3);
}

void Admin::manageUsers(std::map<std::string, User> &userMap) {
  int choice;
  do {
    std::cout << "\nUser Management:";
    std::cout << "\n1. View All Users";
    std::cout << "\n2. Add User";
    std::cout << "\n3. Delete User";
    std::cout << "\n4. Return to Main Menu";
    std::cout << "\nEnter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1: {
      std::cout << "Registered Users:\n";
      for (const auto &pair : userMap) {
        const std::string &username = pair.first;
        const User &user = pair.second;
        std::cout << "Username: " << username << ", User ID: " << user.userID
                  << ", Borrow History: "
                  << (user.borrowHistory.empty() ? "None" : "") << "\n";
        for (const auto &book : user.borrowHistory) {
          std::cout << "  - " << book << "\n";
        }
      }
      break;
    }
    case 2: {
      User newUser;
      std::cout << "Enter username: ";
      std::cin >> newUser.username;
      std::cout << "Enter password: ";
      std::cin >> newUser.password;
      newUser.userID =
          "U" + std::to_string(userMap.size() + 1); // Generate a user ID
      userMap[newUser.username] = newUser;
      std::cout << "User added successfully! User ID: " << newUser.userID
                << "\n";
      break;
    }
    case 3: {
      std::string usernameToDelete;
      std::cout << "Enter username of the user to delete: ";
      std::cin >> usernameToDelete;
      if (userMap.erase(usernameToDelete)) {
        std::cout << "User deleted successfully.\n";
      } else {
        std::cout << "User not found.\n";
      }
      break;
    }
    case 4:
      std::cout << "Returning to Main Menu...\n";
      break;
    default:
      std::cout << "Invalid choice. Try again.\n";
    }
  } while (choice != 4);
}
