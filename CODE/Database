#include <iostream>
#include <fstream>
#include "Database.h"

using namespace std;

// REGISTER USER
bool registerUser()
{
    string username, password;

    cout << "========== REGISTER ==========" << endl;

        cout << "Enter new username: ";
    cin >> username;

    cout << "Enter new password: ";
    cin >> password;

    ifstream readFile("users.txt");

    string fileUser, filePass;

    while (readFile >> fileUser >> filePass)
    {
        if (fileUser == username)
        {
            cout << "Username already exists.";
                readFile.close();
            return false;
        }
    }

    readFile.close();

    ofstream writeFile("users.txt", ios::app);

    writeFile << username << " " << password << endl;

    writeFile.close();

    cout << "Registration successful!";

        return true;
}

// LOGIN USER
bool login(string& currentUser)
{
    string username, password;

    int attempts = 3;

    while (attempts > 0)
    {
        cout << "========== LOGIN ==========" << endl;

            cout << "Username: ";
        cin >> username;

        cout << "Password: ";
        cin >> password;

        ifstream readFile("users.txt");

        string fileUser, filePass;
        bool found = false;

        while (readFile >> fileUser >> filePass)
        {
            if (username == fileUser &&
                password == filePass)
            {
                found = true;
                currentUser = username;
                break;
            }
        }

        readFile.close();

        if (found)
        {
            cout << "Login Successful!" << endl;
                return true;
        }

        else
        {
            attempts--;

            cout << "Invalid username or password." << endl;
                cout << "Attempts left: " << attempts << endl;
        }
    }

    cout << "Too many failed attempts." << endl;

        return false;
}
