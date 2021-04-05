#include <iostream>
#include "todoclasss.h"

using namespace std;

int main(int argc, char const* argv[]) // used to count the arguments and argv stores the arguments in an array
{
	TodoList tasks("list.txt");

	while (true)
	{
		tasks.read(); // reads the file items 

		if (tasks.get_count() > 0)
		{
			tasks.display();
			cout << endl;
			cout << "/////Main Menu/////" << endl;
			cout << "             " << endl;
			cout << "1) Add Task " << endl;
			cout << "2) Clear Tasks " << endl;
			cout << "3) Mark task as completed  " << endl;
			cout << "4) Unmark Task" << endl;
			cout << "5) Prioritise task" << endl;
			cout << "6) View Completed Tasks List " << endl;
			cout << "7) View Incomplted Tasks List" << endl;
			cout << "             " << endl;
			cout << "/////////////////// " << endl;
			cout << "Choice: ";



			string choice;
			getline(cin, choice);

			if (choice == "1")
			{
				tasks.add();
			}
			else if (choice == "2") {
				tasks.clear();
			}
			else if (choice == "3") {
				tasks.mrk();
			}
			else if (choice == "4")
			{
				tasks.unmrk();
			}
			else if (choice == "5") {
				tasks.setpri();
			}
			else if (choice == "6")
			{
				tasks.displaydone();
			}
			else if (choice == "7")
			{
				tasks.displaynotdone();
			} 
			else {
				break;
			}

		}

		else
			{

			cout << "make another list .." << endl; // a new list is created 
			tasks.create();

			cout << endl;

			tasks.save();
		}

	}

		return 0;
}


