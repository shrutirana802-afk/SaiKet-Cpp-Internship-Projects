#include <iostream>
#include <vector>
using namespace std;

struct Item {
    string name;
    int quantity;
    float price;
};

int main() {
    vector<Item> inventory;
    int choice;

    do {
        cout << "\n===== INVENTORY MENU =====\n";
        cout << "1. Add Item\n";
        cout << "2. View Inventory\n";
        cout << "3. Update Item\n";
        cout << "4. Delete Item\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                Item item;
                cout << "Enter Item Name: ";
                cin >> item.name;
                cout << "Enter Quantity: ";
                cin >> item.quantity;
                cout << "Enter Price: ";
                cin >> item.price;

                inventory.push_back(item);
                cout << "Item Added Successfully!\n";
                break;
            }

            case 2: {
                cout << "\n--- Inventory List ---\n";
                if(inventory.empty()) {
                    cout << "No items available.\n";
                } else {
                    for(int i = 0; i < inventory.size(); i++) {
                        cout << i + 1 << ". "
                             << inventory[i].name
                             << " | Qty: " << inventory[i].quantity
                             << " | Price: ₹" << inventory[i].price
                             << endl;
                    }
                }
                break;
            }

            case 3: {
                int num;
                cout << "Enter Item Number to Update: ";
                cin >> num;

                if(num > 0 && num <= inventory.size()) {
                    cout << "New Quantity: ";
                    cin >> inventory[num - 1].quantity;
                    cout << "New Price: ";
                    cin >> inventory[num - 1].price;
                    cout << "Item Updated!\n";
                } else {
                    cout << "Invalid Item Number!\n";
                }
                break;
            }

            case 4: {
                int num;
                cout << "Enter Item Number to Delete: ";
                cin >> num;

                if(num > 0 && num <= inventory.size()) {
                    inventory.erase(inventory.begin() + num - 1);
                    cout << "Item Deleted!\n";
                } else {
                    cout << "Invalid Item Number!\n";
                }
                break;
            }

            case 5:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}