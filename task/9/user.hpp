#ifndef USER_HPP
#define  USER_HPP

#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
using std::string;

void save(const std::string& user, const std::string& info) {
    string s = user + ".txt";
    std::ofstream f(s);
    f << info;
    f.close();
}

struct fit
{
	unsigned int gym = 12;
	unsigned int pool = 6;
	unsigned int massag = 1;
};

class User
{
	const string name;
	const string conInf;
	const string type;
	fit f;
public:
	User(const string& n,const string& cI,const string& t):name(n),conInf(cI),type(t) {
		if(type == "prem")
		{
			f.gym = 24;
			f.massag  = 2;
			f.pool = 12;
		} 
		else if (type == "all")
		{
			f.gym = -1;
			f.massag  = -1;
			f.pool = -1;
		}
	}
	void goPool()
	{
		if (f.pool > 0)
			f.pool --;
		else
			std::cerr << "sold out";
	}
	void goMassag()
	{
		if (f.massag > 0)
			f.massag --;
		else
			std::cerr << "sold out";
	}
	void goGym()
	{
		if (f.gym > 0)
			f.gym --;
		else
			std::cerr << "sold out";
	}
	string report()
	{
		if(type == "all")
			return "forever here";
		string s = "gym" + std::to_string(f.gym) + "\n"; 
		s += "massag" + std::to_string(f.massag) + "\n"; 
		s += "pool" + std::to_string(f.pool) + "\n"; 
		return s;
	}
	string getName()
	{
		return name;
	}
	string getType()
	{
		return type;
	}
	string getConInf()
	{
		return conInf;
	}
	void display()
	{
		std::cout << report() <<std::endl;
	}
	void uSave()
	{
		std::time_t t = std::time(nullptr);	
    	std::tm* now = std::localtime(&t);
    	std::string month = std::to_string(now->tm_mon + 1);
		save(name + month,report());
	}
};

#endif //USER_HPP