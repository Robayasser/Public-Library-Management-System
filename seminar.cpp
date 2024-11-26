#include "seminar.h"
#include <iostream>

Seminar::Seminar() : title(""), description(""), speaker("") {}

Seminar::Seminar(const std::string& title, const std::string& description, const std::string& speaker)
    : title(title), description(description), speaker(speaker) {}


// Add feedback
void Seminar::addFeedback(const std::string& userFeedback) {
    feedback.push_back(userFeedback);
}

// Display seminar information
void Seminar::display() const {
    std::cout << "Title: " << title
              << ", Description: " << description
              << ", Speaker: " << speaker << std::endl;

    std::cout << "Feedback:\n";
    for (const auto& fb : feedback) {
        std::cout << "- " << fb << std::endl;
    }
}
