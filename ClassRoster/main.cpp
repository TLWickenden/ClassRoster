// Student Name: Tyler Lloyd Wickenden
// Student ID: 003613208
// Course Title: Scripting and Programming, Applications (C867)
// Programming Language: C++
#include "roster.h"
#include "student.h"
#include "degree.h"

int main() {
	cout << "-----------------------------------------" << std::endl;
	cout << "Class Roster Application for C867" << std::endl;
	cout << "By Tyler Wickenden, Student ID: 003613208" << std::endl;
	cout << "Written in C++" << std::endl;
	cout << "-----------------------------------------" << std::endl;

	const string studentData[] = {
		"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Tyler,Wickenden,twicken@wgu.edu,29,15,20,30,SOFTWARE"
	};

	const int studentDataTable = 5;

	Roster roster;

	for (int i = 0; i < 5; i++) {
		roster.parse(studentData[i]);
	}

	cout << "Displaying all students:" << endl;
	roster.printAll();
	cout << endl;

	for (int i = 0; i < 3; i++) {
		cout << "Displaying by Degree Program:" << degreeProgramStr[i] << endl;
		roster.printByDegreeProgram((DegreeProgram)i);
		cout << endl;
	}

	cout << "Displaying invalid email address(es):" << endl;
	roster.printInvalidEmails();
	cout << endl;

	cout << "Displaying average days per class:" << endl;
	for (int i = 0; i < studentDataTable; i++) {
		roster.printAverageDays(roster.classRosterArray[i]->getStudentID());
	}

	cout << "Remove student A3." << endl;
	roster.removeStudentByID("A3");
	cout << endl;

	cout << "Remove student A3." << endl;
	roster.removeStudentByID("A3");
	cout << endl;

	return 0;
}