#ifndef USER_HPP
#define  USER_HPP

#include <string>
using std::string;

class User
{
	const string name;
	const string conInf;
	const string paySys;
public:
	User(const string &n,const string &cI,const string &pS):name(n),conInf(cI),paySys(pS) {}
	string getName()
	{
		return name;
	}
	string getConInf()
	{
		return conInf;
	}
	string getPaySys()
	{
		return paySys;
	}
};

#endif //USER_HPP