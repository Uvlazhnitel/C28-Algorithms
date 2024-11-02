#include <iostream> 
#include <cmath>    
#include <string>   

using namespace std; 

// Function to calculate the area of a triangle using Heron's formula
double calculateArea(double a, double b, double c) {
    double s = (a + b + c) / 2; // Calculate the semi-perimeter
    return sqrt(s * (s - a) * (s - b) * (s - c)); // Return the area using Heron's formula
}

// Function to check if three lengths can form a valid triangle
bool isValidTriangle(double a, double b, double c) {
    // Check if the sum of any two sides is greater than the third
    return a + b > c && a + c > b && b + c > a;
}

// Main function where the program execution begins
int main() {
    while (true) { // Start an infinite loop
        int n; // Declare an integer to store the number of elements
        cout << "Enter the number of elements (0 to quit): "; // Prompt user to enter the number of elements

        // Validate the input to ensure it's a positive integer
        while (!(cin >> n) || n < 0) {
            cout << "Invalid input. Please enter a positive integer." << endl;
            cin.clear(); // Clear any error flags
            cin.ignore(10000, '\n'); // Ignore the next 10000 characters or until a newline
        }

        if (n == 0) break; // Break the loop if the user enters 0

        if (n < 3) { // Check if the number of elements is less than 3
            cout << "Invalid input. Please enter a positive integer greater than 2." << endl;
            continue; // Continue to the next iteration of the loop
        }

        double a[n]; // Declare an array 'a' to store the lengths
        cout << "Enter the lengths: \n"; // Prompt user to enter the lengths
        for (int i = 0; i < n; i++) { // Loop through the number of elements
            while (true) { // Start an inner infinite loop for input validation
                cout << "Enter length for element " << i + 1 << ": "; // Ask for each length
                if (cin >> a[i] && a[i] > 0) {
                    break; // Break the loop if the input is valid
                }
                cout << "Invalid length. Please enter a positive number greater than 0." << endl;
                cin.clear(); // Clear any error flags
                cin.ignore(10000, '\n'); // Ignore the next 10000 characters or until a newline
            }
        }

        bool triangleFound = false; // Flag to track if any valid triangle is found
        // Nested loops to check every combination of three lengths
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (isValidTriangle(a[i], a[j], a[k])) { // Check if a valid triangle can be formed
                        double area = calculateArea(a[i], a[j], a[k]); // Calculate the area
                        cout << "Triangle: " << a[i] << ", " << a[j] << ", " << a[k] << " | Area: " << area << endl; // Output the triangle and its area
                        triangleFound = true; // Set the flag to true
                    }
                }
            }
        }

        if (!triangleFound) { // Check if no triangle was found
            cout << "Error: No valid triangles can be formed with the given lengths." << endl;
        }
    }

    cout << "Program exited successfully." << endl; // Indicate the program has exited
    return 0; // Return 0 to indicate successful completion
}
