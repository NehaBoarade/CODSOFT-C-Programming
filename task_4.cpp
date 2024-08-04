#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

void displayMenu();
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markCompleted(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);

int main() {
    vector<Task> tasks;
    char choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (toupper(choice)) {
            case 'A':
                addTask(tasks);
                break;
            case 'V':
                viewTasks(tasks);
                break;
            case 'C':
                markCompleted(tasks);
                break;
            case 'R':
                removeTask(tasks);
                break;
            case 'Q':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (toupper(choice) != 'Q');

    return 0;
}

void displayMenu() {
    cout << "\n===== TO-DO LIST MANAGER =====" << endl;
    cout << "A. Add Task" << endl;
    cout << "V. View Tasks" << endl;
    cout << "C. Mark Task as Completed" << endl;
    cout << "R. Remove Task" << endl;
    cout << "Q. Quit Program" << endl;
    cout << "Enter your choice: ";
}

void addTask(vector<Task>& tasks) {
    string description;
    cout << "Enter task description: ";
    getline(cin, description);
    tasks.emplace_back(description);
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task>& tasks) {
    cout << "\n===== TASK LIST =====" << endl;
    int count = 1;
    for (const auto& task : tasks) {
        cout << count << ". " << task.description;
        if (task.completed) {
            cout << " [COMPLETED]";
        } else {
            cout << " [PENDING]";
        }
        cout << endl;
        ++count;
    }
}

void markCompleted(vector<Task>& tasks) {
    int index;
    viewTasks(tasks);
    cout << "Enter the index of the task to mark as completed: ";
    cin >> index;
    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid index! No task marked as completed." << endl;
    }
}

void removeTask(vector<Task>& tasks) {
    int index;
    viewTasks(tasks);
    cout << "Enter the index of the task to remove: ";
    cin >> index;
    if (index >= 1 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid index! No task removed." << endl;
    }
}
