#ifndef USER_H
#define USER_H

#include "book.h"
#include "seminar.h"
#include <string>
#include <vector>

class User {
public:
  // Data members
  std::string username;
  std::string userID;
  std::string password;
  std::vector<std::string> borrowHistory;

  // Constructors
  User();
  User(const std::string &username, const std::string &userID,
       const std::string &password);

  // Member functions
  void searchBooks(const std::vector<Book> &books) const;
  void borrowBook(std::vector<Book> &books);
  void viewBorrowHistory() const;
  void registerForSeminar(std::vector<Seminar> &seminars);
  void provideFeedback(std::vector<Seminar> &seminars);
};

#endif
