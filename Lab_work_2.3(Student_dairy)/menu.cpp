#include "menu.h"

menu::menu()
	:manual(), file_name{ "empty" }, date{ "00.00.0000" }, name{ "empty" }, info{ "empty" }, new_info{ "empty" }, day(0), sequence(0), score(0), new_score(0), status(0), choice(0), count(0)
{}

void menu::set_file_name()
{
	std::cout << "<< Enter your DEFAULT file name:    ";
	try {
		std::getline(std::cin, file_name);
		if (std::cin.fail())
			throw - 1;
	}
	catch (int) {
		system("cls");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
		std::cin.get();
	}
}

void menu::set_date()
{
	std::cout << "<< Enter date( Format: ´ dd.mm.yyyy ª ):    ";
	std::getline(std::cin, date);
	if (std::cin.fail())
		throw - 1;
	if (date.length() != 10)
		throw - 1;
	for (int i = 0; i < date.length(); ++i)
	{
		if ((i == 2 || i == 5))
		{
			if (date[i] != '.')
				throw - 1;
		}
		else if (!std::isdigit(date[i])) {
			throw - 1;
		}
	}
	int day = std::stoi(date.substr(0, 2));
	int month = std::stoi(date.substr(3, 2));
	int year = std::stoi(date.substr(6, 4));
	if (month < 1 || month > 12)
		throw - 1;
	if (day < 1 || day > 31)
		throw - 1;
}

void menu::set_name(std::string type_name)
{
	if (type_name == "subject")
	{
		std::cout << "<< Enter subject name:    ";
	}
	else if (type_name == "record")
		std::cout << "<< Enter record name:    ";
	try	{
		std::getline(std::cin, name);
		if (std::cin.fail())
			throw - 1;
	}
	catch (int)	{
		system("cls");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
		std::cin.get();
	}
}

void menu::set_new_name()
{
	std::cout << "<< Enter NEW subject name:    ";
	try	{
		std::getline(std::cin, name);
		if (std::cin.fail())
			throw - 1;
	}
	catch (int)	{
		system("cls");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
		std::cin.get();
	}
}

void menu::set_info()
{
	std::cout << "<< Enter record info:    ";
	try	{
		std::getline(std::cin, info);
		if (std::cin.fail())
			throw - 1;
	}
	catch (int)	{
		system("cls");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
		std::cin.get();
	}
}

void menu::set_new_info()
{
	std::cout << "<< Enter NEW record info:    ";
	try	{
		std::getline(std::cin, new_info);
		if (std::cin.fail())
			throw - 1;
	}
	catch (int)	{
		system("cls");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
		std::cin.get();
	}
}

void menu::set_day()
{
	std::cout << "( 1 ) Monday; \n";
	std::cout << "( 2 ) Tursday; \n";
	std::cout << "( 3 ) Wednesday; \n";
	std::cout << "( 4 ) Thursday; \n";
	std::cout << "( 5 ) Friday; \n";
	std::cout << "<< Choose day:  ";
	try	{
		std::cin >> day;
		if (std::cin.fail() || day < 0 || day > 5)
			throw - 1;
		std::cin.ignore();
	}
	catch (int)	{
		system("cls");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
		std::cin.get();
	}
}

void menu::set_sequence()
{
	std::cout << "<< Enter sequnce( 1 - 7 ):    "; 
	try {
		std::cin >> sequence;
		if (std::cin.fail() || sequence < 0 || sequence > 7)
			throw - 1;
		std::cin.ignore();
	}
	catch (int) {
		system("cls");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
		std::cin.get();
	}
}

void menu::set_score()
{
	std::cout << "<< Enter score( 0 - 100 ):    ";
	try {
		std::cin >> score;
		if (std::cin.fail() || score < 0 || score > 100)
			throw - 1;
		std::cin.ignore();
	}
	catch (int)	{
		system("cls");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
		std::cin.get();
	}
}

void menu::set_new_score()
{
	std::cout << "<< Enter NEW score( 0 - 100 ):    ";
	try	{
		std::cin >> new_score;
		if (std::cin.fail() || new_score < 0 || new_score > 100)
			throw - 1;
		std::cin.ignore();
	}
	catch (int)	{
		system("cls");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
		std::cin.get();
	}
}

void menu::set_status()
{
	std::cout << "( 0 ) Do not complete; \n";
	std::cout << "( 1 ) Complete; \n";
	std::cout << "<< Choose status:  ";
	try	{
		std::cin >> status;
		if (std::cin.fail() || status < 0 || status > 1)
			throw - 1;
		std::cin.ignore();
	}
	catch (int)	{
		system("cls");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
		std::cin.get();
	}
}

void menu::set_choice()
{
	std::cout << "<< Enter choice:    ";
	try	{
		std::cin >> choice;
		if (std::cin.fail())
			throw - 1;
		std::cin.ignore();
	}
	catch (int)	{
		system("cls");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
		std::cin.get();
	}
}

void menu::set_count()
{
	std::cout << "<< Enter count of records:    ";
	try	{
		std::cin >> count;
		if (std::cin.fail())
			throw - 1;
		std::cin.ignore();
	}
	catch (int)	{
		system("cls");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
		std::cin.get();
	}
}

