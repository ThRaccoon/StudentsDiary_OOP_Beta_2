#include "Student.h"

Student::Student(std::string firstName, std::string secondName,
	int age, int id)
	: m_firstName(firstName)
	, m_lastName(secondName)
	, m_age(age)
	, m_id(id)
{
}

void Student::setFirstName(std::string firstName)
{
	m_firstName = firstName;
}

void Student::setSecondName(std::string secondName)
{
	m_lastName = secondName;
}

void Student::setAge(int age)
{
	m_age = age;
}

void Student::setId(int id)
{
	m_id = id;
}

std::string Student::getFirstName()
{
	return m_firstName;
}

std::string Student::getLastName()
{
	return m_lastName;
}

int Student::getAge()
{
	return m_age;
}

int Student::getId()
{
	return m_id;
}

int Student::getId() const
{
	return m_id;
}