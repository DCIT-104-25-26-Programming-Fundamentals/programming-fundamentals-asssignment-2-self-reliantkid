// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


void addition(int a, int b) {
    int result = a + b;
    cout << "Result: " << a << " + " << b << " = " << result << endl << endl;
}


void subtraction (int a, int b) {
    int result =  a - b;
    cout << "Result: " << a << " - " << b << " = " << result << endl << endl;
}


void multiplication(int a, int b) {
    int result = a * b;
    cout << "Result: " << a << " x " << b << " = " << result << endl << endl;
}


void division(int a, int b) {
    if (b == 0) {
        cout << "Error: Cannot divide by zero.\n" << endl;
    }
    else {
        double result = static_cast<double>(a) / b;
        cout << "Result: " << a << " / " << b << " = " << fixed << setprecision(2) << result << endl << endl;
    }
}


void mod(int a, int b) {
    if (b == 0) {
        cout << "Error: Cannot perform modulus by zero.\n" << endl;
    }
    else {
        int result = a % b;
        cout << "Result: " << a << " % " << b << " = " << result << endl << endl;
    }
}


void expo(int a, int b) {
    int result = static_cast<int>(round(pow(a, b)));
    cout << "Result: " << a << " ^ " << b << " = " << result << endl << endl;
}


int main() {
    while (true) {
        cout << "============================" << endl;
        cout << "     SIMPLE CALCULATOR      " << endl;
        cout << "============================" << endl;

        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exponentiation" << endl;
        cout << "7. Quit" << endl;

        int userChoice;
        cout << "\nSelect an operation (1-7): ";
        cin >> userChoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input!" << endl;
            continue;
        }

        if (userChoice < 0 || userChoice > 7) {
            cout << "Invalid menu option!\n" << endl;
        }
        else {
            if (userChoice == 7) {
                cout << "Goodbye!" << endl;
                return 0;
            }
            else {
                int num1;
                cout << "Enter first number: ";
                cin >> num1;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input!" << endl;
                    continue;
                }

                int num2;
                cout << "Enter second number: ";
                cin >> num2;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input!" << endl;
                    continue;
                }

                if (userChoice == 1) {
                    addition(num1, num2);
                }
                else if (userChoice == 2) {
                    subtraction(num1, num2);
                }
                else if (userChoice == 3) {
                    multiplication(num1, num2);
                }
                else if (userChoice == 4) {
                    division(num1, num2);
                }
                else if (userChoice == 5) {
                    mod(num1, num2);
                }
                else if (userChoice == 6) {
                    expo(num1, num2);
                }
            }
        }
    }
}