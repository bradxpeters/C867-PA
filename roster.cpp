#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"

using namespace std;

void Roster::add(
        string studentID, string firstName, string lastName, string emailAddress,
        int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram
) {
    int courseDays[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[index] = new Student(
            studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram
    );
    index++;
}

void Roster::remove(string studentIdToRemove) {

    bool found = false;
    string studentId;
    int size = sizeof(classRosterArray) / sizeof(classRosterArray[0]);

    int i = 0;
    while (i < size) {
        if (classRosterArray[i] != nullptr) {
            studentId = classRosterArray[i]->getStudentId();
        }

        if (studentId == studentIdToRemove) {
            delete classRosterArray[i];
            classRosterArray[i] = classRosterArray[i + 1];
            classRosterArray[i + 1] = classRosterArray[i + 2];
            classRosterArray[size - 1] = nullptr;
            found = true;

            cout << "Student " << studentIdToRemove << " was removed. \n";
            break;
        }
        i++;
    }

    if (!found) {
        cout << "Student " << studentIdToRemove << " was not found." << endl;
    }
}

void Roster::printAll() {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i < 5; i++) {
        string email = classRosterArray[i]->getEmail();
        bool isValid = false;
        size_t found = email.find('@');
        if (found != string::npos) {
            found = email.find('.');
            if (found != string::npos) {
                found = email.find(' ');
                if (found == string::npos) {
                    isValid = true;
                }
            }
        }

        if (!isValid) {
            cout << email << " is not a valid email." << endl;
        }
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i]->getStudentId() == studentID) {
            cout << "Student " << classRosterArray[i]->getStudentId() << ": ";
            int *days = classRosterArray[i]->getDaysInCourse();
            cout << "Average number of days remaining: " << (days[0] + days[1] + days[2]) / 3 << endl;
            return;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < 5; i++) {
        DegreeProgram studentDegree = classRosterArray[i]->getDegreeProgram();
        if (studentDegree == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

Roster::~Roster() = default;
