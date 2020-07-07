#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

class Student {

public:
    const static string studentData[];

    string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysInCourse();
    DegreeProgram getDegreeProgram();

	void setStudentId(string);
	void setFirstName(string);
	void setLastName(string);
	void setEmail(string);
	void setAge(int);
	void setDaysInCourse(int[3]);
	void setDegree(DegreeProgram);

	void print();
	
	Student();
	Student(
        string studentId,
        string firstName,
        string lastName,
        string email,
        int age,
        int daysInCourse[3],
        DegreeProgram degreeType
    );
	~Student();

private:
	string studentId;
	string firstName;
	string lastName;
	string email;
	int age;
	int days[3];
    DegreeProgram degreeProgramEnum;
};

#endif