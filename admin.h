#ifndef ADMIN_H
#define ADMIN_H

#include "book.h"
#include "seminar.h"
#include "user.h"
#include <map> // Include the map header
#include <string>
#include <vector>

class Admin {
public:
  void manageBooks(std::vector<Book> &books);
  void manageSeminars(std::vector<Seminar> &seminars);
  void manageUsers(
      std::map<std::string, User> &userMap); // Placeholder for user management
};

#endif
