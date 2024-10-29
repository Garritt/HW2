// phonebook.h
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>

class phonebook {
public:
  // Constructor and Destructor
  phonebook();       // Default constructor
  ~phonebook();      // Destructor to clean up dynamically allocated nodes
  
  // Methods
  void push_front(const std::string& first_name, const std::string& last_name, const std::string& phone_number);
  void push_back(const std::string& first_name, const std::string& last_name, const std::string& phone_number);
  bool read_from_file(const std::string& filename);
  bool write_to_file(const std::string& filename) const;
  void insert_sorted(const std::string& first_name, const std::string& last_name, const std::string& phone_number);
  std::string lookup(const std::string& first_name, const std::string& last_name) const;
  std::string reverse_lookup(const std::string& phone_number) const;
  void print() const;
  bool delete_user(const std::string& first_name, const std::string& last_name);
  
private:
  // Helper method to clean up nodes
  void clear();
  struct entry {
    std::string first_name;
    std::string last_name;
    std::string phone_number;
    entry* next;
    
    // Constructor for easy entry creation
    entry(const std::string& fn, const std::string& ln, const std::string& \
	  pn, entry* nxt = nullptr)
      : first_name(fn), last_name(ln), phone_number(pn), next(nxt) {}         };
  
  entry* head;  // Pointer to the head of the linked list
  entry* tail;  // Pointer to the tail of the linked list
};

#endif // PHONEBOOK_H
