#ifndef USER_HPP
#define  USER_HPP

#include <string>
using std::string;

class User
{
	const string name;
	const string conInf;
	int placeNum = 0;
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
	void setPlaceNum(int i)
	{
		placeNum = i;
	}
	int getPlaceNum()
	{
		return placeNum;
	}
};

#endif //USER_HPP