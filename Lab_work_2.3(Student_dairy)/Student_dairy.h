#pragma once
#include <vector>
#include <deque>
#include "Res_path.h"
#include "Sched_path.h"
#include "Goal.h"
#include "Note.h"


class Student_dairy
{
private:
	std::string s_name;
	std::string s_surname;
	int course;
	std::deque<std::unique_ptr<Subject>> sub_items;
	std::deque<std::unique_ptr<Record>> records;
public:
	Student_dairy();
	Student_dairy(std::string s_name, std::string s_surname, int course);
	std::string get_sname() const { return this->s_name; }
	std::string get_ssurname() const { return this->s_surname; }
	int get_course() const { return this->course; }
	

	// методи згідно умови 
	/*
	* 
	* 
	*/

	void add_record(std::unique_ptr<Record> item); // додає нотатку або ціль в "records"
	void add_sub_item(std::unique_ptr<Subject > item); // додає предмет або результат в "sub_items"
	
	void rm_record(std::unique_ptr<Record> item); // видаляє нотатку або ціль з "records"
	void rm_sub_item(std::unique_ptr<Subject > item); // видаляє предмет за назвою та днем з "sub_items"
	
	void ed_record(std::unique_ptr<Record> item); // редагує нотатку або ціль в "records" ???????????????????????????????????
	void ed_sub_item(std::unique_ptr<Subject > item); // редагує предмет або бал в "sub_items"

	void full_clear(); // очищує всі контейнери та файли




	/*
		Забезпечте можливість зчитування та запису даних у/з файлу(ів) з використанням потокових маніпуляцій.
		Розгляньте використання маніпуляцій для форматування введення/виведення даних.
	*/
};

