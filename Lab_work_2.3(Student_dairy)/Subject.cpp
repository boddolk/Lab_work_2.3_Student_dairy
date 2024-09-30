#include "Subject.h"

Subject::Subject()
	: uslable{ "empty" }, name{ "empty" }
{
}

Subject::Subject(std::string uslable)
	: uslable(uslable), name{ "empty" }
{
}

Subject::Subject(std::string uslable, std::string name)
	: uslable(uslable), name(name)
{
}
