#ifndef ROSTERH
#define ROSTERH

#include "degree.h"
#include "student.h"
#include <string>
using namespace std;

class Roster {
    public:
        Roster();

        ~Roster();
        
        void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, 
            int daysInCourse3, DegreeProgram degreeProgram);
        
        void remove(string studentID);

        void printAll();

        void printAverageDaysInCourse (string studentID);

        void printInvalidEmails();

        void printByDegreeProgram(DegreeProgram degreeProgram);

        Student GetStudent(int index);

    private: 
        Student* classRosterArray[5];
        int arrayIndex = 0;
};

#endif