// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;


int sum(int arr[], int s) {
    int total = 0;
    
    for (int i = 0; i < s; i++) {
        total += arr[i];
    }

    return total;
}


double average(int arr[], int s) {
    int total = sum(arr, s);
    double avg = static_cast<double>(total) / s;
    return avg;
}


int maximum(int arr[], int s) {
    int max_value = arr[0];

    for (int i = 1; i < s; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    return max_value;
}


int minimum(int arr[], int s) {
    int min_value = arr[0];

    for (int i = 1; i < s; i++) {
        if (arr[i] < min_value) {
            min_value = arr[i];
        }
    }

    return min_value;
}


int main() {
    int numCount;
    cout << "How many numbers? ";
    cin >> numCount;

    if (numCount <= 0) {
        cout << "N must be a positive integer!";
    }
    
    else {
        int numArray[numCount];
        int i = 1;

        while (i <= numCount) {
            int num;
            cout << "Enter number " << i << ": ";
            cin >> num;

            numArray[i-1] = num;
            i++;
        }

        int sumResult = sum(numArray, numCount);
        double avgResult = average(numArray, numCount);
        int maxResult = maximum(numArray, numCount);
        int minResult = minimum(numArray, numCount);

        cout << "\nResults:";
        cout << "\nSum: " << sumResult;
        cout << "\nAverage: " << avgResult;
        cout << "\nMaximum: " << maxResult;
        cout << "\nMinimum: " << minResult;
    }

    return 0;
}