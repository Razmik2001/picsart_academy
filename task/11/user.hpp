#ifndef USER_HPP
#define  USER_HPP

#include <string>
using std::string;

class User
{
	const string name;
	const string conInf;
	int fliNum = 0;
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
	void setFliNum(int i)
	{
		fliNum = i;
	}
	int getFliNum()
	{
		return fliNum;
	}
};

#endif //USER_HPP