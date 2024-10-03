#include "Goal.h"

Goal::Goal()
	:Record{}, status(0)
{}

Goal::Goal(std::string name, std::string date, std::string info, int status)
	:Record(name, date, info), status(status == 0 || status == 1 ? status : 0)
{}

void Goal::extraction(std::ifstream& ifs)
{
	std::getline(ifs, name);
	std::getline(ifs, date);
	std::getline(ifs, info);
	ifs >> status;
	ifs.ignore();
}

void Goal::show_item() const
{
	std::cout << "< " << get_date() << " >   --   <<< ";
	if (get_status() == 0)
		std::cout << "NOT COMPLETED >>>\n";
	if (get_status() == 1)
		std::cout << "COMPLETED >>>\n";
	std::cout << " / " << get_name() << " /\n";
	std::cout << " << " << get_info() << " >>\n\n";
}