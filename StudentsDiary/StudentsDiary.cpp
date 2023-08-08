#include "StudentsDiary.h"
#include  <iostream> 
#include <algorithm> 
#include <fstream>

Student student;

int isItInt(int& digit);

float isItFloat(float& digit);

bool operator==(const Student& a, const int& b)
{
	return b == a.getId();
}

bool operator==(const StudentGrades& a, const int& b)
{
	return b == a.getGradeId();
}

void StudentsDiary::writeToFile()
{
	std::ofstream file("file.txt");
	
	makeStudentListInOrder();
	makeGradesListInOrder();

	for(int i = 0; i < m_students.size(); i++)
	{
		file << m_students[i].getFirstName() << std::endl;
		file << m_students[i].getLastName() << std::endl;
		file << m_students[i].getAge() << std::endl;
		file << m_students[i].getId() << std::endl;
	
		file << m_grades[i].getMath() << std::endl;
		file << m_grades[i].getBg() << std::endl;
		file << m_grades[i].getEn() << std::endl;
		file << m_grades[i].getGradeId() << std::endl;
	}
	file.close();
}

void StudentsDiary::readFromFile()
{
	std::string firstName = "NA"; 
	std::string lastName = "NA";
	int age = 0; 
	int id = 0; 
	int gradeId = 0;
	float mathGrade = 0; 
	float bgGrade = 0; 
	float enGrade = 0;

	std::ifstream file("file.txt");

	while(!file.eof())
	{
		file >> firstName >> lastName >> age >> id
			>> mathGrade >> bgGrade >> enGrade >> gradeId;
		
		auto it = std::find(m_students.begin(), m_students.end(), id);
		
		if(it != m_students.end())
		{
			std::cout << "Dublicate found!" << std::endl;
			return;
		}	
		else 
		{
			m_students.push_back(Student(firstName, lastName, age, id));
			m_grades.push_back(StudentGrades(gradeId, mathGrade, bgGrade, enGrade));
		} 
	}
	file.close();
}

void StudentsDiary::addStudent()
{
	std::string firstName;
	std::string lastName;
	int age = 0;
	int id = 0;
	 
	std::cin.ignore();
	std::cout << "Enter student first name: " << std::endl;
	getline(std::cin, firstName);

	std::cin.clear();
	std::cout << "Enter student last name: " << std::endl;
	getline(std::cin, lastName);

	std::cout << "Enter student age: " << std::endl;
	std::cin >> age;
	isItInt(age);

	std::cout << "Enter student ID: " << std::endl;
	std::cin >> id;
	isItInt(id);
	
	int wantedId = 0;
	wantedId = id;

	auto it = std::find(m_students.begin(), m_students.end(), wantedId);

	if (it != m_students.end())
	{
		std::cout << "Student with ID #" << wantedId << " already exist!" << std::endl;
	}
	else
	{
		m_students.push_back(Student(firstName, lastName, age, id));
		
		int gradeid = 0;
		gradeid = id;
		float math = 0;
		float bg = 0;
		float en = 0;

		m_grades.push_back(StudentGrades(gradeid, math, bg, en));
	}
}

void StudentsDiary::addGrades()
{
	float math = 0;
	float bg = 0;
	float en = 0;
	int gradeid = 0;

	int wantedId = 0;
	std::cout << "Please enter the ID of the student that you want to add grade!" << std::endl;
	std::cin >> wantedId;
	isItInt(wantedId);

	auto it = std::find(m_students.begin(), m_students.end(), wantedId);

	if (it != m_students.end())
	{
		auto it = std::find(m_grades.begin(), m_grades.end(), wantedId);

		if (it != m_grades.end())
		{
			m_grades.erase(it);

			int gradeid = 0;
			float math = 0;
			float bg = 0;
			float en = 0;

			std::cout << "Enter math grade: " << std::endl;
			std::cin >> math;
			isItFloat(math);

			std::cout << "Enter bg grade: " << std::endl;
			std::cin >> bg;
			isItFloat(bg);

			std::cout << "Enter en grade: " << std::endl;
			std::cin >> en;
			isItFloat(en);

			gradeid = wantedId;

			m_grades.push_back(StudentGrades(gradeid, math, bg, en));
		}
	}
	else
	{
		std::cout << "Student with #" << wantedId << " does not exist!" << std::endl;
	}
}

