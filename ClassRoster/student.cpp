// Student Name: Tyler Lloyd Wickenden
// Student ID: 003613208
// Course Title: Scripting and Programming, Applications (C867)
// Programming Language: C++
#include "student.h"

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < daysInCourseArray; i++) this->daysInCourse[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < daysInCourseArray; i++) this->daysInCourse[i] = daysInCourse[i];
	this->degreeProgram = degreeProgram;
}

Student::~Student() {}

string Student::getStudentID() {
	return this->studentID;
}

string Student::getFirstName() {
	return this->firstName;
}

string Student::getLastName() {
	return this->lastName;
}

string Student::getEmail() {
	return this->email;
}

int Student::getAge() {
	return this->age;
}

int* Student::getDaysInCourse() {
	return this->daysInCourse;
}

DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}

void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmail(string email) {
	this->email = email;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysInCourse(int daysInCourse[]) {
	for (int i = 0; i < daysInCourseArray; i++) this->daysInCourse[i] = daysInCourse[i];
}

void Student::setDegreeProgram(DegreeProgram degProg) {
	this->degreeProgram = degProg;
}

void Student::printHeader() {
	cout << "Student ID\t";
	cout << "First Name\t";
	cout << "Last Name\t";
	cout << "Email Address\t";
	cout << "Age\t";
	cout << "Days left in Course\t";
	cout << "Degree Program\t";
	cout << std::endl;
}

void Student::print() {
	cout << this->getStudentID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmail() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDaysInCourse()[0] << ',';
	cout << this->getDaysInCourse()[1] << ',';
	cout << this->getDaysInCourse()[2] << '\t';
	cout << degreeProgramStr[(int)this->getDegreeProgram()];
	cout << std::endl;
}