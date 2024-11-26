#ifndef ADMIN_H //to include this file once
#define ADMIN_H 

#include "book.h"
#include "seminar.h"
#include "user.h"
#include <map> // Include the map header
#include <string> // for text
#include <vector> // manage lists 

class Admin {
public:
  void manageBooks(std::vector<Book> &books); //admin handle books
  void manageSeminars(std::vector<Seminar> &seminars); // handles seminar 
  void manageUsers(
      std::map<std::string, User> &userMap); // handles user 
};

#endif