void StudentsDiary::addStudentWithGrades()
{
	std::string firstName;
	std::string lastName;
	int age = 0;
	int id = 0;
	float math = 0;
	float bg = 0;
	float en = 0;
	int gradeid = 0;

	std::cin.ignore();
	std::cout << "Enter student first name: " << std::endl;
	getline(std::cin, firstName);

	std::cin.clear();
	std::cout << "Enter student last name: " << std::endl;
	getline(std::cin, lastName);

	std::cout << "Enter student age: " << std::endl;
	std::cin >> age;
	isItInt(age);

	std::cout << "Enter student ID: " << std::endl;
	std::cin >> id;
	isItInt(id);

	gradeid = id;

	std::cout << "Enter math grade: " << std::endl;
	std::cin >> math;
	isItFloat(math);

	std::cout << "Enter bg grade: " << std::endl;
	std::cin >> bg;
	isItFloat(bg);

	std::cout << "Enter en grade: " << std::endl;
	std::cin >> en;
	isItFloat(en);

	int wantedId = 0;
	wantedId = id;

	auto it = std::find(m_students.begin(), m_students.end(), wantedId);

	if (it != m_students.end())
	{
		std::cout << "Student with ID #" << wantedId << " already exist!" << std::endl;
	}
	else
	{
		m_students.push_back(Student(firstName, lastName, age, id));
		m_grades.push_back(StudentGrades(gradeid, math, bg, en));
	}
}

void StudentsDiary::removeStudent()
{
	int wantedId;
	std::cout << "Please enter the student ID that you want to remove!" << std::endl;
	std::cin >> wantedId;
	isItInt(wantedId);

	auto it = std::find(m_students.begin(), m_students.end(), wantedId);
	auto it1 = std::find(m_grades.begin(), m_grades.end(), wantedId);

	if (it != m_students.end())
	{
		m_grades.erase(it1);
		m_students.erase(it);
		std::cout << "Student with ID #" << wantedId << " was deleted!" << std::endl;
	}
	else
	{
		std::cout << "Studen with ID #" << wantedId << " was not faund!" << std::endl;
		return;
	}
}

void StudentsDiary::removeGrades(int wantedGradeId)
{
	int wantedId = 0;
	wantedId = wantedGradeId;
	isItInt(wantedId);

	auto it = std::find(m_grades.begin(), m_grades.end(), wantedId);

	if (it != m_grades.end())
	{
		m_grades.erase(it);
		int gradeid = 0;
		float math = 0;
		float bg = 0;
		float en = 0;

		gradeid = wantedId;

		m_grades.push_back(StudentGrades(gradeid, math, bg, en));
		std::cout << "Student grades with ID #" << wantedId << " were deleted!" << std::endl;
	}
	else
	{
		std::cout << "Studen grades with ID #" << wantedId << " were not faund!" << std::endl;
	}
}

//Not in use
void StudentsDiary::showStudentList()
{	
	int size = 0;
	size = m_students.size();

	if (size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << "Student first name: " << m_students[i].getFirstName() << std::endl;
			std::cout << "Student last name: " << m_students[i].getLastName() << std::endl;
			std::cout << "Student age: " << m_students[i].getAge() << std::endl;
			std::cout << "Student ID: " << m_students[i].getId() << std::endl;
			std::cout << "-----------------------------" << std::endl;
		}
	}
	else
	{
		std::cout << "This list is empty!" << std::endl;
	}
}

//Not in use
void StudentsDiary::showGradesList()
{
	int size = 0;
	size = m_grades.size();

	if (size > 0)
	{
		for (int i = 0; i < size; i++)
		{	 
			std::cout << "Student math grade: " << m_grades[i].getMath() << std::endl;
			std::cout << "Student bg grade: " << m_grades[i].getBg() << std::endl;
			std::cout << "Student en grade: " << m_grades[i].getEn() << std::endl;
			std::cout << "Student grade ID is: " << m_grades[i].getGradeId() << std::endl;
			std::wcout << "-----------------------------------" << std::endl;
		}
	}
	else
	{
		std::cout << "This list is empty!" << std::endl;
	}
}

void StudentsDiary::makeStudentListInOrder()
{
	std::sort(m_students.begin(), m_students.end(), [](const Student& lhs, const Student& rhs)
		{
			return lhs.getId() < rhs.getId();
		}
	);
}

