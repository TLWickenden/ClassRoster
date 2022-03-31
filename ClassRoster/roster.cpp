// Student Name: Tyler Lloyd Wickenden
// Student ID: 003613208
// Course Title: Scripting and Programming, Applications (C867)
// Programming Language: C++
#include "roster.h"

void Roster::parse(string items) {
	std::vector<string> tokens;
	DegreeProgram degProg;
	for (int i = 0; i < studentData; ++i) {
		std::stringstream ss(items);

		while (ss.good()) {
			string subStr;
			std::getline(ss, subStr, ',');
			tokens.push_back(subStr);
		}

		if (tokens[8] == "SECURITY") {
			degProg = DegreeProgram::SECURITY;
		}
		if (tokens[8] == "NETWORK") {
			degProg = DegreeProgram::NETWORK;
		}
		if (tokens[8] == "SOFTWARE") {
			degProg = DegreeProgram::SOFTWARE;
		}
	}
	add(tokens.at(0), tokens.at(1), tokens.at(2), tokens.at(3), stoi(tokens.at(4)), stoi(tokens.at(5)),
		stoi(tokens.at(6)), stoi(tokens.at(7)), degProg);
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int days1, int days2, int days3, DegreeProgram degProg) {
	int daysArray[3] = { days1, days2, days3 };
	classRosterArray[++last] = new Student(studentID, firstName, lastName, email, age, daysArray, degProg);
	cout << "Student added to class roster at row " << last + 1 << endl;
}

void Roster::printAll() {
	Student::printHeader();
	for (int i = 0; i <= Roster::last; i++) Roster::classRosterArray[i]->print();
}

void Roster::printByDegreeProgram(DegreeProgram degProg) {
	Student::printHeader();
	for (int i = 0; i <= Roster::last; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degProg) classRosterArray[i]->print();
	}
	cout << endl;
}

void Roster::printInvalidEmails() {
	bool any = false;
	for (int i = 0; i <= Roster::last; i++) {
		string email = (classRosterArray[i]->getEmail());
		if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos)) {
			any = true;
			cout << email << ":" << classRosterArray[i]->getFirstName() << std::endl;
		}
	}
	if (!any) cout << "No invalid IDs" << std::endl;
}

void Roster::printAverageDays(string studentID) {
	for (int i = 0; i <= Roster::last; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			cout << studentID << ":";
			cout << (classRosterArray[i]->getDaysInCourse()[0] +
				classRosterArray[i]->getDaysInCourse()[1] +
				classRosterArray[i]->getDaysInCourse()[2]) / 3 << endl;
		}
	}
}

void Roster::removeStudentByID(string studentID) {
	bool success = false;
	for (int i = 0; i <= Roster::last; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			success = true;
			delete classRosterArray[i];
			Student* x = classRosterArray[i];
			classRosterArray[i] = classRosterArray[studentData - 1];
			classRosterArray[studentData - 1] = x;
			Roster::last--;
		}
	}
	if (success) {
		cout << "Student " << studentID << " removed." << endl;
		printAll();
	}
	else {
		cout << "Student " << studentID << " not found." << endl;
	}
}

Roster::~Roster() {
	for (int i = 0; i <= last; i++) {
		cout << "Destructor called for " << classRosterArray[i]->getStudentID() << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}