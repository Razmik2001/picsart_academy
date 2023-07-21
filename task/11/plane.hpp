#ifndef PLANE_HPP
#define PLANE_HPP

#include <string>
using std::string;

class Plane
{
	int fliNum;
	const string origin;
	const string dest;
	int date;
	int count;
public:
	Plane(int fN,int c,const string& o,const string& de,int da):fliNum(fN),origin(o),dest(de),date(da),count(c){}
	int getFliNum()
	{
		return fliNum;
	}
	int getCount()
	{
		return count;
	}
	bool isIn(const string& o,const string& de,int start,int end)
	{
		if(!(origin == o) || !(de == dest))
			return false;
		if(date < start && date > end)
			return false;
		return true;
	}
	string getInfo()
	{
		string s = "";
		s += "plane " + std::to_string(fliNum) + '\n';
		s += origin + "->" + dest + '\n';
		s += "date->" + std::to_string(date) + '\n';
		return s;
	}
};

#endif