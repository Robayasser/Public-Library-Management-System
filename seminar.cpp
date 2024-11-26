#include "seminar.h"  // Include seminar header file
#include <iostream>  // Include iostream for output

Seminar::Seminar() : title(""), description(""), speaker("") {}  // Default constructor initializing empty strings

Seminar::Seminar(const std::string& title, const std::string& description, const std::string& speaker)  // Constructor with parameters
    : title(title), description(description), speaker(speaker) {}  // Initialize member variables with provided values

// Add feedback
void Seminar::addFeedback(const std::string& userFeedback) {  // Method to add feedback
    feedback.push_back(userFeedback);  // Push feedback into the feedback vector
}

// Display seminar information
void Seminar::display() const {  // Method to display seminar details
    std::cout << "Title: " << title  // Output seminar title
              << ", Description: " << description  // Output seminar description
              << ", Speaker: " << speaker << std::endl;  // Output speaker name

    std::cout << "Feedback:\n";  // Output feedback label
    for (const auto& fb : feedback) {  // Loop through all feedback
        std::cout << "- " << fb << std::endl;  // Output each feedback
    }
}
```
