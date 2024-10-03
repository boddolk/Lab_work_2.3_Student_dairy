#pragma once
#include "Sched_path.h"
#include "Res_path.h"
#include "Note.h"
#include "Goal.h"
class S_for_Sched
{
private:
	int day;
	int sequence;

public:
	S_for_Sched(int day, int sequence) :day(day), sequence(sequence) {}
	bool operator()(const std::shared_ptr<Subject>& a)
	{
		if (a->get_type() == "schedule_t")
		{
			auto Nptr = std::dynamic_pointer_cast<Sched_path>(a);
			if (Nptr->get_day() == day && Nptr->get_sequence() == sequence)
				return true;
		}
		return false;
	}
};
class So_for_sub_r
{
private:
public:
	So_for_sub_r() {}
	bool operator()(const std::shared_ptr<Subject>& a, const std::shared_ptr<Subject>& b)
	{
		if (a->get_type() == "result_t" && b->get_type() == "result_t")
		{
			auto fptr = std::dynamic_pointer_cast<Res_path>(a);
			auto sptr = std::dynamic_pointer_cast<Res_path>(b);
			return fptr->get_score() > sptr->get_score();
		}
	}
};
class S_for_Res
{
private:
	std::string name;
public:
	S_for_Res(std::string name)	:name(name)	{}
	bool operator()(const std::shared_ptr<Subject>& a)
	{
		if (a->get_type() == "result_t" && a->get_name() == name)
			return true;
		return false;
	}
};
class S_for_Note
{
private:
	std::string name;
	std::string date;
public:
	S_for_Note(std::string name, std::string date) :name(name), date(date) {}
	bool operator()(const std::shared_ptr<Record>& a)
	{
		if (a->get_type() == "note_t" && a->get_name() == name && a->get_date() == date)
			return true;
		return false;
	}
};
class S_for_Goal
{
private:
	std::string name;
	std::string date;
	int status;
public:
	S_for_Goal(std::string name, std::string date, int status)	:name(name), date(date), status(status)	{}
	bool operator()(const std::shared_ptr<Record>& a)
	{
		if (a->get_type() == "goal_t" && a->get_name() == name && a->get_date() == date)
		{
			auto Nptr = std::dynamic_pointer_cast<Goal>(a);
			if (Nptr->get_status() == status)
				return true;
		}
		return false;
	}
};