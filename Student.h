#pragma once
#include <string>
using namespace std;
class Student
{
	int marks;
	char grade;
	string rollno;
public:
	Student();
	Student(int marks, char grade, string rollno);
	int getmarks();
	char getgrade();
	string getrollno();
	void setmarks(int m);
	void setgrade(char c);
	void setrollno(string roll);
};
