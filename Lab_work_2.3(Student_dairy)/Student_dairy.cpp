#include "Student_dairy.h"

Student_dairy::Student_dairy()
	:s_name{ "noname" }, s_surname{ "nosurname"}, course(0)

{
}

Student_dairy::Student_dairy(std::string s_name, std::string s_surname, int course)
	:s_name(s_name), s_surname(s_surname), course(course)
{
}

void Student_dairy::add_record(std::unique_ptr<Record> item)
{
	if (item)
}
