#ifndef USER_HPP
#define  USER_HPP

#include <string>
#include <ctime>
using std::string;

class User
{
	const string name;
	const string conInf;
	int parkNum = 0;
	std::time_t start;

public:
	User(string n,string cI):name(n),conInf(cI) {}
	string getName()
	{
		return name;
	}
	string getConInf()
	{
		return conInf;
	}
	void setParkNum(int i)
	{
		start = std::time(nullptr);
		parkNum = i;
	}
	int getParkNum()
	{
		return parkNum;
	}
	std::time_t getTime()
	{
		return start;
	}
};

#endif //USER_HPP