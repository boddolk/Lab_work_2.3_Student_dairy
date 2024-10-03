#include "Student_dairy.h"

Student_dairy::Student_dairy()
	:Rec_file{ "Student_dairy_file" }
{}

Student_dairy::Student_dairy(std::string Res_file)
	:Rec_file(Res_file)
{}
// ÂÈÂÎÄÈ
bool Student_dairy::show_schedule(int day) const
{
    bool n = false;
    if (day > 0 && day < 6 && !sub_records.empty())
    {
        switch (day)
        {
        case 1: std::cout << "\n <<      Monday      >>\n\n";
            break;
        case 2: std::cout << "\n <<      Tuesday      >>\n\n";
            break;
        case 3: std::cout << "\n <<      Wednesday      >>\n\n";
            break;
        case 4: std::cout << "\n <<      Thursday      >>\n\n";
            break;
        case 5: std::cout << "\n <<      Friday      >>\n\n";
            break;
        }

        for (int i = 1; i <= 7; i++)
        {
            for (const auto& item : this->sub_records)
            {
                if (item->get_type() == "schedule_t")
                {
                    auto Sche = std::dynamic_pointer_cast<Sched_path>(item);
                    if (Sche->get_day() == day && Sche->get_sequence() == i)
                    {
                        n = true;
                        Sche->show_item();
                    }
                }
            }
        }
    }
    return n;
}

bool Student_dairy::show_results() const
{
    bool n = false;
    if (!sub_records.empty())
    {
        for (const auto& item : this->sub_records)
        {
            if (item->get_type() == "result_t")
            {
                n = true;
                item->show_item();
            }
        }
    }
    return n;
}

bool Student_dairy::show_notes() const
{
    bool n = false;
    if (!records.empty())
    {
        for (const auto& item : this->records)
        {
            if (item->get_type() == "note_t")
            {
                item->show_item();
                n = true;
            }
        }
    }
    return n;
}

bool Student_dairy::show_goals() const
{
    bool n = false;
    if (!records.empty())
    {
        for (const auto& item : this->records)
        {
            if (item->get_type() == "goal_t")
            {
                item->show_item();
                n = true;
            }
        }
    }
    return n;
}
// ÄÎÄÀÂÀÍÍß
void Student_dairy::add_record(std::shared_ptr<Record> item)
{
    if (item != nullptr)
    {
        if (std::find(records.begin(), records.end(), item) == records.end())
            records.push_back(item);
    }
}

void Student_dairy::add_sub_record(std::shared_ptr<Subject> item)
{
    if (item != nullptr)
    {
        if (std::find(sub_records.begin(), sub_records.end(), item) == sub_records.end())
            sub_records.push_back(item);
    }
}
// ÂÈÄÀËÅÍÍß
bool Student_dairy::rm_note(std::string name, std::string date)
{
    if (!records.empty())
    {
        std::vector<std::shared_ptr<Record>>::iterator it = std::find_if(records.begin(), records.end(), S_for_Note(name, date));
        if (it != records.end())
        {
            records.erase(it);
            return true;
        }
    }
    return false;
}

bool Student_dairy::rm_goal(std::string name, std::string date, int status)
{
    if (!records.empty())
    {
        std::vector<std::shared_ptr<Record>>::iterator it = std::find_if(records.begin(), records.end(), S_for_Goal(name, date, status));
        if (it != records.end())
        {
            records.erase(it);
            return true;
        }
    }
    return false;
}

bool Student_dairy::rm_sched_item(int day, int sequence)
{
    if (!sub_records.empty())
    {
        std::vector<std::shared_ptr<Subject>>::iterator it = std::find_if(sub_records.begin(), sub_records.end(), S_for_Sched(day, sequence));
        if (it != sub_records.end())
        {
            sub_records.erase(it);
            return true;
        }
    }
    return false;
}

