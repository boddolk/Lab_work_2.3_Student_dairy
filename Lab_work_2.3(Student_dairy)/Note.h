#pragma once
#include "Record.h"

class Note : public Record
{
protected:
	// without arguments
public:
	Note();
	Note(std::string uslable);
	Note(std::string uslable, std::string name, std::string date, std::string info);
	std::string get_type() const { return "note_t"; }
	void introduction(std::ofstream& ofs) const { ofs << uslable << '\n' << name << '\n' << date << '\n' << info << '\n'; }
	void extraction(std::ifstream& ifs);
	virtual void show_item() const;
};

