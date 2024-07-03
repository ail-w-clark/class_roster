//
//  roster.cpp
//  PerformanceAssessment
//
//  Created by A Clark on 2/14/24.
//

#include "roster.h"
#include "degree.h"
#include <iostream>
using namespace std;

// Constructors
Roster::Roster() {
    lastStudent = -1;
}
Roster::~Roster() {
    for (int i = 0; i <= lastStudent; i++) {
        delete classRosterArray[i];
    }
}

// Methods
void Roster::add(string studentID,
                 string firstName,
                 string lastName,
                 string emailAddress,
                 int age,
                 int daysInCourse1,
                 int daysInCourse2,
                 int daysInCourse3,
                 DegreeProgram degreeProgram) {
    if (lastStudent < 4) {
        lastStudent++;
        classRosterArray[lastStudent] = new Student(studentID,
                                                    firstName,
                                                    lastName,
                                                    emailAddress,
                                                    age,
                                                    daysInCourse1,
                                                    daysInCourse2,
                                                    daysInCourse3,
                                                    degreeProgram);
    }
}

void Roster::remove(string studentID) {
    cout << endl;
    for (int i = 0; i <= lastStudent; ++i) {
        if (classRosterArray[i]->GetStudentID() == studentID) { // Check if student ID matches
            delete classRosterArray[i];
            classRosterArray[i] = classRosterArray[lastStudent];
            lastStudent--;
            cout << "Student with ID " << studentID << " removed from roster." << endl;
            break;
        }
        else if (i == lastStudent && classRosterArray[i]->GetStudentID() != studentID){
            cout << "Student ID " << studentID << " was not found." << endl;
            break;
        }
        else {
            continue;
        }
    }
}
Student** Roster::GetClassRosterArray() {
    return classRosterArray;
}


// Printing
void Roster::printAll() {
    for (int i = 0; i <= lastStudent; i++) {
        classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    for (int i =0; i <= lastStudent; i++) {
        if (classRosterArray[i]->GetStudentID() == studentID) {
            int* daysInCourse = classRosterArray[i]->GetDaysInCourse();
            double avgDaysInCourse = (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3.0;
            cout << "Student ID: " << studentID << ", average days in course is: " << avgDaysInCourse << endl;
        }
    }
}


void Roster::printInvalidEmails() {
    cout << endl;
    for (int i = 0; i <= lastStudent; i++) {
        string checkEmail = classRosterArray[i]->GetEmailAddress();
        if (checkEmail.find('@') == string::npos || checkEmail.find('.') == string::npos
            || checkEmail.find(" ") != string::npos) {
            cout << "Student ID: " << checkEmail << " - is invalid." << endl;
        }
    }
    
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    cout << endl;
    // Convert enum into string format
    string program = "PROGRAM NOT FOUND";
    if (degreeProgram == 0) {
        program = "SECURITY";
    }
    else if (degreeProgram == 1) {
        program = "NETWORK";
    }
    else {
        program = "SOFTWARE";
    }
    cout << "Students in the " << program << " program:" << endl;
    for (int i = 0; i <= lastStudent; i++) {
        if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}
