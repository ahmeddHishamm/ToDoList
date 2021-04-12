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


	
	void display();
	void displaydone(); 
	void displaynotdone();
	//////////////////////////////////////////
	void create();                          
	void save();     
	void read();
	//////////////////////////////////////////
	/*void edit();*/
	void add();
	void addday(); 
	void addmonth();
	void clear();
	void mrk();
	void unmrk();
	void setpri();
	void calendar(); 


	/*void remove();*/


	int get_count();

}; 
