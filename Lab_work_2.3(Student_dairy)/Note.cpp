#include "Note.h"

Note::Note()
	:Record{ "note_lable" }
{
}

Note::Note(std::string uslable)
	:Record(uslable)
{
}

Note::Note(std::string uslable, std::string name, std::string date, std::string info)
	:Record(uslable, name, date, info)
{
}

void Note::extraction(std::ifstream& ifs)
{
	std::getline(ifs, uslable);
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
