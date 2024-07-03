//
//  student.h
//  PerformanceAssessment
//
//  Created by A Clark on 2/14/24.
//

#ifndef student_h
#define student_h

#include <string>

#include "degree.h"

using namespace std;

class Student {
public:
    // Constructors
    Student(string studentID,
            string firstName,
            string lastName,
            string emailAddress,
            int age,
            int daysInCourse1,
            int daysInCourse2,
            int daysInCourse3,
            DegreeProgram degreeProgram);
    
    // Accessors
    string GetStudentID() const;
    string GetFirstName() const;
    string GetLastName() const;
    string GetEmailAddress() const;
    
    int GetAge() const;
    int* GetDaysInCourse();
    
    DegreeProgram GetDegreeProgram() const;
    
    // Setters
    void SetStudentID(string newStudentID);
    void SetFirstName(string newFirstName);
    void SetLastName(string newLastName);
    void SetEmailAddress(string newEmailAddress);
    
    void SetAge(int newAge);
    void SetDaysInCourse(int* newDaysInCourse);
    
    void SetDegreeProgram(DegreeProgram newDegreeProgram);
    
    // Printing
    void print();
    
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    
    int age;
    int daysInCourse1;
    int daysInCourse2;
    int daysInCourse3;
    int daysInCourse[3];
    
    DegreeProgram degreeProgram;
};

#endif /* student_h */
