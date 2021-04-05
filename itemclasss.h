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

	string str_tolower(string);

public:
	Item();
	Item(string);
	~Item();

	string text();
	void done();
	void undone();
	bool is_done();
	
	/// //////////////////////////
	
	void hp();
	void mp();
	void lp();
	void nop();
	string get_Pri();
	string pri();


	bool operator==(Item&);

};
