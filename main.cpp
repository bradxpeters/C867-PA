#include <iostream>
#include <string>
#include <sstream>

#include "degree.h"
#include "student.h"
#include "roster.h"

using namespace std;

int main() {
    Roster classRoster;

    cout << "Generating student roster: \n";
    for (int i = 0; i < 5; i++) {

        // Grab the raw student data
        string input = Student::studentData[i];
        istringstream studentString(input);

        // Separate each line by commas, store values in array
        string studentVal;
        string studentDataRaw[9];
        int counter = 0;
        while (getline(studentString, studentVal, ',')) {
            studentDataRaw[counter] = studentVal;
            counter++;
        }

        // Determine the correct degree program enum from the raw string
        DegreeProgram program;
        if (studentDataRaw[8] == "NETWORK") {
            program = DegreeProgram::NETWORK;
        } else if (studentDataRaw[8] == "SECURITY") {
            program = DegreeProgram::SECURITY;
        } else {
            program = DegreeProgram::SOFTWARE;
        }

        // Add the student to the roster
        classRoster.add(
                studentDataRaw[0],
                studentDataRaw[1],
                studentDataRaw[2],
                studentDataRaw[3],
                stoi(studentDataRaw[4]),
                stoi(studentDataRaw[5]),
                stoi(studentDataRaw[6]),
                stoi(studentDataRaw[7]),
                program
        );
    }
    cout << "----\n";

    cout << "Printing all students: \n";
    classRoster.printAll();
    cout << "----\n";

    cout << "Printing invalid emails: \n";
    classRoster.printInvalidEmails();
    cout << "----\n";

    cout << "Printing days remaining in course: \n";
    for (int i = 0; i < 5; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
    }
    cout << "----\n";

    cout << "Printing by degree program SOFTWARE: \n";
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << "----\n";

    cout << "Printing by degree program NETWORK: \n";
    classRoster.printByDegreeProgram(DegreeProgram::NETWORK);
    cout << "----\n";

    cout << "Printing by degree program SECURITY: \n";
    classRoster.printByDegreeProgram(DegreeProgram::SECURITY);
    cout << "----\n";

    cout << "Removing student A3: \n";
    classRoster.remove("A3");
    cout << "----\n";

    cout << "Printing all students (A3 has been removed): \n";
    classRoster.printAll();
    cout << "----\n";

    cout << "Removing student A3 again: \n";
    classRoster.remove("A3");
    cout << "----\n";

    return 0;
}
