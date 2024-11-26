#ifndef SEMINAR_H
#define SEMINAR_H

#include <string>
#include <vector>

class Seminar {
public:
  std::string title;
  std::string description;
  std::string speaker;
  std::vector<std::string> feedback;

  Seminar();
  Seminar(const std::string &title, const std::string &description,
          const std::string &speaker);

  void addFeedback(const std::string &userFeedback);
  void display() const;
};

#endif
