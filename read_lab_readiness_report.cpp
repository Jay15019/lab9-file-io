/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Jadiel Ortiz Rodriguez]
 * Lab: 9 - File I/O
 * Description: [What this specific program does]
 * Due Date: [19/oct/2026]
 */
#include <fstream>                                       // Provides ifstream for file input
#include <iostream>                                      // Provides cout and endl
#include <string>                                        // Provides the string data type
using namespace std;                                     // Allows standard-library names without the std:: prefix

int main() {                                             // Starts the program
    ifstream inputFile("lab_readiness_report.txt");     // Prepares the existing report for input
    string line;                                         // Stores one complete line read from the file

    if (!inputFile) {
        cout << "Error: Could not open the report file." << endl; // Reports an opening failure in English
        return 1;                                       // Ends the program with an error status
    }                                                    // Ends the input-file validation
    cout << "Lab Readiness Report" << endl;
    while (getline(inputFile, line)) {
        cout << line << endl;
    }
    inputFile.close();

    return 0;                                            // Ends the program successfully
}                                                        // Ends the main function
/*
 * Analysis:
 * 1. Why does this program use ifstream instead of ofstream?
 *    Because it is reading from an existing file, not writing to one.
 * 2. What causes the while loop to stop?
 *    The loop stops when there are no more lines to read from the file.
 * 3. Why must the program test the input stream before reading?
 *    To ensure the file was opened successfully and handle any errors that may have occurred.
 */