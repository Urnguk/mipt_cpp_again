#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>
#include <string>

struct Student
{
	Student(std::string nm) :
		name(nm)
	{

	}

	~Student() {}

	std::string name;
	std::vector <Lesson*> assignment;
};

struct Lesson
{
	Lesson(std::string tp) :
		topic(tp)
	{

	}

	~Lesson() {}

	std::string topic;
	std::vector <Student*> attenders;
};

int main()
{

}
