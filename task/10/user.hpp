#ifndef USER_HPP
#define  USER_HPP

#include <string>
using std::string;

class User
{
	const string name;
	const string conInf;
	int roomNum = 0;
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
	int getRoomNum()
	{
		return roomNum;
	}
	void setRoomNum(int i)
	{
		roomNum = i;
	}
};

#endif //USER_HPP