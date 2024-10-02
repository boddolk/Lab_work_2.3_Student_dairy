#include "Res_path.h"

Res_path::Res_path()
	: Subject(), score(0)
{
}

Res_path::Res_path(std::string name, int score)
	: Subject(name), score(score)
{
}

void Res_path::extraction(std::ifstream& ifs)
{
	std::getline(ifs, name);
	ifs >> score;
	ifs.ignore();
}

void Res_path::show_item() const
{
	std::cout << " Subject:  < " << get_name() << " >    Score:  / " << get_score() << " /\n\n";
}
