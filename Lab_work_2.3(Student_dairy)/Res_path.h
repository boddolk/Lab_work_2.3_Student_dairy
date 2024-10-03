#pragma once
#include "Subject.h"

class Res_path : public Subject
{
protected:
	int score;
public:
	Res_path();
	Res_path(std::string name, int score);
	std::string get_type() const override { return "result_t"; }
	void introduction(std::ofstream& ofs) const override { ofs << name << '\n' << score << '\n'; }
	void extraction(std::ifstream& ifs) override;
	void show_item() const override;
	int get_score() const { return this->score; }
	void set_score(int score) { this->score = score; }
};