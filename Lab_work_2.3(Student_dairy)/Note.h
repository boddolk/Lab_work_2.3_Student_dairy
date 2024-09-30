#pragma once
#include "Record.h"

class Note : public Record
{
protected:
	// without arguments
public:
	Note();
	Note(std::string uslable);
	Note(std::string uslable, std::string name, std::string date, std::string info);
	virtual void show_item() const;
};

