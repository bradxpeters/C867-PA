#include <iostream>
#include <string>
#include "student.h"

using namespace std;

class Roster {
public:

    Student* classRosterArray[5];
    int index = 0;
    
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void remove(string studentID);
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
    ~Roster();
};