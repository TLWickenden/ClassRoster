#pragma once
#include <vector>
#include <sstream>
#include "student.h"

const static int studentData = 5;

class Roster {
private:
	int last = -1;
public:
	Student* classRosterArray[studentData] = { nullptr, nullptr, nullptr, nullptr, nullptr };

	void parse(string row);
	void add(string aStudentID, string aFirstName, string aLastName, string aEmail, int aAge, int days1, int days2, int days3, DegreeProgram degProg);
	void printAll();
	void printByDegreeProgram(DegreeProgram degProg);
	void printInvalidEmails();
	void printAverageDays(string studentID);
	void removeStudentByID(string studentID);
	~Roster();
};