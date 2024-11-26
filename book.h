#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
  // Data members
  std::string title;
  std::string author;
  std::string category;
  bool isBorrowed;

  // Constructors
  Book(); // Default constructor
  Book(const std::string &title, const std::string &author,
       const std::string &category, bool isBorrowed = false);

  // Member functions
  void display() const;
};

#endif
