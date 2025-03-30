#include "student.h"
#include <iostream>

// Default constructor
Student::Student() {
    studentID = "Unknown";
    firstName = "Unknown";
    lastName = "Unknown";
    emailAddress = "Unknown";
    age = -1;
    numOfDays[0] = -1;
    numOfDays[1] = -1;
    numOfDays[2] = -1;
    degreeProgram = SECURITY;
}

// Constructor with all parameters
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numOfDays1, int numOfDays2, 
int numOfDays3, DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    numOfDays[0] = numOfDays1;
    numOfDays[1] = numOfDays2;
    numOfDays[2] = numOfDays3;
    this->degreeProgram = degreeProgram;
}

string Student::GetStudentID() {
    return studentID;
}

string Student::GetFirstName() {
    return firstName;
}

string Student::GetLastName() {
    return lastName;
}

string Student::GetEmailAddress() {
    return emailAddress;
}

int Student::GetAge() {
    return age;
}

int* Student::GetNumOfDays() {
    return numOfDays;
}

DegreeProgram Student::GetDegreeProgram() {
    return degreeProgram;
}

void Student::SetStudentID(string id) {
    studentID = id;
}

void Student::SetFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::SetLastName(string lastName) {
    this->lastName = lastName;
}

void Student::SetEmailAddress(string email) {
    emailAddress = email;
}

void Student::SetAge(int age) {
    this->age = age;
}

void Student::SetNumOfDays(int numOfDays1, int numOfDays2, int numOfDays3) {
    numOfDays[0] = numOfDays1;
    numOfDays[1] = numOfDays2;
    numOfDays[2] = numOfDays3;
}

void Student::SetDegreeProgram(DegreeProgram degree) {
    degreeProgram = degree;
}

// Print student info
void Student::Print() {
    int* ptr = GetNumOfDays();

    if (GetDegreeProgram() == 0) {
        cout << GetStudentID() << "   " << "First Name: " << GetFirstName() << "   " << "Last Name: " << GetLastName() <<
        "   " << "Age: " << GetAge() << "   " << "daysInCourse: {" << ptr[0] << ", " << ptr[1] <<
        ", " << ptr[2] << "} Degree Program: " << "Security" << endl;
    }

    else if (GetDegreeProgram() == 1) {
        cout << GetStudentID() << "   " << "First Name: " << GetFirstName() << "   " << "Last Name: " << GetLastName() <<
        "   " << "Age: " << GetAge() << "   " << "daysInCourse: {" << ptr[0] << ", " << ptr[1] <<
        ", " << ptr[2] << "} Degree Program: " << "Network" << endl;
    }

    else {
        cout << GetStudentID() << "   " << "First Name: " << GetFirstName() << "   " << "Last Name: " << GetLastName() <<
        "   " << "Age: " << GetAge() << "   " << "daysInCourse: {" << ptr[0] << ", " << ptr[1] <<
        ", " << ptr[2] << "} Degree Program: " << "Software" << endl;
    }
}