void menu::general_choice()
{
	system("cls");
	std::cout << "     <<     GENERAL MENU     >>\n\n";
	std::cout << "( 1 ) Exam results; \n";
	std::cout << "( 2 ) Schedule; \n";
	std::cout << "( 3 ) Records; \n";
	std::cout << "( 4 ) Containers; \n";
	std::cout << "( 5 ) Recording file; \n";
	std::cout << "     ( 0 ) Exit; \n";
	this->set_choice();
}

void menu::schedule_actions()
{
	do	{
		system("cls");
		std::cout << "    <<     SCHEDULE MENU     >>\n\n";
		std::cout << "( 1 ) Add schedule records; \n";
		std::cout << "( 2 ) Show schedule; \n";
		std::cout << "( 3 ) Delete subject path; \n";
		std::cout << "( 4 ) Edit schedule path; \n";
		std::cout << "     ( 0 ) Exit; \n";
		this->set_choice();
		switch (choice)		{
		case 1:	system("cls");
			this->set_count();
			for (int i = 0; i < count; i++)
			{
				system("cls");
				this->set_day();
				this->set_name("subject");
				this->set_sequence();
				try {
					manual.add_sub_record(std::make_shared<Sched_path>(name, day, sequence));
				}
				catch (int)				{
					system("cls");
					std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
				}
			}
			break;
		case 2:	system("cls");
			this->set_day();
			system("cls");
			std::cout << "    << SCHEDULE >>\n";
			if (!manual.show_schedule(day))
				std::cout << "\n   SCHEDULE IS EMPTY\n";
			break;
		case 3:	system("cls");
			this->set_day();
			this->set_sequence();
			if(!manual.rm_sched_item(day, sequence))
				std::cout << "\n   PATH IS NOT FOUND\n";
			break;
		case 4:	system("cls");
			this->set_day();
			this->set_sequence();
			this->set_new_name();
			manual.ed_sched_item(day, sequence, name);
			break;
		case 0:	system("cls");
			break;
		}
		if (choice != 0)
		{
			std::cout << "\n\nENTER SOME KEY TO CONTINUE...\n";
			std::cin.get();
		}

	} while (choice != 0);
}

void menu::results_actions()
{
	do	{
		system("cls");
		std::cout << "    <<     RESULTS MENU     >>\n\n";
		std::cout << "( 1 ) Add result records; \n";
		std::cout << "( 2 ) Show results; \n";
		std::cout << "( 3 ) Delete result path; \n";
		std::cout << "( 4 ) Edit result path; \n";
		std::cout << "     ( 0 ) Exit; \n";
		this->set_choice();
		switch (choice)		{
		case 1:	system("cls");
			this->set_count();
			for (int i = 0; i < count; i++)
			{
				system("cls");
				this->set_name("subject");
				this->set_score();
				try {
					manual.add_sub_record(std::make_shared<Res_path>(name, score)); // ƒŒƒ¿“» ¬» Àﬁ◊≈ÕÕﬂ œ–» ƒŒƒ¿¬¿ÕÕ≤
				}
				catch (int)	{
					system("cls");
					std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
				}
			}
			break;
		case 2:	system("cls");
			std::cout << "   << RESULTS >>\n";
			if (!manual.show_results())
				std::cout << "\n   RESULTS IS EMPTY\n";
			break;
		case 3:	system("cls");
			this->set_name("subject");
			if (!manual.rm_res_item(name))
				std::cout << "\n   PATH IS NOT FOUND\n";
			break;
		case 4:	system("cls");
			this->set_name("subject");
			this->set_new_score();
			manual.ed_res_item(name, new_score);
			break;
		case 0:	system("cls");
			break;
		}
		if (choice != 0)
		{
			std::cout << "\n\nENTER SOME KEY TO CONTINUE...\n";
			std::cin.get();
		}

	} while (choice != 0);
}

