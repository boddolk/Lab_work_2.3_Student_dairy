#include "Note.h"

Note::Note()
	:Record{}
{
}

Note::Note(std::string name, std::string date, std::string info)
	:Record(name, date, info)
{
}

void Note::extraction(std::ifstream& ifs)
{
	std::getline(ifs, name);
	std::getline(ifs, date);
	std::getline(ifs, info);
//	ifs.ignore();
}

void Note::show_item() const
{
	std::cout << "< " << get_date() << " >\n";
	std::cout << " / " << get_name() << " /\n";
	std::cout << " << " << get_info() << " >>\n\n";
}