bool Student_dairy::rm_res_item(std::string name)
{
    if (!sub_records.empty())
    {
        std::vector<std::shared_ptr<Subject>>::iterator it = std::find_if(sub_records.begin(), sub_records.end(), S_for_Res(name));
        if (it != sub_records.end())
        {
            sub_records.erase(it);
            return true;
        }
    }
    return false;
}
// ĞÅÄÀÃÓÂÀÍÍß
bool Student_dairy::ed_note(std::string name, std::string date, std::string new_info)
{
    if (!records.empty())
    {
        std::vector<std::shared_ptr<Record>>::iterator it = std::find_if(records.begin(), records.end(), S_for_Note(name, date));
        if (it != records.end())
        {
            auto No = std::dynamic_pointer_cast<Note>(*it);
            No->set_info(new_info);
            return true;
        }
    }
    return false;
}

bool Student_dairy::ed_goal(std::string name, std::string date, int status)
{
    if (!records.empty())
    {
        std::vector<std::shared_ptr<Record>>::iterator it = std::find_if(records.begin(), records.end(), S_for_Goal(name, date, status));
        if (it != records.end())
        {
            auto Go = std::dynamic_pointer_cast<Goal>(*it);
            Go->set_status(Go->get_status() == 0 ? 1 : 0);
            return true;
        }
    }
    return false;
}

bool Student_dairy::ed_sched_item(int day, int sequence, std::string new_name)
{
    if (!sub_records.empty())
    {
        std::vector<std::shared_ptr<Subject>>::iterator it = std::find_if(sub_records.begin(), sub_records.end(), S_for_Sched(day, sequence));
        if (it != sub_records.end())
        {
            auto Sch = std::dynamic_pointer_cast<Sched_path>(*it);
            Sch->set_name(new_name);
            return true;
        }
    }
    return false;
}

bool Student_dairy::ed_res_item(std::string name, int new_result)
{
    if (!sub_records.empty())
    {
        std::vector<std::shared_ptr<Subject>>::iterator it = std::find_if(sub_records.begin(), sub_records.end(), S_for_Res(name));
        if (it != sub_records.end())
        {
            auto Re = std::dynamic_pointer_cast<Res_path>(*it);
            Re->set_score(new_result);
            return true;
        }
    }
    return false;
}

bool Student_dairy::sort_sub_container()
{
    if (!sub_records.empty())
    {
        std::sort(sub_records.begin(), sub_records.end(), So_for_sub_r());
        return true;
    }
    return false;
}

bool Student_dairy::clear_sub_records()
{
    if (!sub_records.empty())
    {
        this->sub_records.clear();
        return true;
    }
    return false;
}

bool Student_dairy::clear_records()
{
    if (!records.empty())
    {
        this->records.clear();
        return true;
    }
    return false;
}
// ÇÀÏÈÑ ÄÎ ÔÀÉËÓ
bool Student_dairy::write_to_file() const
{
    std::ofstream ofs(Rec_file);
    if (!ofs)
        return false;

    if (!records.empty())
    {
        for (const auto& item : this->records)
        {
            ofs << item->get_type() << '\n';
            item->introduction(ofs);
        }
    }
    if (!sub_records.empty())
    {
        for (const auto& item2 : this->sub_records)
        {
            ofs << item2->get_type() << '\n';
            item2->introduction(ofs);
        }
    }
    return true;
}
// ÂÈÒßÃÓÂÀÍÍß Ç ÔÀÉËÓ
bool Student_dairy::execute_from_file()
{
    std::ifstream ofs(this->Rec_file);
    if (!ofs)
        return false;

    this->clear_sub_records();
    this->clear_records();

    std::string type;
    while (std::getline(ofs, type))
    {
        std::shared_ptr<Record> item1;
        std::shared_ptr<Subject> item2;

        if (type == "note_t") { item1 = std::make_shared<Note>(); }
        else if (type == "goal_t") { item1 = std::make_shared<Goal>(); }
        else if (type == "schedule_t") { item2 = std::make_shared<Sched_path>(); }
        else if (type == "result_t") { item2 = std::make_shared<Res_path>(); }

        if (type == "note_t" || type == "goal_t") 
        {
            item1->extraction(ofs);
            records.push_back(item1);
        } else if (type == "schedule_t" || type == "result_t") 
        {
            item2->extraction(ofs);
            sub_records.push_back(item2);
        }
    }
    return true;
}