#ifndef USER_HPP
#define  USER_HPP

#include <string>
using std::string;
#include <vector>
using std::vector;

class User
{
	const string name;
	const string conInf;
	const vector<string> req;
public:
	User(const string& n,const string& cI,const vector<string>r):name(n),conInf(cI),req(r) {}
	string getName()
	{
		return name;
	}
	string getConInf()
	{
		return conInf;
	}
	vector<string> getReq()
	{
		return req;
	}
};

#endif //USER_HPP