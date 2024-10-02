#pragma once
#include "Student_dairy.h"


class menu
{
private:
	Student_dairy manual;
	std::string name;
	std::string file_name;
	int day;
	int sequence;
	int score;
	int status;
	int choice;
	int count;
public:
	menu();
	void general_choice();
	void schedule_actions();
	void records_actions();
	void refile_actions();

	void start();

};

