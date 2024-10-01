#pragma once
#include "Record.h"

class Goal : public Record
{
protected:
	int status;

public:
	Goal();
	Goal(std::string uslable);
	Goal(std::string uslable, std::string name, std::string date, std::string info, int status);
	std::string get_type() const { return "goal_t"; }
	void introduction(std::ofstream& ofs) const { ofs << uslable << '\n' << name << '\n' << date << '\n' << info << '\n' << status << '\n'; }
	void extraction(std::ifstream& ifs);
	virtual void show_item() const;
	int get_status() const { return this->status; }
	void set_status(int status) { this->status = status; }
};

