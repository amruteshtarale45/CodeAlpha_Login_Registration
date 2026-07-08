#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool registerUser(const string& username, const string& password) {
    // Check if username already exists
    ifstream infile("users.txt");
    string u, p;
    while (infile >> u >> p) {
        if (u == username) {
            cout << "Error: Username already exists!\n";
            return false;
        }
    }
    infile.close();

    // Save new user
    ofstream outfile("users.txt", ios::app); // append mode
    outfile << username << " " << password << endl;
    outfile.close();

    cout << "Registration successful!\n";
    return true;
}

bool loginUser(const string& username, const string& password) {
    ifstream infile("users.txt");
    string u, p;
    while (infile >> u >> p) {
        if (u == username && p == password) {
            cout << "Login successful!\n";
            return true;
        }
    }
    infile.close();

    cout << "Invalid credentials!\n";
    return false;
}

int main() {
    int choice;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Register\n2. Login\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            string username, password;
            cout << "Enter new username: ";
            cin >> username;
            cout << "Enter new password: ";
            cin >> password;
            registerUser(username, password);
        }
        else if (choice == 2) {
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            loginUser(username, password);
        }
        else if (choice == 3) {
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
