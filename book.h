#ifndef BOOK_H // include this file only once
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
       const std::string &category, bool isBorrowed = false); //creates a book with given details 

  // Member functions
  void display() const; // display details 
};

#endif
