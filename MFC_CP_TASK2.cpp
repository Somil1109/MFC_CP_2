#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    int id;
    bool available;
};

struct Member {
    string name;
    int id;
    int booksBorrowed;
};

vector<Book> books;
vector<Member> members;

void addBook() {
    Book book;
    cout << "Enter book title: ";
    getline(cin >> ws, book.title);
    cout << "Enter book author: ";
    getline(cin >> ws, book.author);
    book.id = books.size() + 1;
    book.available = true;
    books.push_back(book);
    cout << "Book added successfully!" << endl;
}

void displayBooks() {
    cout << "List of books:" << endl;
    for (const auto& book : books) {
        cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author;
        if (book.available) {
            cout << " (Available)" << endl;
        } else {
            cout << " (Not Available)" << endl;
        }
    }
}

int main() {
    int choice;
    do {
        cout << "Library Management System Menu:" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                cout << "Exiting... Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
