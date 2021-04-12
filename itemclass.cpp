#include "itemclasss.h"
#include "todoclasss.h"
#include <iostream>



Item::Item()
{
	_text = "";
	_done = false;
	_day = "";
	_month = ""; 

}

Item::Item(string item)
{
	int startf = item.find("false");
	int startt = item.find("true");
	string str;
	/*string day; 
	string month;*/

	if (startf > -1 && startt == -1) // item has false
	{
		str = item.substr(0, startf - 1);
	
		_done = false;
	}
	else if (startt > -1 && startf == -1) { // item has true
		str = item.substr(0, startt - 1);
	
		_done = true;
	}
	else if (startf == -1 && startt == -1) { // item is user input (not true or false)
		str = item;
		_done = false;
	}

	_text = str;
	/*_day = day; 
	_month = month; */

	
}

Item::~Item()
{
	// destructor 
}


string Item::text()
{
	return _text; // returns the line text 
}

void Item::done()
{
	_done = true;
}

void Item::undone()
{
	_done = false;
}

string Item::day()
{
	return _day ;
}

string Item::month()
{
	return _month; 
}


bool Item::is_done()
{
	return _done; //this marks task as done 
}

void Item::hp()
{
	_pri = "10";
	cout << "high priority is set " << endl; 
}

void Item::mp()
{
	_pri = "5";
	cout << "meduim priority is set" << endl; 
}

void Item::lp()
{
	 _pri = "1";
	 cout << "low priority is set" << endl; 
}

void Item::nop()
{
	_pri = "0";
	cout << "no priority is set" << endl; 

}


string Item::get_Pri()
{
	string p;

	if (_pri == " ")
	{
		p = "";
	}
	else if (_pri == "1")
	{
		p = "low";
	}
	else if (_pri == "5")
	{
		p = "moderate";
	}
	else if (_pri == "10")
	{
		p = "critical";
	}
	return p;

}

string Item::pri()
{
	return _pri; 
}



string Item::str_tolower(string str) //this changes the text to lwrcase 
{
	string temp = str;

	for (int i = 0; i < temp.size(); ++i)

		temp[i] = tolower(temp[i]);
	return temp;
}

bool Item::operator==(Item& other)
{
	// (==) helps compare the object text to other object of same type also compares lwrcased text to each other 
	bool text_equal = str_tolower(_text) == str_tolower(other.text());
	bool done_equal = _done == other.is_done();
	return text_equal && done_equal;
}