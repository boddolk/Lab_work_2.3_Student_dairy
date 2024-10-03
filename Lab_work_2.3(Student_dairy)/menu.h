#pragma once
#include "Student_dairy.h"


class menu
{
private:
	Student_dairy manual;
	std::string file_name, date, name, info, new_info;
	int day, sequence, score, new_score, status, choice, count;
public:
	menu();
	void set_file_name();
	void set_date();
	void set_name(std::string type_name);
	void set_new_name();
	void set_info();
	void set_new_info();
	void set_day();
	void set_sequence();
	void set_score();
	void set_new_score();
	void set_status();
	void set_choice();
	void set_count();
	void general_choice();
	void schedule_actions();
	void results_actions();
	void records_actions();
	void containers_actions();
	void refile_actions();
	void start();
};