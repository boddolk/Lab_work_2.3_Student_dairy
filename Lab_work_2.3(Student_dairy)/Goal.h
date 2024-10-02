#pragma once
#include "Record.h"

class Goal : public Record
{
protected:
	int status;

public:
	Goal();
	Goal(std::string name, std::string date, std::string info, int status);
	std::string get_type() const override { return "goal_t"; }
	void introduction(std::ofstream& ofs) const override { ofs << name << '\n' << date << '\n' << info << '\n' << status << '\n'; }
	void extraction(std::ifstream& ifs) override;
	virtual void show_item() const override;
	int get_status() const { return this->status; }
	void set_status(int status) { this->status = status; }
};

