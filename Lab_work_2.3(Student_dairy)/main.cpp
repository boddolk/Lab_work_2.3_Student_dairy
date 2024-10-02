#include "menu.h"



int main()
{
	Student_dairy manual;
	
	/*if (manual.execute_records_file())
	{
		std::cout << "COOOOOOOOOOOOOOOOOOOOOOOOOOOOL\n\n";
	}
	manual.show_notes();*/


	/*std::string name = "Soooooooo important task";
	std::string date = "10.03.2024";
	std::string info = "It is necessary to identify and describe the 
	requirements of users to the information system in accordance with the task 
	variant, identify the main actors of the system and formulate options for their use.";*/


	std::string name = "Algorithms";
	std::string name2 = "Programming";
	std::string name3 = "Modeling and data executing";

	int day = 1;
	int sequence = 2;
	int sequence1 = 1;
	int sequence2 = 3;

	/*manual.add_sched_item(Sched_path(name, day, sequence));
	manual.add_sched_item(Sched_path(name2, day, sequence1));
	manual.add_sched_item(Sched_path(name3, day, sequence2));

	manual.write_schedule_file();*/


	/*if (manual.execute_schedule_file())
	{
		std::cout << "COOOOOOOOOOOOOOOOOOOOOOOOOOOOL\n\n";
	}
	manual.show_schedule(1);*/

	int score = 90;
	int score1 = 100;
	int score2 = 80;

	manual.add_res_item(Res_path(name, score));
	manual.add_res_item(Res_path(name2, score1));
	manual.add_res_item(Res_path(name3, score2));

	manual.show_results();
	int status = 0;

	/*for (int i = 0; i < 3; i++)
	{
		manual.add_record(std::make_shared<Goal>(name, date, info, status));
		manual.add_record(std::make_shared<Note>(name, date, info));
	}
	manual.show_goals();
	manual.show_notes();
	if (manual.write_records_file())
	{
		std::cout << "COOOOOOOOOOOOOOOOOOOOOOOOOOOOL\n\n";
	}*/


	return 0;
}