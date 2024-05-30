
/* //========= Create address Phone Book===============//

The main parts of this program of this address book app:
->We defined a Contact struct to store the name, phone, and email of each contact.
->The addContact function allows users to add a new contact to the contact book.
->The displayContacts function lists all contacts in the contact book.
->The searchContact function looks for a contact by name and displays it if found.
->The deleteContact removes a contact from the list based on the name.
->The main function provides a simple menu for the user to choose between adding a new contact, displaying contacts, searching for a contact, deleting a contact, or exiting the program.
->We use a vector of Contact structs to store the list of contacts

 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Phone_book   // In Struct contains all member as public
{
  std::string name;
  std::string phone;
  std::string email;
};

void addContact(std::vector<Phone_book> &para)
{
  Phone_book newContact;
  std::cout << "Enter name: ";
  std::cin >> newContact.name;
  std::cout << "Enter phone: ";
  std::cin >> newContact.phone;
  std::cout << "Enter email: ";
  std::cin >> newContact.email;
  para.push_back(newContact);
  std::cout << "Contact added." << std::endl;
}

void displayContacts(const std::vector<Phone_book> &para)
{
  for (const auto & e : para)
  {
      std::cout << "Name: " << e.name << ", Phone: "
                << e.phone << ", Email: " << e.email << std::endl;
  }
}

void searchContact(const std::vector<Phone_book> &para)
{
  std::string searchTerm;
  std::cout << "Enter name to search: ";
  std::cin >> searchTerm;

  bool found = false;                // create boolfound as a Flag
  for (const auto & e : para)
  {
      if ( e.name == searchTerm)
      {
          std::cout << "Name: " << e.name << ", Phone: "
                    << e.phone << ", Email: " << e.email << std::endl;
          found = true;                   // if found Flag became true then only enable next "if" statement.
          break;
      }
  }

  if (!found)
  {
      std::cout << "Contact not found." << std::endl;
  }
}

void deleteContact(std::vector<Phone_book> &para)
{
    std::string nameToDelete;
    std::cout << "Enter name of contact to delete: ";
    std::cin >> nameToDelete;

    auto it = std::remove_if(para.begin(), para.end(), 
                [&](const Phone_book & e) { return e.name == nameToDelete; }); // using lambda function, //auto it indicates iteration at removing point position

        // using lambda function, syntex: auto greet = []() {// lambda function body };
        // [] is called the lambda introducer which denotes the start of the lambda expression
        // Here,[&] indicate reference of starting lambda expression
        // e.g.: foo.erase(std::remove_if(foo.begin(), foo.end(), [](auto n) { return n % 2 == 0;}), foo.end());-->Remove all even number.
        //  https://stackoverflow.com/questions/33571609/having-trouble-with-vector-erase-and-remove-if

    if (it != para.end())
    {
        para.erase(it, para.end());       //  Here erase() works along with reemove_if()
        std::cout << "Contact deleted." << std::endl;
    }
    else
    {
        std::cout << "Contact not found." << std::endl;
    }
}

int main()
{
  std::vector<Phone_book> cont_obj;
  int choice;

  do
  {
      std::cout << "\n1. Add Contact" << std::endl;
      std::cout << "2. Display Contacts" << std::endl;
      std::cout << "3. Search Contact" << std::endl;
      std::cout << "4. Delete Contact" << std::endl;
      std::cout << "5. Exit" << std::endl;
      std::cout << "Enter choice: ";
      std::cin >> choice;

      switch (choice)
      {
      case 1:
          addContact(cont_obj);
          break;
      case 2:
          displayContacts(cont_obj);
          break;
      case 3:
          searchContact(cont_obj);
          break;
      case 4:
          deleteContact(cont_obj);
          break;
      case 5:
          break;
      default:
          std::cout << "Invalid choice." << std::endl;
      }
  } while (choice != 5);

  return 0;
}