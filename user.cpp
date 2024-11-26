#include "user.h"
#include <algorithm>
#include <iostream>


User::User() : username(""), userID(""), password("") {}

User::User(const std::string &username, const std::string &userID,
           const std::string &password)
    : username(username), userID(userID), password(password) {}

// Search for books
void User::searchBooks(const std::vector<Book> &books) const {
  std::string query;
  int choice;

  std::cout << "\nSearch Books by:";
  std::cout << "\n1. Title";
  std::cout << "\n2. Author";
  std::cout << "\n3. Category";
  std::cout << "\nEnter your choice: ";
  std::cin >> choice;

  std::cout << "Enter your search query: ";
  std::cin.ignore();
  std::getline(std::cin, query);

  std::cout << "\nSearch Results:\n";
  bool found = false;

  for (const auto &book : books) {
    bool match = false;
    if (choice == 1 && book.title.find(query) != std::string::npos) {
      match = true;
    } else if (choice == 2 && book.author.find(query) != std::string::npos) {
      match = true;
    } else if (choice == 3 && book.category.find(query) != std::string::npos) {
      match = true;
    }

    if (match) {
      std::cout << "Title: " << book.title << ", Author: " << book.author
                << ", Category: " << book.category
                << ", Borrowed: " << (book.isBorrowed ? "Yes" : "No") << "\n";
      found = true;
    }
  }

  if (!found) {
    std::cout << "No books found matching your query.\n";
  }
}

// Borrow a book
void User::borrowBook(std::vector<Book> &books) {
  std::cout << "First, search for books to borrow.\n";
  searchBooks(books);

  std::cout << "\nEnter the title of the book you want to borrow: ";
  std::string title;
  std::getline(std::cin, title);

  std::cout << "Trying to borrow: " << title << "\n";

  for (auto &book : books) {
    if (book.title == title && !book.isBorrowed) {
      borrowHistory.push_back(book.title);
      std::cout << "You have successfully borrowed: " << book.title << "\n";
      return;
    }
  }

  std::cout << "Book not available or already borrowed.\n";
}

// View borrowing history
void User::viewBorrowHistory() const {
  std::cout << "Borrowing History for " << username << ":\n";
  if (borrowHistory.empty()) {
    std::cout << "No borrowing history.\n";
  } else {
    for (const auto &bookTitle : borrowHistory) {
      std::cout << "- " << bookTitle << "\n";
    }
  }
}

// Register for a seminar
void User::registerForSeminar(std::vector<Seminar> &seminars) {
  std::cout << "Available Seminars:\n";
  for (size_t i = 0; i < seminars.size(); ++i) {
    std::cout << i + 1 << ". " << seminars[i].title << " by "
              << seminars[i].speaker << "\n";
  }

  int choice;
  std::cout << "Enter the number of the seminar to register (or 0 to cancel): ";
  std::cin >> choice;

  if (choice > 0 && choice <= seminars.size()) {
    std::cout << "You have registered for: " << seminars[choice - 1].title
              << "\n";
  } else {
    std::cout << "Invalid choice.\n";
  }
}

// Provide feedback for a seminar
void User::provideFeedback(std::vector<Seminar> &seminars) {
  std::cout << "Seminars you can provide feedback for:\n";
  for (size_t i = 0; i < seminars.size(); ++i) {
    std::cout << i + 1 << ". " << seminars[i].title << "\n";
  }

  int choice;
  std::cout << "Enter the number of the seminar to provide feedback (or 0 to "
               "cancel): ";
  std::cin >> choice;

  if (choice > 0 && choice <= seminars.size()) {
    std::cout << "Enter your feedback: ";
    std::string feedback;
    std::cin.ignore();
    std::getline(std::cin, feedback);

    seminars[choice - 1].addFeedback(feedback);
    std::cout << "Thank you for your feedback!\n";
  } else {
    std::cout << "Invalid choice.\n";
  }
}
