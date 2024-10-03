#include "Record.h"

Record::Record()
	: name{ "empty" }, date{ "00.00.0000" }, info{ "empty" }
{}

Record::Record(std::string name, std::string date, std::string info)
	: name(name), date(date), info(info)
{}