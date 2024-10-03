#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Subject
{
protected:
	std::string name;
public:
	Subject();
	Subject(std::string name);
	virtual  std::string get_type() const = 0;
	virtual void introduction(std::ofstream& ofs) const = 0;
	virtual void extraction(std::ifstream& ifs) = 0;
	virtual void show_item() const = 0;
	std::string get_name() const { return this->name; }
	void set_name(std::string name) { this->name = name; }
};