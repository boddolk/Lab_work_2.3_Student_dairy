#pragma once
#include <vector>
#include <algorithm>
#include "functors.h"

class Student_dairy
{
private:
	std::string Rec_file;
	std::vector<std::shared_ptr<Subject>> sub_records;
	std::vector<std::shared_ptr<Record>> records;
public:
	Student_dairy();
	Student_dairy(std::string Rec_file);
	std::string get_res_name() const { return this->Rec_file; }
	void set_file(std::string f_name) { this->Rec_file = f_name; };
	// ������ ����Ҳ�
	bool show_schedule(int day) const;
	bool show_results() const;
	bool show_notes() const;
	bool show_goals() const;
	// ��������� ����Ѳ� � ������ ����������
	void add_record(std::shared_ptr<Record> item); // ���� ������� ��� ���� � "records"
	void add_sub_record(std::shared_ptr<Subject> item);
	//��������� ������ ����Ѳ� � ��������в�
	bool rm_note(std::string name, std::string date);
	bool rm_goal(std::string name, std::string date, int status);
	bool rm_sched_item(int day, int sequence);
	bool rm_res_item(std::string name);
	// ����������� ������ ��˲� � �����������
	bool ed_note(std::string name, std::string date, std::string new_info); // �����Ӫ ���������� � �������
	bool ed_goal(std::string name, std::string date, int status); // �����Ӫ ���������� � ���
	bool ed_sched_item(int day, int sequence, std::string new_name); // �����Ӫ ����� �������� � �������
	bool ed_res_item(std::string name, int new_result); // �����Ӫ ��������� ��������
	// ����������
	bool sort_sub_container();
	// ��������
	bool clear_sub_records();
	bool clear_records();
	// ����� �� ����������� � ������ �����
	bool write_to_file() const;
	bool execute_from_file();
};