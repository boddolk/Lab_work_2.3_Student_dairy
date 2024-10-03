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
	// ÂÈÂÎÄÈ ÏÓÍÊÒ²Â
	bool show_schedule(int day) const;
	bool show_results() const;
	bool show_notes() const;
	bool show_goals() const;
	// ÄÎÄÀÂÀÍÍß ÇÀÏÈÑ²Â Â ÎÁÈÄÂÀ ÊÎÍÒÅÉÍÅĞÈ
	void add_record(std::shared_ptr<Record> item); // äîäàº íîòàòêó àáî ö³ëü â "records"
	void add_sub_record(std::shared_ptr<Subject> item);
	//ÂÈÄÀËÅÍÍß ÏÅÂÍÈÕ ÇÀÏÈÑ²Â Ç ÊÎÍÒÅÉÍÅĞ²Â
	bool rm_note(std::string name, std::string date);
	bool rm_goal(std::string name, std::string date, int status);
	bool rm_sched_item(int day, int sequence);
	bool rm_res_item(std::string name);
	// ĞÅÄÀÃÓÂÀÍÍß ÏÅÂÍÈÕ ÏÎË²Â Ó ÊÎÍÒÅÉÍÅĞÀÕ
	bool ed_note(std::string name, std::string date, std::string new_info); // ĞÅÄÀÃÓª ³íôîğìàö³ş â íîòàòö³
	bool ed_goal(std::string name, std::string date, int status); // ĞÅÄÀÃÓª ³íôîğìàö³ş â ö³ë³
	bool ed_sched_item(int day, int sequence, std::string new_name); // ĞÅÄÀÃÓª íàçâó ïğåäìåòó â ğîçêëàä³
	bool ed_res_item(std::string name, int new_result); // ĞÅÄÀÃÓª ğåçóëüòàò åêçàìåíó
	// ÑÎĞÒÓÂÀÍÍß
	bool sort_sub_container();
	// Î×ÈÙÅÍÍß
	bool clear_sub_records();
	bool clear_records();
	// ÇÀÏÈÑ ÒÀ ÂÈÒßÃÓÂÀÍÍß Ç ÎÄÍÎÃÎ ÔÀÉËÓ
	bool write_to_file() const;
	bool execute_from_file();
};