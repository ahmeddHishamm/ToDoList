#include "todoclasss.h"
#include "itemclasss.h"
#include <time.h>

TodoList::TodoList()
{
	filename = nullptr;
}

TodoList::TodoList(const char* filename)
{
	this->filename = filename;
}

TodoList::~TodoList()
{
	/*null*/
}

void TodoList::read()
{
	fstream fs(filename, fstream::in);
	string line;

	list.clear();

	while (getline(fs, line))
	{
		if (line == "") continue;
		Item item(line);
		list.push_back(item);
	}

	fs.close();
}

void TodoList::display()
{
	cout << "Your Tasks are: " << endl << endl;

	const int W = 25;
	cout << "   " << setw(W) << left << "TASK" << " COMPLETED " << "\t" << " PRIORITY" << endl; 
	cout << "   " << setw(W) << left << "/////" << "////////" << "\t" <<  " /////////" << endl;

	for (int i = 0; i < list.size(); ++i)
		cout << i + 1 << ") " << setw(W) << left << list[i].text() << list[i].day() <<list[i].month() <<(list[i].is_done() ? "COMPLETED" : "") <<  list[i].get_Pri()  << endl; 
}

void TodoList::displaydone()
{
	cout << "your completed tasks are: " << endl << endl << endl; ;

	const int W = 25;
	cout << "   " << setw(W) << left << "  " << " COMPLETED " << "\t" << " PRIORITY" << endl;
	cout << "   " << setw(W) << left << "  " << "////////" << "\t" << " /////////" << endl; 
	
	for (int i = 0; i < list.size(); ++i)
		if (list[i].is_done() == 1 )
		{
			cout << i + 1 << ") " << setw(W) << left << list[i].text() << (list[i].is_done() ? "COMPLETED" : "") << list[i].get_Pri() << endl; 	
		}

}

void TodoList::displaynotdone()
{
	cout << "your incompleted tasks are: " << endl << endl << endl; ;

	const int W = 25;
	cout << "   " << setw(W) << left << "  " << " COMPLETED " << "\t" << " PRIORITY" << endl;
	cout << "   " << setw(W) << left << "  " << "////////" << "\t" << " /////////" << endl;
	
	for (int i = 0; i < list.size(); ++i)
		if (list[i].is_done() == 0)
		{
			cout << i + 1 << ") " << setw(W) << left << list[i].text() << (list[i].is_done() ? "COMPLETED" : "") << list[i].get_Pri() << endl;
		}
}


void TodoList::create()
{
	bool is_finished = false;
	int count = 1;
	string task;
	list.clear();

	while (!is_finished)
	{
		cout << "Add Task "<<count << ": ";

		getline(cin, task);
		if (task == "") is_finished = true;

		Item item(task);
		list.push_back(item);
		count++;
		addday(); 
		addmonth(); 
	}
	
}



void TodoList::save()
{
	fstream fs(filename, fstream::out);

	for (Item item : list)
	{
		if (item.text().empty()) continue;
		fs << item.text() << " " << (item.is_done() ? "true" : "false") << item.get_Pri() << endl;
	}

	fs.close();
}

int TodoList::get_count()
{
	return list.size();
}

void TodoList::addday()
{
	
	
		string day;

		cout << "input day :  ";
		getline(cin, day);
		Item item(day);

		if (day.empty()) return;

		for (char c : day) if (isalpha(c)) return;

		int index = stoi(day) - 1;
		if (index > list.size()) return;
		list[index].day();


	
}

void TodoList::addmonth()
{


	string month;

	cout << "input month :  ";
	getline(cin, month);
	Item item(month);

	if (month.empty()) return;

	for (char c : month) if (isalpha(c)) return;

	int index = stoi(month) - 1;
	if (index > list.size()) return;
	list[index].month();
	

}

void TodoList::add()
{
	int index = list.size();
	while (true)
	{
		cout << "Add Task "<<++index << ": ";

		string task;
		getline(cin, task);
		if (task == "") break;
		Item item(task);
		list.push_back(item);
		/*addday(); */
		addmonth(); 
		//-------------------------
		
	}

	save(); 
}

void TodoList::clear()
{
	list.clear();
	remove(filename);
}

//void TodoList::edit()
//{
//	
//
//
//}


void TodoList::mrk()
{
	cout << "Enter the number of the task u want to set as completed : ";

	string choice;
	getline(cin, choice);

	if (choice.empty()) return;

	for (char c : choice) if (isalpha(c)) return;

	int index = stoi(choice) - 1;
	if (index > list.size()) return;
	list[index].done();

	save();
}

void TodoList::unmrk()
{
	cout << "Enter the number of the task u want to unmark  : ";

	string choice;
	getline(cin, choice);

	if (choice.empty()) return;

	for (char c : choice) if (isalpha(c)) return;

	int index = stoi(choice) - 1;
	if (index > list.size()) return;
	list[index].undone();

	save();
}

void TodoList::setpri()
{
	cout << "Number of Task :  ";

	string choice;
	getline(cin, choice);

	if (choice.empty()) return;
	for (char c : choice) if (isalpha(c)) return;


	int index = stoi(choice) - 1;
	if (index > list.size()) return;

	cout << "Enter priority (none (0) , low (1), moderate (5)  ,critical (10) ): ";
	string priority;
	getline(cin, priority);
	if (priority == "low")
	{
		 list[index].lp(); 
		 save();
	}
	else if (priority == "moderate")
	{
		list[index].mp();
		save(); 

	}
	else if (priority == "critical") 
	{
		 list[index].hp();
		 save();

	}
	else if (priority == "none")
	{
		list[index].nop();
		save(); 
	}
	else
	{
		return;
	}

	
}

void TodoList::calendar()
{

	int year = 0; 
	int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	int mDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	string monthList[] = { "January", "February", "March", "April", "May", "June",
						"July", "August", "September", "October", "November", "December" };


	cout << "  /////////////////////////////////" << endl;
	cout << "           Calendar of year "  << endl;
	cout << " //////////////////////////////////" << endl << endl;
	int days;
	int current; 
	int y = year -1;
	current = (y + y / 4 - y / 100 + y / 400 + t[0] + 1) % 7;

	for (int i = 0; i < 12; i++)
	{
		if (i == 1)
			if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
				days = 29;
			else
				days = mDays[i];
		else
			days = mDays[i];

		cout << endl << " ////////////////////" << monthList[i] << "//////////////////" << endl;

		cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;

		int k;
		for (k = 0; k < current; k++)
			cout << "     ";

		for (int j = 1; j <= days; j++)
		{
			k++;
			cout << setw(5) << j;
			if (k > 6)
			{
				k = 0;
				cout << endl;
			}
		}

		if (k)
			cout << endl;

		current = k;
	}
}






//void TodoList::remove()
//{
//
//
//	int r_items;
//	ofstream removeFile;
//
//	removeFile.open(filename);
//	cout << "How many items do you want to remove?" << endl;
//	cin >> r_items;
//	vector <int> items;
//
//	for (int k = 1; k <= r_items; k++)
//	{
//		int item;
//		cout << "Item #" << k << " - ";
//		cin >> item;
//		if (k != item) 
//		{
//			items.push_back(item);
//		}
//	}
//
//	removeFile.close();
//	ofstream outFile(filename);
//	for (int i = 0; i < items.size(); i++)
//		outFile << items[i] << endl;
//	outFile.close();
//	save();
//
//}