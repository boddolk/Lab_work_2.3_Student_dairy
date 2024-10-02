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


	std::vector<std::shared_ptr<Subject>> sub_records; //  ���������� ϲ� ��� ����
	std::vector<std::shared_ptr<Record>> records;

public:
	Student_dairy();
	Student_dairy(std::string Res_file, std::string Sched_file, std::string Rec_file);
	std::string get_res_name() const { return this->Res_file; }
	std::string get_sched_name() const { return this->Sched_file; }
	std::string get_rec_name() const { return this->Rec_file; }	

	// ������ ����� ����� 
	/*
	* 
	* 
	*/

	// ������� ����� � ���� ����
	bool write_records_file() const; // �� �� ����� ��� ���������
	bool write_schedule_file() const; // �� �� ����� ��� ���������
	bool write_results_file() const; // ... ���������
	

	// ���������� � ������ �����
	//bool execute_from_files(); // ��� ��� ��
	bool execute_records_file(); // �� �� ����� ��� ���������
	bool execute_schedule_file(); // �� �� ����� ��� ���������
	bool execute_results_file(); // �� �� ����� ��� ���������


	void show_schedule(int day) const;
	void show_results() const;
	void show_notes() const;
	void show_goals() const;

	void add_record(std::shared_ptr<Record> item); // ���� ������� ��� ���� � "records"
	void add_sched_item(const Sched_path& item); // �� �� ����� ��� ���������
	void add_res_item(const Res_path& item); // �� �� ����� ��� ���������


	void rm_note(std::string name, std::string date); // �� �� ����� ��� ���������
	void rm_goal(std::string name, std::string date, int status); // �� �� ����� ��� ��������� 
	void rm_sched_item(int day, int sequence);
	void rm_res_item(std::string name);

	void ed_note(std::string name, std::string date, std::string new_info); // �����Ӫ ���������� � �������
	void ed_goal(std::string name, std::string date, int status, std::string new_info); // �����Ӫ ���������� � ���
	void ed_sched_item(int day, int sequence, std::string new_name); // �����Ӫ ����� �������� � �������
	void ed_res_item(std::string name, int new_result); // �����Ӫ ��������� ��������



	void full_clear(); // ����� �� ���������� �� �����




	/*
		���������� ��������� ���������� �� ������ ����� �/� �����(��) � ������������� ��������� ����������.
		���������� ������������ ���������� ��� ������������ ��������/��������� �����.
	*/
};

