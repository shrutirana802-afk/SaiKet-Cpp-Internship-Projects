#include <iostream>
#include <vector>
using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

int main() {
    vector<Contact> contacts;
    int choice;

    do {
        cout << "\n===== ADDRESS BOOK MENU =====\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                Contact c;
                cout << "Enter Name: ";
                cin >> c.name;
                cout << "Enter Phone: ";
                cin >> c.phone;
                cout << "Enter Email: ";
                cin >> c.email;

                contacts.push_back(c);
                cout << "Contact Added Successfully!\n";
                break;
            }

            case 2: {
                cout << "\n--- Contact List ---\n";
                if(contacts.empty()) {
                    cout << "No contacts found.\n";
                } else {
                    for(int i = 0; i < contacts.size(); i++) {
                        cout << "\nName: " << contacts[i].name;
                        cout << "\nPhone: " << contacts[i].phone;
                        cout << "\nEmail: " << contacts[i].email << "\n";
                    }
                }
                break;
            }

            case 3: {
                string searchName;
                cout << "Enter Name to Search: ";
                cin >> searchName;

                bool found = false;

                for(int i = 0; i < contacts.size(); i++) {
                    if(contacts[i].name == searchName) {
                        cout << "\nContact Found!";
                        cout << "\nPhone: " << contacts[i].phone;
                        cout << "\nEmail: " << contacts[i].email << "\n";
                        found = true;
                    }
                }

                if(!found)
                    cout << "Contact Not Found!\n";

                break;
            }

            case 4:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 4);

    return 0;
}