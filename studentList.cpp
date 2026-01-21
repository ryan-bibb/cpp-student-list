//*****************************************************************************************************
//
//		File:					studentList.cpp
//
//		This file creates is the main cpp file that creates a linked list of type Student
//		aand creates a student database
//	
//		Other files required: 
//			1.	student.h
//			2.	node.h
//			3.	LList.h
//			
//*****************************************************************************************************

#include <iostream>
#include <fstream>

using namespace std;

#include "student.h"
#include "LList.h"

//*****************************************************************************************************

char getChoice();
void process(LList<Student>&);
void buildList(LList<Student>&);
void displayStudents(LList<Student>&);

void countStudents(LList<Student>&);
void addNewStudent(LList<Student>&);
void removeStudent(LList<Student>&);
void findStudent(LList<Student>&);

//*****************************************************************************************************

int main()
{
	LList<Student> studentList;

	buildList(studentList);
	process(studentList);

	return 0;
}

//*****************************************************************************************************

char getChoice()
{
	char choice;
	bool valid;

	cout << "====== Menu ======\n"
		<< "A: Add a new student\n"
		<< "F: Find a Student Record\n"
		<< "C: Count Students\n"
		<< "R: Remove a Student Record\n"
		<< "D: Display All Students\n"
		<< "Q: Quit (Exit)\n\n"
		<< "Enter your choice: ";

	do
	{
		cin >> choice;
		choice = toupper(choice);

		switch (choice)
		{
		case 'A':
		case 'F':
		case 'R':
		case 'C':
		case 'D':
		case 'Q':
			valid = true;
			break;
		default:
			valid = false;
			cout << "\aInvalid choice \n"
				<< "Please try again: ";
			break;
		}
	} while (!valid);

	return choice;
}

//*****************************************************************************************************

void buildList(LList<Student>& studentList)
{
	Student student;
	ifstream studentData;

	studentData.open("studentFile.txt");

	while (studentData >> student.id)
	{
		studentData.ignore();
		studentData.getline(student.name, 50);
		studentData.getline(student.citystate, 50);
		studentData >> student.phone
			>> student.gender
			>> student.year
			>> student.credits
			>> student.gpa
			>> student.major;

		studentList.insert(student);
	}

	studentData.close();
}

//*****************************************************************************************************

void process(LList<Student>& studentList)
{
	char choice;

	do
	{
		choice = getChoice();

		switch (choice)
		{
		case 'A':
			addNewStudent(studentList);
			break;
		case 'F': 
			findStudent(studentList);
			break;
		case 'R':
			removeStudent(studentList);
			break;
		case 'C':
			countStudents(studentList);
			break; 
		case 'D':
			displayStudents(studentList);
			break;
		case 'Q':
			break;
		}
	} while (choice != 'Q');
}

//*****************************************************************************************************

void displayStudents(LList<Student>& studentList)
{
	cout << "\t\t\tStudent List\n"
		<< "\t=================================================\n"
		<< "\tID\t  Name\t\t\t  Major\t  GPA\n"
		<< "\t=================================================\n\t";

	studentList.display();
}

//*****************************************************************************************************

void countStudents(LList<Student>& studentList)
{
	int count = studentList.getNumValues();

	cout << "Number of students: " << count << endl;
}

//*****************************************************************************************************

void addNewStudent(LList<Student>& studentList)
{
	Student student;

	cout << "Enter student id: ";
	cin >> student.id;
	cin.ignore();

	cout << "Enter student name: ";
	cin.getline(student.name, 50);

	cout << "Enter student city and state: ";
	cin.getline(student.citystate, 50);

	cout << "Enter student phone: ";
	cin >> student.phone;

	cout << "Enter student gender: ";
	cin >> student.gender;

	cout << "Enter student year: ";
	cin >> student.year;

	cout << "Enter student credits: ";
	cin >> student.credits;

	cout << "Enter student gpa: ";
	cin >> student.gpa;

	cout << "Enter student major: ";
	cin >> student.major;

	if (studentList.insert(student))
	{
		cout << "Student entered successfully" << endl;
	}
	else
	{
		cout << "Student unable to be entered" << endl;
	}
}

//*****************************************************************************************************

void removeStudent(LList<Student>& studentList)
{
	int studentID;
	Student student;

	cout << "Enter student ID to remove student: ";
	cin >> studentID;
	student.id = studentID;

	if (studentList.remove(student))
	{
		cout << student.name << " was removed." << endl;
	}
	else
	{
		cout << "Unable to find student to remove." << endl;
	}
}

//*****************************************************************************************************

