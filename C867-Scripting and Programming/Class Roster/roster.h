//
//  roster.h
//  PerformanceAssessment
//
//  Created by A Clark on 2/14/24.
//

#ifndef roster_h
#define roster_h

#include "student.h"
#include "degree.h"

class Roster {
public:
    // Constructors
    Roster();
    ~Roster();
    
    // Methods
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void remove(string studentID);
    
    // Create an accesor to access private members in the main
    Student** GetClassRosterArray();
    
    // Printing
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);

private:
    int lastStudent;
    Student* classRosterArray[5];
};

#endif /* roster_h */
