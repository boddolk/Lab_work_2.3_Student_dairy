#include "Sched_path.h"

Sched_path::Sched_path()
	: Subject(), day(0), sequence(0)
{}

Sched_path::Sched_path(std::string name, int day, int sequence)
	: Subject(name), day((day >= 1 && day <= 5 ? day : throw -1)), sequence((sequence >= 1 && sequence <= 5 ? sequence : throw - 1))
{}

void Sched_path::extraction(std::ifstream& ifs) 
{
	std::getline(ifs, name);
	ifs >> day;
	ifs.ignore();
	ifs >> sequence;
	ifs.ignore();
}

void Sched_path::show_item() const { std::cout << " - " << get_sequence() << ".  / " << get_name() << " /\n"; }