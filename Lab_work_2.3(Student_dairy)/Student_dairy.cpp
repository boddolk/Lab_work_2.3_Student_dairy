#include "Student_dairy.h"

Student_dairy::Student_dairy()
	:Res_file{ "Result_file" }, Sched_file{ "Schedule_file" }, Rec_file{ "Record_file"}

{
}

Student_dairy::Student_dairy(std::string Res_file, std::string Sched_file, std::string Rec_file)
	:Res_file(Res_file), Sched_file(Sched_file), Rec_file(Rec_file)
{
}

void Student_dairy::show_schedule(int day) const
{
    if (day > 0 && day < 6 && !schedule.empty())
    {
        switch (day)
        {
        case 1:
            std::cout << " <<      Monday      >>\n\n";
            break;
        case 2:
            std::cout << " <<      Tuesday      >>\n\n";
            break;
        case 3:
            std::cout << " <<      Wednesday      >>\n\n";
            break;
        case 4:
            std::cout << " <<      Thursday      >>\n\n";
            break;
        case 5:
            std::cout << " <<      Friday      >>\n\n";
            break;
        }

        for (int i = 1; i < 5; i++)
        {
            for (const auto& item : this->schedule)
            {
                if (item.get_day() == day && item.get_sequence() == i) // іншааа
                {
                    item.show_item();
                }
            }
        }
    }
    else throw - 1;
}

void Student_dairy::show_results() const
{
    if (!results.empty())
    {
        for (const auto& item : this->results)
        {
            item.show_item();
        }
    }
}

void Student_dairy::show_notes() const
{
    if (!records.empty())
    {
        for (const auto& item : this->records)
        {
            if (item->get_type() == "note_t")
                item->show_item();
        }
    }
}

void Student_dairy::show_goals() const
{
    if (!records.empty())
    {
        for (const auto& item : this->records)
        {
            if (item->get_type() == "goal_t")
                item->show_item();
        }
    }
}

void Student_dairy::add_record(std::shared_ptr<Record> item)
{
    if (item != nullptr)
        records.push_back(item);
}

void Student_dairy::add_sched_item(const Sched_path& item)
{
    this->schedule.push_back(item);
}

void Student_dairy::add_res_item(const Res_path& item)
{
    this->results.push_back(item);
}

void Student_dairy::rm_note(std::string name, std::string date)
{
    if (!records.empty())
    {
        std::vector<std::shared_ptr<Record>>::iterator it = std::find(records.begin(), records.end(), S_for_Note(name, date));
        if (it == records.end())
        {
            records.erase(it);
        }
    }
}

void Student_dairy::rm_goal(std::string name, std::string date, int status)
{
    std::vector<std::shared_ptr<Record>>::iterator it = std::find(records.begin(), records.end(), S_for_Goal(name, date, status));
    if (it == records.end())
    {
        records.erase(it);
    }
}

void Student_dairy::rm_sched_item(int day, int sequence)
{
    std::vector<Sched_path>::iterator it = std::find(schedule.begin(), schedule.end(), S_for_Sched(day, sequence));
    if (it == schedule.end())
    {
        schedule.erase(it);
    }
}

void Student_dairy::rm_res_item(std::string name)
{
    std::vector<Res_path>::iterator it = std::find(results.begin(), results.end(), S_for_Res(name));
    if (it == results.end())
    {
        results.erase(it);
    }
}

void Student_dairy::ed_note(std::string name, std::string date, std::string new_info)
{
    if (!records.empty())
    {
        std::vector<std::shared_ptr<Record>>::iterator it = std::find(records.begin(), records.end(), S_for_Note(name, date));
        if (it == records.end())
        {
            if (auto No = std::dynamic_pointer_cast<Note>(*it))
            {
                No->set_info(new_info);
            } else throw - 1;
        }
    }
}

