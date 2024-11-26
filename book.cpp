#include "book.h"
#include <iostream>

// Default constructor, empty book // sets emoty text
Book::Book() : title(""), author(""), category(""), isBorrowed(false) {}

// Parameterized constructor // Takes inputs to customize
Book::Book(const std::string &title, const std::string &author,
           const std::string &category, bool isBorrowed)
    : title(title), author(author), category(category), isBorrowed(isBorrowed) {
}

// Display book information
void Book::display() const {
  std::cout << "Title: " << title << ", Author: " << author
            << ", Category: " << category
            << ", Borrowed: " << (isBorrowed ? "Yes" : "No") << std::endl;
}
