#include "Record.h"

Record::Record()
	: uslable{ "empty" }, name{ "empty" }, date{ "00.00.0000" }, info{ "empty" }
{
}

Record::Record(std::string uslable)
	: uslable(uslable), name{"empty"}, date{"00.00.0000"}, info{"empty"}
{
}

Record::Record(std::string uslable, std::string name, std::string date, std::string info)
	: uslable(uslable), name(name), date(date), info(info)
{
}
