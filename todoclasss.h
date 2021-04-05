#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include "itemclasss.h"

using namespace std;

class TodoList
{
private:

	const char* filename;
	vector<Item> list;



public:
	TodoList();
	TodoList(const char*);
	~TodoList();


	void read();
	void display();
	void displaydone(); 
	void displaynotdone();
	//////////////////////////////////////////
	void create();                          
	void save();                           
	//////////////////////////////////////////
	/*void edit();*/
	void add();
	void clear();
	void mrk();
	void unmrk();
	void setpri();

	


	/*void remove();*/


	int get_count();

}; 
