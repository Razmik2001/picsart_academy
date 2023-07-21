#ifndef USER_HPP
#define  USER_HPP

#include <string>
using std::string;

class User
{
	const string name;
	const string conInf;
	int tubNum = 0;
public:
	User(const &string n,const &string cI):name(n),conInf(cI) {}
	string getName()
	{
		return name;
	}
	string getConInf()
	{
		return conInf;
	}
	void setTubNum(int i)
	{
		tubNum = i;
	}
	int getTubNum()
	{
		return tubNum;
	}
};

#endif //USER_HPP