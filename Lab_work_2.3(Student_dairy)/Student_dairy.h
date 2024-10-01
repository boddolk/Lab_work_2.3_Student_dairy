#pragma once
#include <vector>
#include <deque>
#include <memory>
#include "Res_path.h"
#include "Sched_path.h"
#include "Goal.h"
#include "Note.h"


class Student_dairy
{
private:
	std::string Sub_file;
	std::string Rec_file;
	std::vector<std::shared_ptr<Subject>> sub_items;
	std::vector<std::shared_ptr<Record>> records;
public:
	Student_dairy();
	Student_dairy(std::string Sub_file, std::string Rec_file);
	std::string get_sub_name() const { return this->Sub_file; }
	std::string get_rec_name() const { return this->Rec_file; }	

	// методи згідно умови 
	/*
	* 
	* 
	*/
	bool write_to_file(std::string file_name) const; // хз чи треба два
	bool execute_from_files(); // тут теж хз

	void show_schedule(int day) const;
	void show_results() const;
	void show_notes() const;
	void show_goals() const;

	void add_record(std::shared_ptr<Record> item); // додає нотатку або ціль в "records"
	void add_sub_item(std::shared_ptr<Subject> item); // додає предмет або результат в "sub_items"
	
	void rm_record(std::string date, std::string name); // видаляє нотатку або ціль з "records"
	void rm_sub_item(std::string name, /*продумати*/); // видаляє предмет за назвою та днем з "sub_items"
	
	void ed_record(std::shared_ptr<Record> item); // редагує нотатку або ціль в "records" ???????????????????????????????????
	void ed_sub_item(std::shared_ptr<Subject > item); // редагує предмет або бал в "sub_items"

	void full_clear(); // очищує всі контейнери та файли




	/*
		Забезпечте можливість зчитування та запису даних у/з файлу(ів) з використанням потокових маніпуляцій.
		Розгляньте використання маніпуляцій для форматування введення/виведення даних.
	*/
};

