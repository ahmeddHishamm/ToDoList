#pragma once
#include <string>
#include <cctype>

using namespace std;

class Item
{
private:
	string _text;
	bool _done;
	string _pri; 
	string _day; 
	string _month; 

	string str_tolower(string);

public:
	Item();
	Item(string);
	~Item();

	string text();
	string day(); 
	string month(); 
	bool is_done();
	
	/////////////////////////////
	void undone();	
	void done();
	/// //////////////////////////
	
	void hp();
	void mp();
	void lp();
	void nop();

	
	/////////////////////////////////
	
	string get_Pri();
	string pri();


	bool operator==(Item&);

};
