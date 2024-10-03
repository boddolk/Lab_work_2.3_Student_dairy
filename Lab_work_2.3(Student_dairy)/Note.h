#pragma once
#include "Record.h"

class Note : public Record
{
protected:
public:
	Note();
	Note(std::string name, std::string date, std::string info);
	std::string get_type() const override { return "note_t"; }
	void introduction(std::ofstream& ofs) const override { ofs << name << '\n' << date << '\n' << info << '\n'; }
	void extraction(std::ifstream& ifs) override;
	virtual void show_item() const override;
};