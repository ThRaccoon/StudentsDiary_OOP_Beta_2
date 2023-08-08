#pragma once
#include <string>

class Student
{
	public:

		Student() = default;
		Student(std::string firstName, std::string lastName,
			int age, int id);

		void setFirstName(std::string firstName);
		void setSecondName(std::string lastName);
		void setAge(int age);
		void setId(int id);

		std::string getFirstName();
		std::string getLastName();
		int getAge();
		int getId();
		int getId() const;

	private:

		std::string m_firstName;
		std::string m_lastName;
		int m_age;
		int m_id;

};