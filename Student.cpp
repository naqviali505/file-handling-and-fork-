#include"Student.h"
Student::Student()
{
	marks = 0;
	rollno = " ";
	grade = 0;
}
Student::Student(int marks, char grade, string rollno)
{
	this->marks = marks;
	this->grade = grade;
	this->rollno = rollno;
}
int Student::getmarks()
{
	return marks;
}
char Student::getgrade()
{
	return grade;
}
string Student::getrollno()
{
	return rollno;
}
void Student::setmarks(int m)
{
	marks = m;
}
void Student::setgrade(char c)
{
	grade = c;
}
void Student::setrollno(string roll)
{
	rollno = roll;
}