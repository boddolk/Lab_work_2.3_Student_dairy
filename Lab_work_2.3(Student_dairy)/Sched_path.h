#pragma once
#include "Subject.h"

class Sched_path : public Subject
{
protected:
	int day;
	int sequence;

public:
	Sched_path();
	Sched_path(std::string uslable);
	Sched_path(std::string uslable, std::string name, int day, int sequence);
	std::string get_type() const { return "schedule_t"; }
	void introduction(std::ofstream& ofs) const { ofs << uslable << '\n' << name << '\n' << day << '\n' << sequence << '\n'; }
	void extraction(std::ifstream& ifs);
	void show_item() const;
	int get_day() const { return this->day; }
	int get_sequence() const { return this->sequence; }
	void set_day(int day) { this->day = day; }
	void set_sequence(int sequence) { this->sequence = sequence; }
};
