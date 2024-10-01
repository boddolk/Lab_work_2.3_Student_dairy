#pragma once
#include "Subject.h"

class Res_path : public Subject
{
protected:
	int score;

public:
	Res_path();
	Res_path(std::string uslable);
	Res_path(std::string uslable, std::string name, int score);
	std::string get_type() const { return "result_t"; }
	void introduction(std::ofstream& ofs) const { ofs << uslable << '\n' << name << '\n' << score << '\n'; }
	void extraction(std::ifstream& ifs);
	void show_item() const;
	int get_score() const { return this->score; }
	void set_score(int score) { this->score = score; }
};

