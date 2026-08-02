// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;


struct Student {
    string name;
    int id;
    vector<double> scores;
};

vector<Student> studentsList = {};


double computeAverage(const vector<double>& scores) {
    if (scores.empty()) return 0.0;
 
    double sum = 0;
    for (double s : scores) {
        sum += s;
    }
    return sum / scores.size();
}

string formatScore(double score) {
    int scaled = (int)(score * 10 + 0.5); // round to nearest tenth
    int wholePart = scaled / 10;
    int decimalPart = scaled % 10;
    return to_string(wholePart) + "." + to_string(decimalPart);
}


void addStudent() {
    cin.ignore();

    string studentName;
    cout << "Student name: ";
    getline(cin, studentName);

    int studentID;
    cout << "Student ID: ";
    cin >> studentID;

    int scoreCount;
    cout << "How many scores? ";
    cin >> scoreCount;

    if (scoreCount <= 0) {
        cout << "Enter at least one score!" << endl;
        return;
    }

    vector<double> studentScores = {};

    for (int i = 1; i <= scoreCount; i++) {
        double currentScore;
        cout << "Enter score " << i << ": ";
        cin >> currentScore;

        while (currentScore < 0 || currentScore > 100) {
            cout << "Score should fall between 0 and 100" << endl;
            cin >> currentScore;
        }
        
        studentScores.push_back(currentScore);
    }

    Student newStudent;
    newStudent.name = studentName;
    newStudent.id = studentID;
    newStudent.scores = studentScores;

    studentsList.push_back(newStudent);

    cout << "Student \"" << studentName << "\" added successfully.\n" << endl;
}


void displayStudents() {
    if (studentsList.size() == 0) {
        cout << "No students added yet!\n" << endl;
        return;
    }

    cout << left << setw(20) << "Name" << setw(12) << "ID" << setw(24) << "Scores" << "Average " << endl;

    for (int i = 0; i < studentsList.size(); i++) {
        cout << left << setw(20) << studentsList[i].name << setw(12) << studentsList[i].id;

        string scoresStr = "";
        for (int j = 0; j < studentsList[i].scores.size(); j++) {
            scoresStr += formatScore(studentsList[i].scores[j]);
            if (j != studentsList[i].scores.size() - 1) {
                scoresStr += ", ";
            }
        }
        cout << setw(24) << scoresStr;

        double avg = computeAverage(studentsList[i].scores);
        cout << fixed << setprecision(2) << avg << endl;
    }

    cout << endl;
}


void calculateAverageForId() {
    int searchID;
    cout << "Enter student ID: ";
    cin >> searchID;
 
    bool found = false;
 
    for (int i = 0; i < studentsList.size(); i++) {
        if (studentsList[i].id == searchID) {
            double avg = computeAverage(studentsList[i].scores);
            cout << fixed << setprecision(2);
            cout << studentsList[i].name << "'s average score: " << avg << "\n" << endl;
            found = true;
            break;
        }
    }
 
    if (found == false) {
        cout << "Student ID not found!\n" << endl;
    }
}


int main() {
    while (true) {
        cout << "================================" << endl;
        cout << "   STUDENT RECORD SYSTEM MENU   " << endl;
        cout << "================================" << endl;

        cout << "1. Add student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Calculate average score" << endl;
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
            cout << "Invalid menu option!\n" << endl;
        }
        else {
            if (userChoice == 1) {
                addStudent();
            }
            else if (userChoice == 2) {
                displayStudents();
            }
            else if (userChoice == 3) {
                calculateAverageForId();
            }
            else if (userChoice == 4) {
                cout << "Goodbye!" << endl;
                break;
            }
        }
    }
    return 0;
}