//
//  student.cpp
//  PerformanceAssessment
//
//  Created by A Clark on 2/14/24.
//

#include <iostream>

#include "student.h"
#include "degree.h"

using namespace std;

Student::Student(string studentID,
                 string firstName,
                 string lastName,
                 string emailAddress,
                 int age,
                 int daysInCourse1,
                 int daysInCourse2,
                 int daysInCourse3,
                 DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysInCourse[0] = daysInCourse1;
    this->daysInCourse[1] = daysInCourse2;
    this->daysInCourse[2] = daysInCourse3;
    this->degreeProgram = degreeProgram;
}

// Getters
string Student::GetStudentID() const {
    return studentID;
}
string Student::GetFirstName() const {
    return firstName;
}
string Student::GetLastName() const {
    return lastName;
}
string Student::GetEmailAddress() const {
    return emailAddress;
}

int Student::GetAge() const {
    return age;
}
int* Student::GetDaysInCourse() {
    return daysInCourse;
}

DegreeProgram Student::GetDegreeProgram() const {
    return degreeProgram;
}


// Setters
void Student::SetStudentID(string newStudentID) {
    studentID = newStudentID;
}
void Student::SetFirstName(string newFirstName) {
    firstName = newFirstName;
}
void Student::SetLastName(string newLastName) {
    lastName = newLastName;
}
void Student::SetEmailAddress(string newEmailAddress) {
    emailAddress = newEmailAddress;
}

void Student::SetAge(int newAge) {
    age = newAge;
}
void Student::SetDaysInCourse(int* daysInCourse) {
    daysInCourse[0] = daysInCourse1;
    daysInCourse[1] = daysInCourse2;
    daysInCourse[2] = daysInCourse3;
    }


void Student::SetDegreeProgram(DegreeProgram newDegreeProgram) {
    degreeProgram = newDegreeProgram;
}

// Printing
void Student::print() {
    cout << studentID << "\t" << firstName << "\t" << lastName << "\t";
    cout << emailAddress << "\t" << age << "\t";
    
    for (int i = 0; i < 3; i++) {
        cout << daysInCourse[i] << "\t";
    }
    
    if (degreeProgram == SOFTWARE) {
        cout << "SOFTWARE";
    } else if (degreeProgram == NETWORK) {
        cout << "NETWORK";
    } else {
        cout << "SECURITY";
    }
    
    cout << endl;
}
