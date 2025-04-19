#include <iostream>
using namespace std;

// Function to count students in a particular activity group
int sameGroupStudent(int particularGroup, int studentGroup) {
    int count = 0;

    // Process each digit in studentGroup
    while (studentGroup > 0) {
        int digit = studentGroup % 10; // Extract the last digit
        if (digit == particularGroup) {
            count++; // Increment count if digit matches particularGroup
        }
        studentGroup /= 10; // Remove the last digit
    }

    return count;
}

int main() {
    int particularGroup, studentGroup;

    // Input for particularGroup
    cout << "Enter the activity group digit (0-9): ";
    cin >> particularGroup;

    // Input for studentGroup
    cout << "Enter the student group as a number: ";
    cin >> studentGroup;

    // Call the function and output the result
    int result = sameGroupStudent(particularGroup, studentGroup);
    cout << "Number of students in activity group " << particularGroup << ": " << result << endl;

    return 0;
}
