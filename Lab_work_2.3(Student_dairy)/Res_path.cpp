#include "Res_path.h"

Res_path::Res_path()
	: Subject{ "result_lable" }, score(0)
{
}

Res_path::Res_path(std::string uslable)
	: Subject(uslable), score(0)
{
}

Res_path::Res_path(std::string uslable, std::string name, int score)
	: Subject(uslable, name), score(score)
{
}

void Res_path::show_item() const
{
	std::cout << " Subject:  < " << get_name() << " >,    Score:  / " << get_score() << " /\n\n";
}
