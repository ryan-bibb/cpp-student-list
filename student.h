//*****************************************************************************************************
//
//		File:					student.h
//
//		Student:				Ryan Bibb
//
//		Assignment:				Program # 11
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-Z1
//
//		Due:					11/25/25
//
//
//		This file creates the student struct
//	
//		Other files required: 
//			1.	studentList.cpp
//			2.	node.h
//			3.	LList.h
//			
//*****************************************************************************************************

#ifndef STUDENT_H
#define STUDENT_H

//*****************************************************************************************************

#include <iostream>
#include <iomanip>
using namespace std;

//*****************************************************************************************************

struct Student
{
	int id;
	char name[50];
	char citystate[50];
	char phone[12];
	char gender;
	int year;
	int credits;
	float gpa;
	char major[6];

	Student();
	friend ostream& operator << (ostream& out, const Student& data);
	
	bool operator == (const Student& rhs) const;
	bool operator == (int value) const;
	bool operator != (const Student& rhs) const;
	bool operator != (int value) const;
	bool operator < (const Student& rhs) const;
	bool operator < (int value) const;
	bool operator > (const Student& rhs) const;
	bool operator > (int value) const;
	bool operator <= (const Student& rhs) const;
	bool operator <= (int value) const;
	bool operator >= (const Student& rhs) const;
	bool operator >= (int value) const;
};

//*****************************************************************************************************

Student::Student()
{
	id = 0;
}

//*****************************************************************************************************

ostream& operator << (ostream& out, const Student& data)
{
	out << left << setw(10) << data.id << setw(25)
		<< data.name << setw(10)
		<< data.major << setw(10)
		<< setprecision(2) << fixed << data.gpa << endl;

	return out;
}

//*****************************************************************************************************

bool Student::operator == (const Student& rhs) const
{
	return (this->id == rhs.id);
}

//*****************************************************************************************************

bool Student::operator == (int value) const
{
	return (this->id == value);
}

bool Student::operator != (const Student& rhs) const
{
	return (this->id != rhs.id);
}

//*****************************************************************************************************

bool Student::operator != (int value) const
{
	return (this->id != value);
}

//*****************************************************************************************************

bool Student::operator < (const Student& rhs) const
{
	return (this->id < rhs.id);
}

//*****************************************************************************************************

bool Student::operator < (int value) const
{
	return (this->id < value);
}

//*****************************************************************************************************

bool Student::operator > (const Student& rhs) const
{
	return (this->id > rhs.id);
}

//*****************************************************************************************************

bool Student::operator > (int value) const
{
	return (this->id > value);
}

//*****************************************************************************************************

bool Student::operator <= (const Student& rhs) const
{
	return (this->id <= rhs.id);
}

//*****************************************************************************************************

bool Student::operator <= (int value) const
{
	return (this->id <= value);
}

//*****************************************************************************************************

bool Student::operator >= (const Student& rhs) const
{
	return (this->id >= rhs.id);
}

//*****************************************************************************************************

bool Student::operator >= (int value) const
{
	return (this->id >= value);
}

//*****************************************************************************************************

#endif
