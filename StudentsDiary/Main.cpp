#include "StudentsDiary.h"
#include "Student.h"
#include <iostream>

StudentsDiary studentsDiary;
 
int main()
{	
	studentsDiary.readFromFile();

	while (true)
	{
		std::cout << "--------------------------------------------------------" << std::endl;
		std::cout << "                         WELCOME                        " << std::endl;
		std::cout << "1.To add new student to the list                  press:(1)" << std::endl;
		std::cout << "2.To add grades to already existing student       press:(2)" << std::endl;
		std::cout << "3.To add new student and grades to the list       press:(3)" << std::endl;
		std::cout << "4.To remove student from the list                 press:(4)" << std::endl;
		std::cout << "5.To remove grades from the list                  press:(5)" << std::endl;
		std::cout << "6.To show students and grades list in order       press:(6)" << std::endl;
		std::cout << "7.To change student information                   press:(7)" << std::endl;
		std::cout << "8.To change grades information                    press:(8)" << std::endl;
		std::cout << "9.To change students and grades information       press:(9)" << std::endl;
		std::cout << "10.To clear the screen                            press:(10)" << std::endl;
		std::cout << "11.To exit                                        press:(11)" << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;

		int op = 0;
		std::cin >> op;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cin >> op;
		}
		
		switch (op)
		{
		case 1:
		{
			studentsDiary.addStudent();
			break;
		}
		case 2:
		{
			studentsDiary.addGrades();
			break;
		}
		case 3:
		{
			studentsDiary.addStudentWithGrades();
			break;
		}
		case 4:
		{
			studentsDiary.removeStudent();
			break;
		}
		case 5:
		{
			int wantedId = 0;
			std::cout << "Please enter the ID of the student or the grades that you want to remove!" << std::endl;
			std::cin >> wantedId;
			studentsDiary.removeGrades(wantedId);
			break;
		}
		case 6:
		{
			studentsDiary.showStudentAndGradesListInOrder();
			break;
		}
		case 7:
		{
			studentsDiary.changeStudentInfo();
			break;
		}
		case 8:
		{
			studentsDiary.changeGradesInfo();
			break;
		}
		case 9:
		{
			studentsDiary.changeStudentAndGradesInfo();
			break;
		}
		case 10:
		{
			system("cls");
			break;
		}
		case 11:
		{
			std::cout << "Thanks for using my program!" << std::endl;
			studentsDiary.writeToFile();
			exit(0);
			break;
		}
		default:
		{
			std::cout << "Please choose only from numbers from (1) to (11)!" << std::endl;
			break;
		}
		}
	}
	return 0;
}

 