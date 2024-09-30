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
	

	// ������ ����� ����� 
	/*
	* 
	* 
	*/

	void add_record(std::unique_ptr<Record> item); // ���� ������� ��� ���� � "records"
	void add_sub_item(std::unique_ptr<Subject > item); // ���� ������� ��� ��������� � "sub_items"
	
	void rm_record(std::unique_ptr<Record> item); // ������� ������� ��� ���� � "records"
	void rm_sub_item(std::unique_ptr<Subject > item); // ������� ������� �� ������ �� ���� � "sub_items"
	
	void ed_record(std::unique_ptr<Record> item); // ������ ������� ��� ���� � "records" ???????????????????????????????????
	void ed_sub_item(std::unique_ptr<Subject > item); // ������ ������� ��� ��� � "sub_items"

	void full_clear(); // ����� �� ���������� �� �����




	/*
		���������� ��������� ���������� �� ������ ����� �/� �����(��) � ������������� ��������� ����������.
		���������� ������������ ���������� ��� ������������ ��������/��������� �����.
	*/
};

