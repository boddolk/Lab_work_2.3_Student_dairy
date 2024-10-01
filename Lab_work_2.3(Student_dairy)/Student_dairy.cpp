#include "Student_dairy.h"

Student_dairy::Student_dairy()
	:Sub_file{ "Subject_file" }, Rec_file{ "Record_file"}

{
}

Student_dairy::Student_dairy(std::string Sub_file, std::string Rec_file)
	:Sub_file(Sub_file), Rec_file(Rec_file)
{
}

void Student_dairy::show_schedule(int day) const
{
    if (day > 0 && day < 6 && !sub_items.empty())
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
            for (const auto& item : this->sub_items)
            {
                if (item->get_type() == "schedule_t")
                {
                    auto sched = std::dynamic_pointer_cast<Sched_path>(item);
                    if (sched->get_day() == day && sched->get_sequence() == i)
                    {
                        item->show_item();
                    }
                // Sched_path temp;// переробити цю залупу ???????????????????????????????????????????????????
                }
            }
        }
    }
    else throw - 1;
}

void Student_dairy::show_results() const
{
    if (!sub_items.empty())
    {
        for (const auto& item : this->records)
        {
            if (item->get_type() == "result_t")
                item->show_item();
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

void Student_dairy::add_sub_item(std::shared_ptr<Subject> item)
{
    if (item != nullptr)
        sub_items.push_back(item);
}

void Student_dairy::full_clear()
{
    if (!records.empty())
        records.clear();
    if (!sub_items.empty())
        sub_items.clear();

    // зачистити файли
}

bool Student_dairy::write_to_file(std::string file_name) const
{
	std::ofstream ofs(file_name);
	if (!ofs) 
    {
		std::cerr << "Error opening file for writing!" << std::endl;
		return;
	}

	if (file_name == this->get_sub_name())
	{
		for (const auto& item : this->sub_items) 
        {
			ofs << item->get_type() << '\n'; // Спочатку записуємо тип об'єкта
			item->introduction(ofs);
		}
	}
	if (file_name == this->get_rec_name())
	{
		for (const auto& item : this->records) 
        {
			ofs << item->get_type() << '\n'; // Спочатку записуємо тип об'єкта
			item->introduction(ofs);
		}
	}

	return false;
}

bool Student_dairy::execute_from_files()
{
    std::ifstream ifs_rec(this->Rec_file);
    if (!ifs_rec) 
    {
        std::cerr << "Error opening records file for writing!" << std::endl;
        return;
    }
    std::ifstream ifs_sub(this->Sub_file);
    if (!ifs_sub)
    {
        std::cerr << "Error opening subjects file for writing!" << std::endl;
        return;
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

    while (std::getline(ifs_sub, type))
    {
        std::shared_ptr<Subject> item2;
        if (type == "schedule_t") { item2 = std::make_shared<Sched_path>(); }
        else if (type == "result_t") { item2 = std::make_shared<Res_path>(); }

        if (item2)
        {
            item2->extraction(ifs_sub);
            sub_items.push_back(item2);
        }
    }

	return false;
}