void StudentsDiary::makeGradesListInOrder()
{
	std::sort(m_grades.begin(), m_grades.end(), [](const StudentGrades& lhs, const StudentGrades& rhs)
		{
			return lhs.getGradeId() < rhs.getGradeId();
		}
	);	 
}

void StudentsDiary::showStudentAndGradesListInOrder()
{
	int size = 0;
	size = m_students.size();

	if (size > 1) {
		makeStudentListInOrder();
		makeGradesListInOrder();

		for (int i = 1; i < m_students.size(); i++)
		{
			std::cout << "Student first name is: " << m_students[i].getFirstName() << std::endl;
			std::cout << "Student second name is: " << m_students[i].getLastName() << std::endl;
			std::cout << "Student age is: " << m_students[i].getAge() << std::endl;
			std::cout << "Student ID is: " << m_students[i].getId() << std::endl;

			auto it = std::find(m_grades.begin(), m_grades.end(), m_students[i].getId());

			if (it != m_grades.end())
			{
				std::cout << "Student math grade: " << m_grades[i].getMath() << std::endl;
				std::cout << "Student bg grade: " << m_grades[i].getBg() << std::endl;
				std::cout << "Student en grade: " << m_grades[i].getEn() << std::endl; 
				std::cout << "Student grade ID is: " << m_grades[i].getGradeId() << std::endl;
			}
			else
			{
				std::cout << "This student don't have grades" << std::endl;
			}
			std::cout << "-------------------------------" << std::endl;
		}
	}
	else
	{
		std::cout << "The list is empty" << std::endl;
	}
}

void StudentsDiary::changeStudentInfo()
{
	int wantedId = 0;
	std::cout << "Please enter the ID of the student that you want to change!" << std::endl;
	std::cin >> wantedId;
	isItInt(wantedId);

	auto it = std::find(m_students.begin(), m_students.end(), wantedId);

	if (it != m_students.end())
	{
		m_students.erase(it);

		std::string firstName;
		std::string lastName;
		int age = 0;
		int id = 0;

		std::cin.ignore();
		std::cout << "Enter student first name: " << std::endl;
		getline(std::cin, firstName);

		std::cin.clear();
		std::cout << "Enter student last name: " << std::endl;
		getline(std::cin, lastName);

		std::cout << "Enter student age: " << std::endl;
		std::cin >> age;
		isItInt(age);

		id = wantedId;

		m_students.push_back(Student(firstName, lastName, age, id));
	}
	else
	{
		std::cout << "Student with this ID #" << wantedId << " does not exist!" << std::endl;
	}

}

void StudentsDiary::changeGradesInfo()
{
	int wantedId = 0;
	std::cout << "Please enter the ID of the grades that you want to change!" << std::endl;
	std::cin >> wantedId;
	isItInt(wantedId);

	auto it = std::find(m_grades.begin(), m_grades.end(), wantedId);

	if(it != m_grades.end())
	{
		m_grades.erase(it);
		
		int gradeid = 0;
		float math = 0;
		float bg = 0;
		float en = 0;

		std::cout << "Enter math grade: " << std::endl;
		std::cin >> math;
		isItFloat(math);

		std::cout << "Enter bg grade: " << std::endl;
		std::cin >> bg;
		isItFloat(bg);

		std::cout << "Enter en grade: " << std::endl;
		std::cin >> en;
		isItFloat(en);

		gradeid = wantedId;

		m_grades.push_back(StudentGrades(gradeid, math, bg, en));
	}
}

void StudentsDiary::changeStudentAndGradesInfo()
{
	int wantedId = 0;
	std::cout << "Please enter the ID of the student or his grades ID that you want to change!" << std::endl;
	std::cin >> wantedId;
	isItInt(wantedId);

	auto it = std::find(m_students.begin(), m_students.end(), wantedId);
	 

	if(it != m_students.end())
	{
		m_students.erase(it);
		removeGrades(wantedId);
	
		addStudentWithGrades();
	}
	else
	{
		std::cout << "Student with this ID #" << wantedId << " does not exist!" << std::endl;
	}
}

int isItInt(int& digit)
{
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
		std::cin >> digit;
	}
	return digit;
}

float isItFloat(float& digit)
{
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
		std::cin >> digit;
	}
	return digit;
}