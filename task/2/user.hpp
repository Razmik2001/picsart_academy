#ifndef USER_HPP
#define  USER_HPP

#include <string>
#include <ctime>
 
using std::string;

class User
{
	const string name;
	const string conInf;
	const string num;
    std::time_t start = std::time(nullptr);
public:
	User(const string& n,const string& cI,const string& num):name(n),conInf(cI),num(num) {}
	string getName()
	{
		return name;
	}
	string getNum()
	{
		return num;
	}
	string getConInf()
	{
		return conInf;
	}
	long long Time()
	{
		return  std::time(nullptr) - start;
	}
};

#endif //USER_HPP