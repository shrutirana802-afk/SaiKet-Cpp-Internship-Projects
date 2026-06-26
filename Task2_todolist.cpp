#include <iostream>
#include <vector>
using namespace std;

struct Task {
    string description;
    bool completed;
};

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n===== TO-DO LIST MENU =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Complete\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1: {
                Task t;
                cout << "Enter task description: ";
                getline(cin, t.description);
                t.completed = false;
                tasks.push_back(t);
                cout << "Task Added Successfully!\n";
                break;
            }

            case 2: {
                cout << "\n--- Task List ---\n";
                for(int i = 0; i < tasks.size(); i++) {
                    cout << i + 1 << ". "
                         << tasks[i].description
                         << " [" << (tasks[i].completed ? "Done" : "Pending") << "]\n";
                }
                if(tasks.empty())
                    cout << "No tasks available.\n";
                break;
            }

            case 3: {
                int num;
                cout << "Enter task number to mark complete: ";
                cin >> num;

                if(num > 0 && num <= tasks.size()) {
                    tasks[num - 1].completed = true;
                    cout << "Task Marked Complete!\n";
                } else {
                    cout << "Invalid Task Number!\n";
                }
                break;
            }

            case 4: {
                int num;
                cout << "Enter task number to delete: ";
                cin >> num;

                if(num > 0 && num <= tasks.size()) {
                    tasks.erase(tasks.begin() + num - 1);
                    cout << "Task Deleted!\n";
                } else {
                    cout << "Invalid Task Number!\n";
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