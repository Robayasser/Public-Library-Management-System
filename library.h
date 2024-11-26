#ifndef LIBRARY_H
#define LIBRARY_H

#include "admin.h"
#include "user.h"
#include <map>
#include <vector>

class Library {
public:
  void loadData();
  void saveData();
  void adminLogin();
  void userLogin();

private:
  Admin admin;
  std::map<std::string, User> userMap;
  std::vector<Book> books;
  std::vector<Seminar> seminars;
};

#endif
