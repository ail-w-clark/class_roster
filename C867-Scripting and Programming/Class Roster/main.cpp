//
//  main.cpp
//  PerformanceAssessment
//
//  Created AClark on 2/14/24.
//

#include <iostream>
#include "roster.h"
#include "degree.h"

using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Course Title: Scripting and Programming - Applications C867" << endl;
    cout << "Programming Language Used: C++" << endl;
    cout << "Student ID: " << endl;
    cout << "Name: A Clark" << endl;
    cout << endl;
    
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Ailene,Clark,acl1241@wgu.edu,21,17,30,29,SOFTWARE"
    };
    
    Roster classRoster;
    
    // P    arse student data
    for (int i = 0; i < 5; i++) {
        string line = studentData[i];
        string tokens[9];
        
        size_t start = 0;
        size_t end = line.find(',');
        int next = 0;
        
        while (end != string::npos) {
            tokens[next] = line.substr(start, end - start);
            start = end + 1;
            end = line.find(',', start);
            next++;
        }
        tokens[8] = line.substr(start);
        
        DegreeProgram program = SOFTWARE;
        if (tokens[8] == "NETWORK") {
            program = NETWORK;
        } else if (tokens[8] == "SECURITY") {
            program = SECURITY;
        }
        
        classRoster.add(tokens[0],
                   tokens[1],
                   tokens[2],
                   tokens[3],
                   stoi(tokens[4]),
                   stoi(tokens[5]),
                   stoi(tokens[6]),
                   stoi(tokens[7]),
                   program);
    }
    
    classRoster.printAll();
    
    classRoster.printInvalidEmails();
    
    cout << endl;
    
    for (int i = 0; i <= 4; ++i) {
        Student** rosterArray = classRoster.GetClassRosterArray();
        classRoster.printAverageDaysInCourse(rosterArray[i]->GetStudentID());
        rosterArray++;
    }
    
    classRoster.printByDegreeProgram(SOFTWARE);
    
    classRoster.remove("A3");
    
    cout << endl;
    
    classRoster.printAll();
    
    classRoster.remove("A3");

    return 0;
}
