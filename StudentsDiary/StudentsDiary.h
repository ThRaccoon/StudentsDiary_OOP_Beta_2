#pragma once
#include "Student.h"
#include "StudentGrades.h"
#include <string>
#include <vector>
 
class StudentsDiary
{
	public:
		bool operator==(const Student& a);
		bool operator==(const StudentGrades& a);
	
		void writeToFile();

		void readFromFile();

		void addStudent();
		
		void addGrades();
		
		void addStudentWithGrades();
		
		void removeStudent();
		
		void removeGrades(int wantedGradeId);
		
		void showStudentList();
		
		void showGradesList();

		void makeStudentListInOrder();

		void makeGradesListInOrder();

		void showStudentAndGradesListInOrder();

		void changeStudentInfo();
		
		void changeGradesInfo();

		void changeStudentAndGradesInfo();

	private:
		std::vector<Student> m_students;
		std::vector<StudentGrades> m_grades;
};