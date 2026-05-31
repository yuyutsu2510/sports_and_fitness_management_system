#include <iostream>
#include <string>
#include <map>
using namespace std;

// Password hashing (Caesar cipher)
string hashPassword(string password) {
    string hashed = "";
    for (char c : password) {
        hashed += char(((c - 32 + 3) % 95) + 32); // Keeps printable ASCII
    }
    return hashed;
}

// User structure
struct User {
    string username;
    string hashedPassword;
    string role;
};

// User database
map<string, User> users;

// Register a new user
void registerUser() {
    string username, password, role;

    cout << "\n--- User Registration ---\n";
    cout << "Enter username: ";
    cin >> username;

    if (users.find(username) != users.end()) {
        cout << "Username already exists. Try a different one.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    cout << "Enter role (admin/user): ";
    cin >> role;

    User newUser;
    newUser.username = username;
    newUser.hashedPassword = hashPassword(password);
    newUser.role = role;

    users[username] = newUser;

    cout << "User registered successfully!\n";
}

// Login function
void loginUser() {
    string username, password;

    cout << "\n--- User Login ---\n";
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    if (users.find(username) == users.end()) {
        cout << "User not found!\n";
        return;
    }

    string hashedInput = hashPassword(password);

    if (hashedInput == users[username].hashedPassword) {
        cout << "Login successful! Welcome, " << username
             << " (" << users[username].role << ")\n";
    } else {
        cout << "Incorrect password!\n";
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n--- Menu ---\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}

