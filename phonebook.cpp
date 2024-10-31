/**
 * @file phonebook.cpp
 * @author Garritt Baker
 * @date 2024-10-30
 * @brief cpp file for the Phonebook header file
 * 
 * 
 */


#include "phonebook.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Constructor
phonebook::phonebook() : head(nullptr), tail(nullptr) {}

// Destructor
phonebook::~phonebook() {
  clear();
}

// Helper method to clean up all nodes
void phonebook::clear() {
  entry* current = head;
    while (current) {
      entry* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
}

// Adds a new entry at the front of the phonebook
void phonebook::push_front(const string& first_name, const string& last_name, const string& phone_number) {
  entry* new_entry = new entry(first_name, last_name, phone_number, head);
    head = new_entry;
    if (!tail) {
      tail = head;
    }
}

// Adds a new entry at the end of the phonebook
void phonebook::push_back(const string& first_name, const string& last_name, const string& phone_number) {
  entry* new_entry = new entry(first_name, last_name, phone_number);
    if (!head) {
      head = tail = new_entry;
    } else {
      tail->next = new_entry;
        tail = new_entry;
    }
}

// Reads phonebook data from a file and inserts entries in sorted order
bool phonebook::read_from_file(const string& filename) {
  ifstream file(filename);
    if (!file) return false;
    
    clear();  // Clear current entries
    string first_name, last_name, phone_number;
    
    // Read each entry (first name, last name, and phone number) line-by-line
    while (file >> first_name >> last_name && getline(file >> ws, phone_number)) {
      insert_sorted(first_name, last_name, phone_number);
    }
    return true;
}

// Writes the phonebook data to a file
bool phonebook::write_to_file(const string& filename) const {
  ofstream file(filename);
    if (!file) return false;
    
    entry* current = head;
    while (current) {
      file << current->first_name << " " << current->last_name << "\n" << current->phone_number << "\n";
        current = current->next;
    }
    return true;
}

// Inserts a new entry in sorted order by last name
void phonebook::insert_sorted(const string& first_name, const string& last_name, const string& phone_number) {
  entry* new_entry = new entry(first_name, last_name, phone_number);
    
    if (!head || last_name < head->last_name) {
      new_entry->next = head;
        head = new_entry;
        if (!tail) tail = head;
    } else {
      entry* current = head;
        while (current->next && current->next->last_name < last_name) {
	  current = current->next;
        }
        new_entry->next = current->next;
        current->next = new_entry;
        if (!new_entry->next) tail = new_entry;
    }
}

// Looks up a user's phone number by first and last name
string phonebook::lookup(const string& first_name, const string& last_name) const {
  entry* current = head;
    while (current) {
      if (current->first_name == first_name && current->last_name == last_name) {
	  return current->phone_number;
        }
        current = current->next;
    }
    return "Not found";
}

// Reverse looks up a user's name by their phone number
string phonebook::reverse_lookup(const string& phone_number) const {
  entry* current = head;
    while (current) {
      if (current->phone_number == phone_number) {
	  return current->first_name + " " + current->last_name;
        }
        current = current->next;
    }
    return "Not found";
}

// Prints all entries in the phonebook
void phonebook::print() const {
  entry* current = head;
    while (current) {
      cout << "Name: " << current->first_name << " " << current->last_name << "\n";
        cout << "Phone Number: " << current->phone_number << "\n";
        current = current->next;
    }
}

// Deletes a user by first and last name
bool phonebook::delete_user(const string& first_name, const string& last_name) {
  if (!head) return false;
    
    if (head->first_name == first_name && head->last_name == last_name) {
      entry* to_delete = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete to_delete;
        return true;
    }
    
    entry* current = head;
    while (current->next && (current->next->first_name != first_name || current->next->last_name != last_name)) {
      current = current->next;
    }
    
    if (current->next) {
      entry* to_delete = current->next;
        current->next = to_delete->next;
        if (!current->next) tail = current;
        delete to_delete;
        return true;
    }
    return false;
}
