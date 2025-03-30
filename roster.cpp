#include "roster.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

Roster::Roster() {
    
    // Student data 
    const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Kyle,Ryer,kyleryer4@gmail.com,28,15,20,14,SOFTWARE"};
    
    // Loop through student data
    for (int i = 0; i < 5; ++i) {
                
        // Parse data for roster add function
        stringstream ss;
        ss.str(studentData[i]);
        vector<string> subStrings;

        string studentID;
        string firstName;
        string lastName;
        string emailAddress;
        int age;
        int daysInCourse1;
        int daysInCourse2;
        int daysInCourse3;
        DegreeProgram degreeProgram;

        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            subStrings.push_back(substr);
        }

        // Assign parsed data to variables
        studentID = subStrings.at(0);
        firstName = subStrings.at(1);
        lastName = subStrings.at(2);
        emailAddress = subStrings.at(3);
        age = stoi(subStrings.at(4));
        daysInCourse1 = stoi(subStrings.at(5));
        daysInCourse2 = stoi(subStrings.at(6));
        daysInCourse3 = stoi(subStrings.at(7));
        if (subStrings.at(8) == "SECURITY") {
            degreeProgram = SECURITY;
        }
        else if (subStrings.at(8) == "NETWORK") {
            degreeProgram = NETWORK;
        }
        else {
            degreeProgram = SOFTWARE;
        }

        // Add student to roster
        add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    }
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, 
    int daysInCourse3, DegreeProgram degreeProgram) {
            Student *student = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
            classRosterArray[arrayIndex] = student;
            ++arrayIndex;
    }


void Roster::remove(string studentID) {
    bool studentFound = false;

    for (int i = 0; i < arrayIndex; ++i) {
        if (classRosterArray[i]->GetStudentID() == studentID) {
            studentFound = true;

            // Delete student from array
            delete classRosterArray[i];
            
            // Fill gap in array
            while (i < arrayIndex - 1) {
                classRosterArray[i] = classRosterArray[i + 1];
                ++i;
            }
            
            --arrayIndex;

            break;
        }
    }
    if (studentFound == false) {
        cout << "Student ID was not found." << endl;
    }
}

void Roster::printAll() {
    for (int i = 0; i < arrayIndex; ++i) {
        classRosterArray[i]->Print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < arrayIndex; ++i) {
        if (classRosterArray[i]->GetStudentID() == studentID) {
            int* ptr = classRosterArray[i]->GetNumOfDays();
            double average = (ptr[0] * 1.0 + ptr[1] + ptr[2]) / 3.0;
            cout << fixed << setprecision(1);
            cout << "Average number of days in a course for student ID " << classRosterArray[i]->GetStudentID() << " is " << average << " days." << endl;
        }
    }
}

void Roster::printInvalidEmails() {
    // Loop through each student's email
    for (int i = 0; i < arrayIndex; ++i) {
        
        string email = classRosterArray[i]->GetEmailAddress();
        int atCounter = 0;
        int periodCounter = 0;
        bool invalid = false;
        
        // Loop through each character of email address
        for (int j = 0; j < email.length(); ++j) {

            // If space found, email is invalid
            if (email[j] == ' ') {
                invalid = true;
                break;
            }                   
        
            // If '@' is found, loop through next characters in email address until end looking for spaces and/or periods
            else if (email[j] == '@') {
                ++atCounter;

                for (int k = j + 1; k < email.length(); ++k) {

                    // If space found, email is invalid
                    if (email[j] == ' ') {
                        invalid = true;
                        break;
                    } 
                    // If period found, indicate one or more were found    
                    else if (email[k] == '.') {
                        ++periodCounter;
                    }
                }
            }
        }
        // Email is invalid if email contains anything other than 1 '@' followed by a string of characters containing at least 1 '.'
        if (atCounter != 1 || periodCounter < 1) {
            invalid = true;
        }

        // If email is invalid, print invalid email
        if (invalid == true) {
            cout << email << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < arrayIndex; ++i) {
        if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            classRosterArray[i]->Print();
        }
    }
}

Student Roster::GetStudent(int index) {
    return *(classRosterArray[index]);
}

// Destructor
Roster::~Roster() {
    for (int i = 0; i < arrayIndex; ++i) {
        delete classRosterArray[i];
    }
}