void menu::records_actions()
{
	do	{
		system("cls");
		std::cout << "    <<     RECORDS MENU     >>\n\n";
		std::cout << "( 1 ) Add NOTE; \n";
		std::cout << "( 2 ) Add GOAL; \n\n";
		std::cout << "( 3 ) Show NOTES; \n";
		std::cout << "( 4 ) Show GOALS; \n\n";
		std::cout << "( 5 ) Delete NOTE; \n";
		std::cout << "( 6 ) Delete GOAL; \n\n";
		std::cout << "( 7 ) Edit NOTE path; \n";
		std::cout << "( 8 ) Edit GOAL STATUS; \n";
		std::cout << "     ( 0 ) Exit; \n";
		this->set_choice();
		switch (choice)	{
		case 1:	system("cls");
			this->set_count();
			for (int i = 0; i < count; i++)
			{
				try {
					system("cls");
					this->set_date();
					this->set_name("record");
					this->set_info();
					manual.add_record(std::make_shared<Note>(name, date, info));
				}
				catch (int)	{
					system("cls");
					std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
					std::cin.get();
					continue;
				}
			}
			break;
		case 2:	system("cls");
			this->set_count();
			for (int i = 0; i < count; i++)
			{
				system("cls");
				try {
					this->set_date();
					this->set_name("record");
					this->set_info();
					this->set_status();
					manual.add_record(std::make_shared<Goal>(name, date, info, status));
				}
				catch (int)	{
					system("cls");
					std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
					std::cin.get();
					continue;
				}
			}
			break;
		case 3:	system("cls");
			std::cout << "        << NOTES >>\n\n";
			if (!manual.show_notes())
				std::cout << "\n   NOTES IS EMPTY\n";
			break;
		case 4:	system("cls");
			std::cout << "        << GOALS >>\n\n";
			if (!manual.show_goals())
				std::cout << "\n   GOALS IS EMPTY\n";
			break;
		case 5:	system("cls");
			try {
				this->set_date();
				this->set_name("record");
				if (!manual.rm_note(name, date))
					std::cout << "\n   PATH IS NOT FOUND\n";
			}
			catch (int)	{
				system("cls");
				std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
				std::cin.get();
			}
			
			break;
		case 6:	system("cls");
			try {
				this->set_date();
				this->set_name("record");
				this->set_status();
				if (!manual.rm_goal(name, date, status))
					std::cout << "\n   PATH IS NOT FOUND\n";
			}
			catch (int)	{
				system("cls");
				std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
				std::cin.get();
			}			
			break;
		case 7:	system("cls");
			try {
				this->set_date();
				this->set_name("record");
				this->set_new_info();
				manual.ed_note(name, date, new_info);
			}
			catch (int)	{
				system("cls");
				std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
				std::cin.get();
			}			
			break;
		case 8:	system("cls");
			try {
				this->set_date();
				this->set_name("record");
				this->set_status();
				manual.ed_goal(name, date, status);
			}
			catch (int)	{
				system("cls");
				std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
				std::cin.get();
			}			
			break;
		case 0:	system("cls");
			std::cout << "   EXIT TO GENERAL\n\n";
			break;
		}
		if (choice != 0)
		{
			std::cout << "\n\nENTER SOME KEY TO CONTINUE...\n";
			std::cin.get();
		}

	} while (choice != 0);
}

void menu::containers_actions()
{
	do	{
		system("cls");
		std::cout << "    <<     CONTAINERS MENU     >>\n\n";
		std::cout << "( 1 ) Clear subj_records container; \n";
		std::cout << "( 2 ) Clear records container; \n";
		std::cout << "( 3 ) Sort subj_records container ; \n";
		std::cout << "     ( 0 ) Exit; \n";
		this->set_choice();

		switch (choice)
		{
		case 1:	system("cls");
			manual.clear_sub_records();
			break;
		case 2:	system("cls");
			manual.clear_records();
			break;
		case 3:	system("cls");
			manual.sort_sub_container();
			break;
		case 0:	system("cls");
			break;
		}
		if (choice != 0)
		{
			std::cout << "\n\nENTER SOME KEY TO CONTINUE...\n";
			std::cin.get();
		}

	} while (choice != 0);
}

void menu::refile_actions()
{
	do {
		system("cls");
		std::cout << "       <<     FILE MENU     >>\n\n";
		std::cout << "( 1 ) Edit file name; \n";
		std::cout << "( 2 ) Save chagges; \n";
		std::cout << "( 3 ) Repeat execute; \n";
		std::cout << "     ( 0 ) Exit; \n";
		this->set_choice();
		switch (choice)	{
		case 1:	system("cls");
			this->set_file_name();
			manual.set_file(file_name);
			break;
		case 2:	system("cls");
			manual.write_to_file();
			break;
		case 3:	system("cls");
			manual.execute_from_file();
			break;
		case 0:	system("cls");
			break;
		}
		if (choice != 0)
		{
			std::cout << "\n\nENTER SOME KEY TO CONTINUE...\n";
			std::cin.get();
		}

	} while (choice != 0);
}

void menu::start()
{
	this->set_file_name();
	manual.set_file(file_name);
	if (manual.execute_from_file())
	{
		std::cout << "\n   <<<   READING COMPLEETE   >>>";
	} else
		std::cout << "\n   <<<   FILE DOES NOT EXIST!   >>>";
	
	std::cout << "\n\nENTER SOME KEY TO CONTINUE...\n";
	std::cin.get();
	do {
		this->general_choice();
		switch (choice)
		{
		case 1: this->results_actions();
			choice = -1;
			break;
		case 2: this->schedule_actions();
			choice = -1;
			break;
		case 3: this->records_actions();
			choice = -1;
			break;
		case 4: this->containers_actions();
			choice = -1;
			break;
		case 5:
			this->refile_actions();
			choice = -1;
			break;
		case 0: std::cout << "   EXIT THE PROGRAM\n\n";
			break;
		default:
			break;
		}
		if (choice != 0 && choice != -1)
		{
			std::cout << "\n\nENTER SOME KEY TO CONTINUE...\n";
			std::cin.get();
		}

	} while (choice != 0);
}