void Student_dairy::ed_goal(std::string name, std::string date, int status, std::string new_info)
{
    if (!records.empty())
    {
        std::vector<std::shared_ptr<Record>>::iterator it = std::find(records.begin(), records.end(), S_for_Goal(name, date, status));
        if (it == records.end())
        {
            if (auto Go = std::dynamic_pointer_cast<Goal>(*it))
            {
                Go->set_info(new_info);
            }
            else throw - 1;
        }
    }
}

void Student_dairy::ed_sched_item(int day, int sequence, std::string new_name)
{
    if (!sub_records.empty())
    {
        std::vector<std::shared_ptr<Subject>>::iterator it = std::find(sub_records.begin(), sub_records.end(), S_for_Sched(day, sequence));
        if (it == sub_records.end())
        {
            if (auto Sch = std::dynamic_pointer_cast<Sched_path>(*it))
            {
                Sch->set_name(new_name);
            }
            else throw - 1;
        }
    }
}

void Student_dairy::ed_res_item(std::string name, int new_result)
{
    if (!sub_records.empty())
    {
        std::vector<std::shared_ptr<Subject>>::iterator it = std::find(sub_records.begin(), sub_records.end(), S_for_Res(name));
        if (it == sub_records.end())
        {
            if (auto Re = std::dynamic_pointer_cast<Res_path>(*it))
            {
                Re->set_score(new_result);
            }
            else throw - 1;
        }
    }
}



void Student_dairy::full_clear()
{
    /*if (!records.empty())
        records.clear();
    if (!results.empty())
        results.clear();
    if (!schedule.empty())
        results.clear();*/

    // зачистити файли
}

bool Student_dairy::write_records_file() const
{
    std::ofstream ofs(Rec_file);
    if (!ofs)
    {
        std::cerr << "Error opening file for writing!" << std::endl;
        throw - 1;
    }
    if (!records.empty())
    {
        for (const auto& item : this->records)
        {
            ofs << item->get_type() << '\n'; // Спочатку записуємо тип об'єкта
            item->introduction(ofs);
        }
    }

    return true;
}

bool Student_dairy::write_schedule_file() const
{
    std::ofstream ofs(Sched_file);
    if (!ofs)
    {
        std::cerr << "Error opening file for writing!" << std::endl;
        throw - 1;
    }
    if (!schedule.empty())
    {
        for (const auto& item : this->schedule)
        {
            item.introduction(ofs);
        }
    }

    return true;
}

bool Student_dairy::write_results_file() const
{
    std::ofstream ofs(Res_file);
    if (!ofs)
    {
        std::cerr << "Error opening file for writing!" << std::endl;
        throw - 1;
    }
    if (!results.empty())
    {
        for (const auto& item : this->results)
        {
            item.introduction(ofs);
        }
    }

    return true;
}

bool Student_dairy::execute_records_file()
{
    std::ifstream ifs_rec(this->Rec_file);
    if (!ifs_rec)
    {
        std::cerr << "Error opening records file for writing!" << std::endl;
        throw - 1;
    }

    std::string type;
    while (std::getline(ifs_rec, type))
    {
        std::shared_ptr<Record> item1;
        if (type == "note_t") { item1 = std::make_shared<Note>(); }
        else if (type == "goal_t") { item1 = std::make_shared<Goal>(); }

        if (item1)
        {
            item1->extraction(ifs_rec);
            records.push_back(item1);
        }
    }

    return true;
}

bool Student_dairy::execute_schedule_file()
{
    std::ifstream ifs_sched(this->Sched_file);
    if (!ifs_sched)
    {
        std::cerr << "Error opening schedule file for writing!" << std::endl;
        throw - 1;
    }
    while (ifs_sched)
    {
        Sched_path item2;
        item2.extraction(ifs_sched);
        schedule.push_back(item2);
    }

    return true;
}

bool Student_dairy::execute_results_file()
{
    std::ifstream ifs_res(this->Res_file);
    if (!ifs_res)
    {
        std::cerr << "Error opening results file for writing!" << std::endl;
        throw - 1;
    }
    while (ifs_res)
    {
        Res_path item3;
        item3.extraction(ifs_res);
        results.push_back(item3);
    }

    return true;
}
