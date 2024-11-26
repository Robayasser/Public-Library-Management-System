#ifndef SEMINAR_H  // Start of header guard to prevent multiple inclusions
#define SEMINAR_H  // Define header guard symbol

#include <string>  // Include string library for string data type
#include <vector>  // Include vector library to use vector container

class Seminar {  // Define Seminar class
public:
  std::string title;  // Member variable to store the title of the seminar
  std::string description;  // Member variable to store the description of the seminar
  std::string speaker;  // Member variable to store the name of the speaker
  std::vector<std::string> feedback;  // Member variable to store a list of feedback

  Seminar();  // Default constructor declaration
  Seminar(const std::string &title, const std::string &description,  // Parameterized constructor declaration
          const std::string &speaker);  // Parameter to initialize speaker

  void addFeedback(const std::string &userFeedback);  // Method to add feedback to the seminar
  void display() const;  // Method to display seminar information, marked as const since it doesn't modify the object
};

#endif  // End of header guard to close the inclusion protection
