#ifndef USER_HPP
#define  USER_HPP

#include <string>
using std::string;

class User
{
	const string name;
	const string conInf;
	int Bloodtype;
public:
	User(string n,string cI,int b):name(n),conInf(cI),Bloodtype(b) {}
	string getName()
	{
		return name;
	}
	string getConInf()
	{
		return conInf;
	}
	int getBloodType()
	{
		return Bloodtype;
	}
};

#endif //USER_HPP