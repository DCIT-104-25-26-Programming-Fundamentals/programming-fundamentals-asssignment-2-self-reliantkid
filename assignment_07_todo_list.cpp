// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<string> tasksList = {};

void addTask() {
    string task;
    cout << "Enter task: ";
    cin.ignore();
    getline(cin, task);

    if (task == "") {
        cout << "Task can't be empty!\n" << endl;
    }
    else {
        tasksList.push_back(task);
        cout << "Task added: " << '"' << task << '"' << "\n" << endl;
    }
}


void viewTasks() {
    cout << "\nYour Tasks: " << endl;
    if (tasksList.size() == 0) {
        cout << "No tasks added yet!\n" << endl;
    }
    else {
        for (int i = 1; i <= tasksList.size(); i++) {
            cout << i << ". " << tasksList[i-1] << endl;
        }
        cout << endl;
    }
}


void deleteTask() {
    viewTasks();
    int taskNum;
    cout << "Enter task number to delete: ";
    cin >> taskNum;

    if (tasksList.size() == 0) {
        cout << "No tasks to delete!\n" << endl;
    } 
    else if (taskNum < 1 || taskNum > tasksList.size()) {
        cout << "Task number not in list!\n" << endl;
    }
    else {
        string task = tasksList[taskNum - 1];
        tasksList.erase(tasksList.begin() + taskNum -1);
        cout << "Task " << '"' << task << '"' << " has been removed.\n" << endl;
    } 
}


int main() {
    while (true) {
        cout << "============================" << endl;
        cout << "     TO-DO LIST MENU        " << endl;
        cout << "============================" << endl;
        cout << "1. Add task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Delete task" << endl;
        cout << "4. Quit" << endl;

        
        int userChoice;
        cout << "\nEnter your choice (1-4): ";
        cin >> userChoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input!" << endl;
            continue;
        }

        if (userChoice < 0 || userChoice > 4) {
            cout << "Invalid menu option!" << endl;
        }
        else {
            if (userChoice == 1) {
                addTask();
            }
            else if (userChoice == 2) {
                viewTasks();
            }
            else if (userChoice == 3) {
                deleteTask();
            }
            else {
                cout << "Goodbye!" << endl;
                return 0;
            }
        }
    }
    return 0;
}