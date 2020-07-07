#include <iostream>
#include <string>
#include <iomanip>

#include "degree.h"
#include "student.h"

using namespace std;

const string Student::studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Brad,Peters,bpet202@wgu.edu,31,50,51,52,SOFTWARE"
};

string Student::getStudentId()
{
	return studentId;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmail()
{
	return email;
}

int Student::getAge()
{
	return age;
}

int* Student::getDaysInCourse()
{
	return days;
}

DegreeProgram Student::getDegreeProgram()
{
	return degreeProgramEnum;
}

void Student::setStudentId(string newStudentId)
{
    studentId = newStudentId;
}

void Student::setFirstName(string newFirstName)
{
    firstName = newFirstName;
}

void Student::setLastName(string newLastName)
{
    lastName = newLastName;
}

void Student::setEmail(string newEmail)
{
    email = newEmail;
}

void Student::setAge(int newAge)
{
    age = newAge;
}

void Student::setDaysInCourse(int* daysInCourse)
{
	for (int i = 0; i < 3; i++) {
        days[i] = daysInCourse[i];
	}
}

void Student::setDegree(DegreeProgram newDegreeProgram)
{
    degreeProgramEnum = newDegreeProgram;
}

void Student::print()
{
    cout << "Student ID: "     << left << setw(5)  << this->getStudentId();
    cout << "First Name: "     << left << setw(10) << this->getFirstName();
    cout << "Last Name: "      << left << setw(10) << this->getLastName();
    cout << "Email: "          << left << setw(25) << this->getEmail();
    cout << "Age: "            << left << setw(5)  << this->getAge();
    cout << "Days 1: "         << left << setw(5)  << this->getDaysInCourse()[0];
    cout << "Days 2: "         << left << setw(5)  << this->getDaysInCourse()[1];
    cout << "Days 3: "         << left << setw(5)  << this->getDaysInCourse()[2];
    cout << "Degree Program: " << left << setw(10);
    if (this->getDegreeProgram() == DegreeProgram::SECURITY) {
        cout << "Security";
    }
    else if (this->getDegreeProgram() == DegreeProgram::NETWORK) {
        cout << "Network";
    }
    else{
        cout << "Software";
    }
    cout << endl;
}

Student::Student() {}

Student::Student(string studentId, string firstName, string lastName, string email, int age, int daysInCourse[3], DegreeProgram degreeType)
{
	setStudentId(studentId);
	setFirstName(firstName);
	setLastName(lastName);
	setEmail(email);
	setAge(age);
	setDaysInCourse(daysInCourse);
	setDegree(degreeType);
}

Student::~Student()= default;