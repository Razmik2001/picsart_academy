#ifndef DEL_HPP
#define DEL_HPP

#include <iostream>
#include <string>
using std::string;

class Del
{
	const string item;
	const string origin;
	const string dest;
	int dTime;
public:
	Del(const string& i,const string& o,const string& d,int dt):item(i),origin(o),dest(d),dTime(dt){
		std::cout<< item <<" prep\n";
	}
	~Del()
	{
		std::cout << item <<" del\n";
	}
	string getInfo()
	{
		string s = "Item -> " + item;
		s += "\nfrom " + origin + " to " + dest;
		s += "\nestimated delivery time" + std::to_string(dTime);
		s += "\ndisp\n";
		return s;
	}
};

#endif