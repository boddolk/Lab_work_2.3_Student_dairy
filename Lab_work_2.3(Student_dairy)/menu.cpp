#include "menu.h"

menu::menu()
	:manual(), name{ "empty" }, file_name{"empty"}, day(0), sequence(0), score(0), status(0), choice(0)
{
}

void menu::general_choice()
{
	system("cls");
	std::cout << "     <<     GENERAL MENU     >>\n\n";
	std::cout << "( 1 ) Exam results; \n";
	std::cout << "( 2 ) Schedule; \n";
	std::cout << "( 3 ) Records; \n";
	std::cout << "( 4 ) Recording files; \n";
	std::cout << "     ( 0 ) Exit; \n";

	try
	{
		std::cin >> choice;
		if (std::cin.fail())
			throw - 1;
	}
	catch (int)
	{
		system("cls");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
		std::cin.get();
	}
}

void menu::schedule_actions()
{
	do
	{
		system("cls");
		std::cout << "     <<     GENERAL MENU     >>\n\n";
		std::cout << "( 1 ) Add schedule records; \n";
		std::cout << "( 2 ) Show schedule; \n";
		std::cout << "( 3 ) Delete subject path; \n";
		std::cout << "( 4 ) Edit schedule path; \n";
		std::cout << "( 5 ) Clear schedule container; \n";
		std::cout << "     ( 0 ) Exit; \n";

		try
		{
			std::cin >> choice;
			if (std::cin.fail())
				throw - 1;
		}
		catch (int)
		{
			system("cls");
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
			std::cin.get();
		}

		switch (choice)
		{
		case 1:
			system("cls");
			std::cout << "  Enter count of records: ";
			std::cin >> count;
			std::cin.ignore();
			
			for (int i = 0; i < count; i++)
			{
				std::cout << "<< CHOOCE DAY >>\n";
				std::cout << "( 1 ) Monday; \n";
				std::cout << "( 2 ) Tursday; \n";
				std::cout << "( 3 ) Wednesday; \n";
				std::cout << "( 4 ) Thursday; \n";
				std::cout << "( 5 ) Friday; \n";

				try
				{
					std::cin >> day;
					if (std::cin.fail() || day < 0 || day > 5)
						throw - 1;
					std::cin.ignore();
				}
				catch (int)
				{
					system("cls");
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
					std::cin.get();
				}

				std::cout << "<< ENTER SUBJECT >>\n";
				try
				{
					std::getline(std::cin, name);
					if (std::cin.fail())
						throw - 1;
					std::cin.ignore();
				}
				catch (int)
				{
					system("cls");
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
					std::cin.get();
				}

				std::cout << "<< ENTER SEQUENCE >>\n";
				try
				{
					std::cin >> sequence;
					if (std::cin.fail() || sequence < 0 || sequence > 7)
						throw - 1;
					std::cin.ignore();
				}
				catch (int)
				{
					system("cls");
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
					std::cin.get();
				}

				manual.add_sched_item(Sched_path(name, day, sequence));
			}
			break;
		case 2:
			std::cout << "<< CHOOCE DAY >>\n";
			std::cout << "( 1 ) Monday; \n";
			std::cout << "( 2 ) Tursday; \n";
			std::cout << "( 3 ) Wednesday; \n";
			std::cout << "( 4 ) Thursday; \n";
			std::cout << "( 5 ) Friday; \n";

			try
			{
				std::cin >> day;
				if (std::cin.fail() || day < 0 || day > 5)
					throw - 1;
				std::cin.ignore();
			}
			catch (int)
			{
				system("cls");
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
				std::cin.get();
			}
			manual.show_schedule(day);
			break;
		case 3:
			std::cout << "<< CHOOCE DAY >>\n";
			std::cout << "( 1 ) Monday; \n";
			std::cout << "( 2 ) Tursday; \n";
			std::cout << "( 3 ) Wednesday; \n";
			std::cout << "( 4 ) Thursday; \n";
			std::cout << "( 5 ) Friday; \n";

			try
			{
				std::cin >> day;
				if (std::cin.fail() || day < 0 || day > 5)
					throw - 1;
				std::cin.ignore();
			}
			catch (int)
			{
				system("cls");
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
				std::cin.get();
			}

			std::cout << "<< ENTER SEQUENCE >>\n";
			try
			{
				std::cin >> sequence;
				if (std::cin.fail() || sequence < 0 || sequence > 7)
					throw - 1;
				std::cin.ignore();
			}
			catch (int)
			{
				system("cls");
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cerr << "   INVALID   INPUT, TRY AGAIN\n";
				std::cin.get();
			}


			manual; // тут метод ремуву
			break;
		case 4:
			break;
		case 5:
			break;
		}

	} while (choice != 0);

}
