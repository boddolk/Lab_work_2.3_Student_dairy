#pragma once
#include <vector>
//#include "Res_path.h"
//#include "Sched_path.h"
//#include "Goal.h"
//#include "Note.h"
#include "functors.h"


class Student_dairy
{
private:
	std::string Res_file;
	std::string Sched_file;
	std::string Rec_file;
	std::vector<Sched_path> schedule;
	std::vector<Res_path> results;


	std::vector<std::shared_ptr<Subject>> sub_records; //  ПЕРЕРОБИТИ ПІД ЦЕЙ ОДИН
	std::vector<std::shared_ptr<Record>> records;

public:
	Student_dairy();
	Student_dairy(std::string Res_file, std::string Sched_file, std::string Rec_file);
	std::string get_res_name() const { return this->Res_file; }
	std::string get_sched_name() const { return this->Sched_file; }
	std::string get_rec_name() const { return this->Rec_file; }	

	// методи згідно умови 
	/*
	* 
	* 
	*/

	// ЗРОБИТИ ЗАПИС В ОДИН ФАЙЛ
	bool write_records_file() const; // хз чи треба два ВИПРАВИТИ
	bool write_schedule_file() const; // хз чи треба два ВИПРАВИТИ
	bool write_results_file() const; // ... ВИПРАВИТИ
	

	// ВИТЯГУВАТИ З ОДНОГО ФАЙЛУ
	//bool execute_from_files(); // тут теж хз
	bool execute_records_file(); // хз чи треба два ВИПРАВИТИ
	bool execute_schedule_file(); // хз чи треба два ВИПРАВИТИ
	bool execute_results_file(); // хз чи треба два ВИПРАВИТИ


	void show_schedule(int day) const;
	void show_results() const;
	void show_notes() const;
	void show_goals() const;

	void add_record(std::shared_ptr<Record> item); // додає нотатку або ціль в "records"
	void add_sched_item(const Sched_path& item); // хз чи треба два ВИПРАВИТИ
	void add_res_item(const Res_path& item); // хз чи треба два ВИПРАВИТИ


	void rm_note(std::string name, std::string date); // хз чи треба два ВИПРАВИТИ
	void rm_goal(std::string name, std::string date, int status); // хз чи треба два ВИПРАВИТИ 
	void rm_sched_item(int day, int sequence);
	void rm_res_item(std::string name);

	void ed_note(std::string name, std::string date, std::string new_info); // РЕДАГУЄ інформацію в нотатці
	void ed_goal(std::string name, std::string date, int status, std::string new_info); // РЕДАГУЄ інформацію в цілі
	void ed_sched_item(int day, int sequence, std::string new_name); // РЕДАГУЄ назву предмету в розкладі
	void ed_res_item(std::string name, int new_result); // РЕДАГУЄ результат екзамену



	void full_clear(); // очищує всі контейнери та файли




	/*
		Забезпечте можливість зчитування та запису даних у/з файлу(ів) з використанням потокових маніпуляцій.
		Розгляньте використання маніпуляцій для форматування введення/виведення даних.
	*/
};

