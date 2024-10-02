#pragma once
#include <iostream>
#include <fstream>
#include <string>
class Record
{
protected:
	std::string name;
	std::string date;
	std::string info;

public:
	Record();
	Record(std::string name, std::string date, std::string info);
	virtual std::string get_type() const = 0;
	virtual void introduction(std::ofstream& ofs) const = 0;
	virtual void extraction(std::ifstream& ifs) = 0;
	virtual void show_item() const = 0;
	std::string get_name() const { return this->name; }
	std::string get_date() const { return this->date; }
	std::string get_info() const { return this->info; }
	void set_name(std::string name) { this->name = name; }
	void set_date(std::string date) { this->date = date; }
	void set_info(std::string info) { this->info = info; }
};

