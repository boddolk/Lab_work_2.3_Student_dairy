#include "Sched_path.h"

Sched_path::Sched_path()
	: Subject{ "schedule_lable" }, day(0), sequence(0)
{
}

Sched_path::Sched_path(std::string uslable)
	: Subject(uslable), day(0), sequence(0)
{
}

Sched_path::Sched_path(std::string uslable, std::string name, int day, int sequence)
	: Subject(uslable, name), day(day), sequence(sequence)
{
}

void Sched_path::extraction(std::ifstream& ifs)
{
	std::getline(ifs, uslable);
	std::getline(ifs, name);
	ifs >> day;
	ifs.ignore();
	ifs >> sequence;
	ifs.ignore();
}

void Sched_path::show_item() const
{
	std::cout << " - " << get_sequence() << ".  / " << get_name() << " /\n";
}