void findStudent(LList<Student>& studentList)
{
	int studentID;
	Student student;

	cout << "Enter student ID to find: ";
	cin >> studentID;
	student.id = studentID;

	if (studentList.retrieve(student))
	{
		cout << "\t=================================================\n"
			<< "\tID\t  Name\t\t\t  Major\t  GPA\n"
			<< "\t=================================================\n\t"
			<< student;
	}
	else
	{
		cout << "Unable to find student." << endl;
	}
}

//*****************************************************************************************************

/*
====== Menu ======
A: Add a new student
F: Find a Student Record
C: Count Students
R: Remove a Student Record
D: Display All Students
Q: Quit
Enter your choice: d
						Student List
		=================================================
		ID        Name                    Major   GPA
		=================================================
		3930      Leibniz, Gottfried W     MATH      1.95
		4454      Atanasoff, Eniac C       CPSC      1.88
		4559      Shyster, Samuel D        SOCI      1.95
		4777      Gauss, Carl F            MATH      4.00
		5316      GotoDijkstra, Edgar G    CPSC      4.00
		5430      Nightingale, Florence K  NURS      3.15
		5710      Busch, Arch E            ENGR      2.75
		5873      Psycho, II,  Prunella E  PSYC      2.99
		7107      Shoemaker, Imelda M      POLS      3.15
		7448      Roosevelt, Rose Y        POLS      2.95
		7844      Aardvark, Anthony A      ENGR      2.79
		7885      Fibonacci, Leonard O     MATH      3.25
		9463      Hochschule, Hortense C   EDUC      2.70
		9743      Johnson, James L         ENGR      3.15
		10236     Andrews, Peter J         CPSC      2.78
		10304     Deutsch, Sprechen Z      GERM      3.05
		11688     Kronecker, Leo P         MATH      2.75
		11749     Issacson, Jacob A        RELI      2.99
		11951     Mouse, Michael E         EDUC      1.99
		13511     Pitt, Stew               GNED      0.21
		14674     Rockne, Newton K         PE        1.98
		14815     Tchaikovsky, Wolfgang A  MUSC      2.75
		15052     Einstein, Alfred M       ENGR      2.78
		15671     Rembrandt, Roberta E     ART       2.20
		15755     VandenVander, Vanessa V  HIST      3.74
		15802     Pascal, Blaze R          CPSC      1.98
		15889     Gazelle, Gwendolyn D     PE        2.78
		16183     Kuts, Cole               FOOD      3.98
		16540     Weerd, Dewey L           PHIL      2.99
		16622     Issacson, Esau B         RELI      2.98
		17376     Scrooge, Ebenezer T      SOCI      3.25
		17424     Nakamura, Toky O         SOCI      1.95
		18213     Marx, Karl Z             ECON      2.75
		18264     Lucky, Lucy L            HIST      2.29
		19077     Medes, Archie L          ENGR      3.10
		19918     Virus, Vera W            CPSC      3.25
		20454     Chicita, Juanita A       BIOL      2.66
		20991     Augusta, Ada B           CPSC      3.83
		21144     Pasteur, Louise A        BIOL      3.10
		22277     Principal, Pamela P      EDUC      1.75
		22447     Zylstra, Zelda A         ENGL      1.95
		23314     Macdonald, Ronald B      CPSC      2.99
		23497     Fault, Paige D           CPSC      2.95
		23544     Gestalt, Gloria G        PSYC      2.48
		23750     Vespucci, Vera D         GEOG      2.29
		24237     Euler, Lennie L          MATH      3.83
		25377     Porgy, Bess N            MUSI      2.78
		25831     Santamaria, Nina P       HIST      1.77
		26316     Custer, General G        HIST      1.95
		27503     Fahrenheit, Felicia O    CHEM      3.85
		28658     Cicero, Marsha           LATI      2.87
		29583     Yewliss, Cal C           MATH      2.99
		30268     Newmann, Alfred E        EDUC      0.99
		30280     Dewey, Johanna A         EDUC      3.83
		30381     Elba, Able M             SPEE      3.40
		30655     Angelo, Mike L           ART       3.74
		30749     Mendelssohn, Mozart W    MUSC      2.87
		30878     Lewis, Clark N           GEOG      3.37
		31631     Aristotle, Alice A       PHIL      3.10
		32598     Xerxes, Art I            GREE      3.25
		32631     Freud, JR, Fred E        PSYC      1.85

====== Menu ======
A: Add a new student
F: Find a Student Record
C: Count Students
R: Remove a Student Record
D: Display All Students
Q: Quit
Enter your choice: q
*/