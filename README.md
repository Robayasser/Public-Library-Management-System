Roba Yasser
Nada Eldardery
Amina Abdelbaky
Kenzie Mostafa
Public Library Management System (PLMS)
Project Overview
The Public Library Management System (PLMS) is designed to manage library operations efficiently, catering to both administrators and regular users. The system provides functionalities such as book management, user registration, seminar handling, and feedback collection. Data is managed using file-based storage with STL for in-memory operations.
________________________________________
Features
Admin Functionalities
•	Manage books (add, view, and search by category).
•	Manage seminars (add and view seminar details).
•	Placeholder functionalities for overdue tracking and blacklisting users.
User Functionalities
•	Register and log in to the system.
•	Search for and borrow books.
•	View borrowing history.
File Storage
•	Books: Stored in books.txt by category, title, and author.
•	Users: Stored in users.txt with IDs, usernames, and passwords.
•	Seminars: Stored in seminars.txt with details like title, date, description, and speaker.
________________________________________
Setup Instructions
1. Prerequisites
•	A C++ compiler (e.g., g++, Clang).
•	A terminal or IDE for compiling and running the code.
2. How to Compile
Run the following command in the terminal:
bash
Copy code
g++ -o PLMS main.cpp user_updated.cpp admin_updated.cpp book.cpp
3. How to Run
Execute the compiled program:
bash
Copy code
./PLMS
________________________________________
Files and Descriptions
Source Code
•	main.cpp: Handles the main flow of the program, including menus for users and admins.
•	user_updated.cpp: Implements user registration, login, book borrowing, and borrowing history.
•	admin_updated.cpp: Implements seminar management and placeholders for overdue tracking and blacklisting.
•	book.cpp: Implements book-specific operations.
Data Files
•	books.txt: Contains details of all books in the library.
•	users.txt: Contains user registration data.
•	seminars.txt: Contains seminar details and feedback.
________________________________________
Usage
1.	Start the program and choose between Admin or User from the main menu.
2.	Admins can manage books and seminars through their dedicated menu.
3.	Users can register, log in, search for books, borrow books, and view borrowing history.
________________________________________
Future Enhancements
•	Implement overdue tracking and user blacklisting.
•	Integrate a Qt-based GUI for a better user experience.

