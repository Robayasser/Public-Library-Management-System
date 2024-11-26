#include "library.h"
#include <fstream>
#include <iostream>
#include <sstream>

void Library::loadData() {
  // Load books data
  std::ifstream booksFile("books.txt");
  if (booksFile.is_open()) {
    std::string line;
    while (getline(booksFile, line)) {
      if (line[0] == '#')
        continue;
      std::istringstream iss(line);
      Book book;
      getline(iss, book.title, '|');
      getline(iss, book.author, '|');
      getline(iss, book.category, '|');
      int borrowed;
      iss >> borrowed;
      book.isBorrowed = (borrowed == 1);
      books.push_back(book);
    }
    booksFile.close();
    std::cout << "Books data loaded.\n";
    std::cout << "Books vector contents:\n";
    for (const auto &book : books) {
      std::cout << "Title: " << book.title << ", Author: " << book.author
                << ", Category: " << book.category
                << ", IsBorrowed: " << book.isBorrowed << "\n";
    }
  } else {
    std::cout << "Books file not found.\n";
  }

  // Load users data
  std::ifstream usersFile("users.txt");
  if (usersFile.is_open()) {
    std::string line;
    while (getline(usersFile, line)) {
      if (line[0] == '#')
        continue;
      std::istringstream iss(line);
      User user;
      getline(iss, user.username, '|');
      getline(iss, user.userID, '|');
      getline(iss, user.password, '|');
      std::string history;
      getline(iss, history, '|');
      std::istringstream histStream(history);
      std::string bookTitle;
      while (getline(histStream, bookTitle, ',')) {
        user.borrowHistory.push_back(bookTitle);
      }
      userMap[user.username] = user;
    }
    usersFile.close();
    std::cout << "Users data loaded.\n";
  } else {
    std::cout << "Users file not found.\n";
  }

  // Load seminars data
  std::ifstream seminarsFile("seminars.txt");
  if (seminarsFile.is_open()) {
    std::string line;
    while (getline(seminarsFile, line)) {
      if (line[0] == '#')
        continue;
      std::cout << "Reading line: " << line << "\n"; // Debug print for line content
      Seminar seminar;
      std::istringstream iss(line);
      getline(iss, seminar.title, '|');
      getline(iss, seminar.description, '|');
      getline(iss, seminar.speaker, '|');
      seminars.push_back(seminar);
    }
    seminarsFile.close();
    std::cout << "Seminars data loaded.\n";
    std::cout << "Seminars vector contents:\n";
    for (const auto &seminar : seminars) {
      std::cout << "Title: " << seminar.title
                << ", Description: " << seminar.description
                << ", Speaker: " << seminar.speaker << "\n";
    }
  } else {
    std::cout << "Seminars file not found.\n";
  }
}

void Library::saveData() {
  // Save books data
  std::ofstream booksFile("books.txt");
  if (booksFile.is_open()) {
    booksFile << "# Book Data: title|author|category|isBorrowed (1 for true, 0 "
                 "for false)\n";
    for (const auto &book : books) {
      booksFile << book.title << "|" << book.author << "|" << book.category
                << "|" << (book.isBorrowed ? 1 : 0) << "\n";
    }
    booksFile.close();
    std::cout << "Books data saved.\n";
  }

  // Save users data
  std::ofstream usersFile("users.txt");
  if (usersFile.is_open()) {
    usersFile << "# User Data: username|userID|password|borrowHistory\n";
    for (const auto &pair : userMap) {          // Traditional iterator loop
      const std::string &username = pair.first; // Extract key (username)
      const User &user = pair.second;           // Extract value (User object)
      usersFile << username << "|" << user.userID << "|" << user.password
                << "|";
      for (size_t i = 0; i < user.borrowHistory.size(); ++i) {
        usersFile << user.borrowHistory[i];
        if (i < user.borrowHistory.size() - 1)
          usersFile << ","; // Comma-separated history
      }
      usersFile << "\n";
    }
    usersFile.close();
    std::cout << "Users data saved.\n";
  }

  // Save seminars data
  std::ofstream seminarsFile("seminars.txt");
  if (seminarsFile.is_open()) {
    seminarsFile << "# Seminar Data: title|description|speaker\n";
    for (const auto &seminar : seminars) {
      seminarsFile << seminar.title << "|" << seminar.description << "|"
                   << seminar.speaker << "\n";
    }
    seminarsFile.close();
    std::cout << "Seminars data saved.\n";
  }
}

void Library::adminLogin() {
  std::cout << "Admin logged in.\n";
  int choice;
  do {
    std::cout << "\n1. Manage Books\n2. Manage Users\n3. Manage Seminars\n4. "
                 "Logout\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    switch (choice) {
    case 1:
      admin.manageBooks(books);
      break;
    case 2:
      admin.manageUsers(userMap);
      break;
    case 3:
      admin.manageSeminars(seminars);
      break;
    case 4:
      std::cout << "Logging out.\n";
      break;
    default:
      std::cout << "Invalid choice.\n";
    }
  } while (choice != 4);
}

void Library::userLogin() {
  std::string username, password;
  std::cout << "Enter username: ";
  std::cin >> username;
  std::cout << "Enter password: ";
  std::cin >> password;

  auto it = userMap.find(username);
  if (it != userMap.end() && it->second.password == password) {
    std::cout << "Welcome, " << username << "!\n";
    User &loggedInUser = it->second;
    int choice;
    do {
      std::cout << "\n1. Search Books\n2. Borrow Book\n3. View Borrow History\n"
                   "4. Register for Seminar\n5. Provide Feedback\n6. Logout\n";
      std::cout << "Enter your choice: ";
      std::cin >> choice;
      switch (choice) {
      case 1:
        loggedInUser.searchBooks(books);
        break;
      case 2:
        loggedInUser.borrowBook(books);
        break;
      case 3:
        loggedInUser.viewBorrowHistory();
        break;
      case 4:
        loggedInUser.registerForSeminar(seminars);
        break;
      case 5:
        loggedInUser.provideFeedback(seminars);
        break;
      case 6:
        std::cout << "Logging out.\n";
        break;
      default:
        std::cout << "Invalid choice.\n";
      }
    } while (choice != 6);
  } else {
    std::cout << "Invalid username or password.\n";
  }
}
