#pragma once
#include <iostream>
#include <string>
class Record
{
protected:
	std::string uslable;
	std::string name;
	std::string date;
	std::string info;
public:
	Record();
	Record(std::string uslable);
	Record(std::string uslable, std::string name, std::string date, std::string info);
	virtual void show_item() const = 0;
	std::string get_uslable() const { return this->uslable; }
	std::string get_name() const { return this->name; }
	std::string get_date() const { return this->date; }
	std::string get_info() const { return this->info; }
	void set_uslable(std::string uslable) { this->uslable = uslable; }
	void set_name(std::string name) { this->name = name; }
	void set_date(std::string date) { this->date = date; }
	void set_info(std::string info) { this->info = info; }
};

