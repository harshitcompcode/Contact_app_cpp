#include <iostream>
#include <map>
#include <string>

using namespace std;

// Function to display menu options
void displayMenu() {
    cout << "Address Book Application\n";
    cout << "1. Add Contact\n";
    cout << "2. Search Contact\n";
    cout << "3. Display All Contacts\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

// Function to add a contact to the address book
void addContact(map<string, string>& addressBook) {
    string name, phoneNumber;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter phone number: ";
    cin >> phoneNumber;
    addressBook.insert(make_pair(name, phoneNumber));
    cout << "Contact added successfully.\n";
}

// Function to search for a contact in the address book
void searchContact(const map<string, string>& addressBook) {
    string name;
    cout << "Enter name to search: ";
    cin >> name;
    auto it = addressBook.find(name);
    if (it != addressBook.end()) {
        cout << "Phone number: " << it->second << endl;
    } else {
        cout << "Contact not found.\n";
    }
}

// Function to display all contacts in the address book
void displayContacts(const map<string, string>& addressBook) {
    cout << "Contacts in Address Book:\n";
    for (const auto& entry : addressBook) {
        cout << "Name: " << entry.first << ", Phone: " << entry.second << endl;
    }
}

int main() {
    map<string, string> addressBook;

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addContact(addressBook);
                break;
            case 2:
                searchContact(addressBook);
                break;
            case 3:
                displayContacts(addressBook);
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
