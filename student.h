#ifndef STUDENTH
#define STUDENTH

#include "degree.h"
#include <string>
using namespace std;

class Student {
    public:
        // Default constructor
        Student();
        
        // Constructor with all parameters
        Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numOfDays1, int numOfDays2, 
        int numOfDays3, DegreeProgram degreeProgram);

        string GetStudentID();

        string GetFirstName();
        
        string GetLastName();

        string GetEmailAddress();

        int GetAge();

        int* GetNumOfDays();

        DegreeProgram GetDegreeProgram();

        void SetStudentID(string id);

        void SetFirstName(string firstName);

        void SetLastName(string lastName);

        void SetEmailAddress(string email);

        void SetAge(int age);

        void SetNumOfDays(int numOfDays1, int numOfDays2, int numOfDays3);

        void SetDegreeProgram(DegreeProgram degree);

        // Print student info
        void Print();

    private:
        string studentID;
        string firstName;
        string lastName;
        string emailAddress;
        int age;
        int numOfDays[3];
        DegreeProgram degreeProgram;        
};

#endif