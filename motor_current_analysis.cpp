/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Jadiel Ortiz Rodriguez]
 * Lab: 9 - File I/O
 * Description: [What this specific program does]
 * Due Date: [19/oct/2026]
 */
#include <fstream>                                       // Provides ifstream and ofstream for file access
#include <iomanip>                                       // Provides fixed and setprecision
#include <iostream>                                      // Provides cin, cout, and endl
using namespace std;                                     // Allows standard-library names without the std:: prefix

// TODO: Declare prototypes for a double-returning average function and a Boolean limit function.
double calculateAverage(double total, int count);
bool isWithinLimit(double average, double limit);

int main() {                                             // Starts the program
    int requestedSamples;                                // Stores the number of readings requested by the user
    int samplesRead = 0;                                 // Counts readings successfully read from the file
    double maximumCurrent;                               // Stores the allowed average-current limit
    double currentReading;                               // Stores one current reading at a time
    double totalCurrent = 0.0;                           // Accumulates the readings obtained from the file
    double averageCurrent;                               // Stores the average returned by a function

    cout << "Enter the number of samples to analyze: ";
    cin >> requestedSamples;
    cout << "Enter the maximum allowed current (A): ";
    cin >> maximumCurrent;

    ofstream outputFile("motor_current_report.txt");
    if (!outputFile) {
        cout << "Error: Could not create the report file." << endl;
        return 1;
    }

    ifstream inputFile("current_readings.txt");
    if (!inputFile) {
        cout << "Error: Could not open the input file." << endl;
        return 1;
    }
    while (samplesRead < requestedSamples && inputFile >> currentReading) {
        totalCurrent += currentReading;
        samplesRead++;
    }
    averageCurrent = calculateAverage(totalCurrent, samplesRead);
    bool isAllowed = isWithinLimit(averageCurrent, maximumCurrent);

    return 0;                                            // Ends the program successfully
}                                                        // Ends the main function

double calculateAverage(double total, int count) {
    if (count == 0) {
        return 0.0; // Avoid division by zero
    }
    return total / count;
}
bool isWithinLimit(double average, double limit) {
    return average <= limit;
}
/*
 * Analysis:
 * 1. Why does the average function return double instead of int?
 *   Because the average of a set of numbers can be a fractional value, and using double allows for decimal precision.
 * 2. What exact comparison makes the Boolean function return true?
 *   The Boolean function returns true when the average current is less than or equal to the maximum allowed current.
 * 3. Why is samplesRead more reliable than requestedSamples for calculating the average?
 *   samplesRead represents the actual number of readings successfully read from the file, while requestedSamples is just the user's request.
 * 4. Why must the output stream close before the input stream opens the same file?
 *   Closing the output stream ensures that all data is properly written to the file and resources are released before attempting to read from it.
 */