#pragma once
#include "Subject.h"

class Sched_path : public Subject
{
protected:
	int day;
	int sequence;
public:
	Sched_path();
	Sched_path(std::string name, int day, int sequence);
	std::string get_type() const override { return "schedule_t"; }
	void introduction(std::ofstream& ofs) const override { ofs << name << '\n' << day << '\n' << sequence << '\n'; }
	void extraction(std::ifstream& ifs) override;
	void show_item() const override;
	int get_day() const { return this->day; }
	int get_sequence() const { return this->sequence; }
	void set_day(int day) { this->day = day; }
	void set_sequence(int sequence) { this->sequence = sequence; }
};