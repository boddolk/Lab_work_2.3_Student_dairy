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
	S_for_Sched(int day, int sequence)
		:day(day), sequence(sequence)
	{}
	bool operator()(const Sched_path& a)
	{
		if (a.get_day() == day && a.get_sequence() == sequence)
		{
			return true;
		}
		return false;
	}
};


class S_for_Res
{
private:
	std::string name;

public:
	S_for_Res(std::string name)
		:name(name)
	{}
	bool operator()(const Res_path& a)
	{
		if (a.get_name() == name)
		{
			return true;
		}
		return false;
	}
};


class S_for_Note
{
private:
	std::string name;
	std::string date;

public:
	S_for_Note(std::string name, std::string date)
		:name(name), date(date)
	{}
	bool operator()(const std::shared_ptr<Record>& a)
	{
		if (a->get_type() == "note_t" && a->get_name() == name && a->get_date() == date)
		{
			return true;
		}
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
	S_for_Goal(std::string name, std::string date, int status)
		:name(name), date(date), status(status)
	{}
	bool operator()(const std::shared_ptr<Record>& a)
	{
		if (a->get_type() == "goal_t" && a->get_name() == name && a->get_date() == date)
		{
			auto Nptr = std::dynamic_pointer_cast<Goal>(a);
			if (Nptr->get_status() == status)
			{
				return true;
			}
		}
		return false;
	}
};