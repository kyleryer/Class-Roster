#include "degree.h"
#include "student.h"
#include "roster.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {

    // My information
    cout << "Course: Scripting and Programming Applications" << endl;
    cout << "Language used: C++" << endl;
    cout << "My WGU Student ID: 012026763" << endl;
    cout << "My name: (Jack) Kyle Ryer" << endl;
    cout << endl;

    // Create roster
    Roster classRoster;

    // Print class roster
    classRoster.printAll();
    cout << endl;

    // Print all invalid emails
    classRoster.printInvalidEmails();
    cout << endl;

    // Loop through each student in roster and print average number of days in course for each
    for (int i = 0; i < 5; ++i) {
        classRoster.printAverageDaysInCourse(classRoster.GetStudent(i).GetStudentID());
    }
    cout << endl;

    // Print students that are in the software degree program
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    // Remove student with ID "A3" from roster
    classRoster.remove("A3");

    // Print class roster
    classRoster.printAll();
    cout << endl;

    // Try to remove student with ID "A3" from roster again
    classRoster.remove("A3");

    return 0;
}


