// phonebook.h
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>

class phonebook {
public:
  // Constructor and Destructor
  phonebook();
  ~phonebook();
  

/**
 * push_front function
 *
 * @param const std::string& first_name 
 * @param const std::string& last_name 
 * @param const std::string& phone_number 
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void push_front(const std::string& first_name, const std::string& last_name, const std::string& phone_number);


/**
 * push_back function
 *
 * @param const std::string& first_name 
 * @param const std::string& last_name 
 * @param const std::string& phone_number 
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void push_back(const std::string& first_name, const std::string& last_name, const std::string& phone_number);


/**
 * takes a string file name as a parameter and reads the phonebook from the file with that name
 *
 * @param const std::string& filename 
 * @pre 
 * @return bool 
 * @post 
 * 
 */
  bool read_from_file(const std::string& filename);


/**
 * takes a string with a file name as a parameter and writes the phonebook to the file with that name
 *
 * @param const std::string& filename 
 * @pre 
 * @return bool 
 * @post 
 * 
 */
  bool write_to_file(const std::string& filename) const;


/**
 * We have implemented insertion at the head and tail in class, however linked lists allow for easy reorganization anywhere in the list. Much like the remove method, you should search for an insertion point in the list by traversing the list, insert a new node in the middle of the list in alphabetical order, sorted by the user's last name.
 *
 * @param const std::string& first_name 
 * @param const std::string& last_name 
 * @param const std::string& phone_number 
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void insert_sorted(const std::string& first_name, const std::string& last_name, const std::string& phone_number);


/**
 * takes a name as a parameter and returns the number associated with it
 *
 * @param const std::string& first_name 
 * @param const std::string& last_name 
 * @pre 
 * @return std::string 
 * @post 
 * 
 */
  std::string lookup(const std::string& first_name, const std::string& last_name) const;


/**
 * takes a phone number as a parameter and returns the name of the individual associated with it.
 *
 * @param const std::string& phone_number 
 * @pre 
 * @return std::string 
 * @post 
 * 
 */
  std::string reverse_lookup(const std::string& phone_number) const;


/**
 * Prints the list
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void print() const;


/**
 * deletes a user's information from the list
 *
 * @param const std::string& first_name 
 * @param const std::string& last_name 
 * @pre 
 * @return bool 
 * @post 
 * 
 */
  bool delete_user(const std::string& first_name, const std::string& last_name);
  
private:
  // Helper method to clean up nodes
  void clear();
  struct entry {
    std::string first_name;
    std::string last_name;
    std::string phone_number;
    entry* next;
    

/**
 * Loop to read through the files. I think. I only know that this works, I spent the most time on this particular function by far. Do not ask me to reconstruct it.
 *
 * @param const std::string& fn 
 * @param const std::string& ln 
 * @param const std::string&pn 
 * @param entry* nxt = nullptr 
 * @pre 
 * @post 
 * 
 */
    entry(const std::string& fn, const std::string& ln, const std::string&pn, entry* nxt = nullptr)
      : first_name(fn), last_name(ln), phone_number(pn), next(nxt) {}         };
  
  entry* head;
  entry* tail;
};

#endif
