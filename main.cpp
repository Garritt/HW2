// main.cpp
#include "phonebook.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  phonebook pb;
    int choice = 0;
    string first_name, last_name, phone_number, filename;
    
    cout << "Welcome to the UTM Phonebook! You may select one of the following options:\n";
    
    while (choice != 8) {
      cout << "\n1. Read a phonebook from a file\n"
             << "2. Write the phonebook to a file\n"
             << "3. Print the phonebook\n"
             << "4. Search for a user's phone number\n"
             << "5. Reverse lookup by phone number\n"
             << "6. Add a user\n"
             << "7. Delete a user\n"
             << "8. Exit this program\n"
             << "Please enter your choice now: ";
        cin >> choice;
	
        if (choice == 1) {
	  cout << "Enter the filename to read from: ";
            cin >> filename;
            if (pb.read_from_file(filename)) {
	      cout << "Phonebook successfully read from " << filename << ".\n";
            } else {
	      cout << "Failed to read from " << filename << ".\n";
            }
        }

	else if (choice == 2) {
	  cout << "Enter the filename to write to: ";
            cin >> filename;
            if (pb.write_to_file(filename)) {
	      cout << "Phonebook successfully written to " << filename << ".\n";
            } else {
	      cout << "Failed to write to " << filename << ".\n";
            }
        }

	else if (choice == 3) {
	  pb.print();
        }

	else if (choice == 4) {
	  cout << "Enter the first name: ";
            cin >> first_name;
            cout << "Enter the last name: ";
            cin >> last_name;
            string number = pb.lookup(first_name, last_name);
            cout << "Phone Number: " << number << "\n";
        }

	else if (choice == 5) {
	  cout << "Enter the phone number for reverse lookup: ";
            cin >> phone_number;
            string name = pb.reverse_lookup(phone_number);
            cout << "Name: " << name << "\n";
        }

	else if (choice == 6) {
	  cout << "Enter the first name: ";
            cin >> first_name;
            cout << "Enter the last name: ";
            cin >> last_name;
            cout << "Enter the phone number: ";
            cin >> phone_number;
            pb.insert_sorted(first_name, last_name, phone_number);
            cout << "User added successfully.\n";
        }

	else if (choice == 7) {
	  cout << "Enter the first name of the user to delete: ";
            cin >> first_name;
            cout << "Enter the last name of the user to delete: ";
            cin >> last_name;
            if (pb.delete_user(first_name, last_name)) {
	      cout << "User deleted successfully.\n";
            } else {
	      cout << "User not found.\n";
            }
        }

	else if (choice == 8) {
	  cout << "Exiting program. Goodbye!\n";
        }
        else {
	  cout << "Invalid option. Please select a valid choice.\n";
        }
    }
    
    return 0;
}
