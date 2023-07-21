#ifndef SYS_HPP
#define SYS_HPP

#include "expTre.hpp"
#include <vector>
#include <fstream>
using std::vector;

void save(const std::string& user, const std::string& info) {
    std::string s = user + ".txt";
    std::ofstream f(s);
    f << info;
    f.close();
}

class sys
{
	const string userName;
	vector<Expense *> ex;
public:
	sys(const string& name):userName(name){}
	void addExp(Expense * e)
	{
		ex.push_back(e);
	}
	void display()
	{
		std::cout << userName << std::endl;
		for(const auto& i: ex)
		{
			i->display();
		}
	}
	void display(const string& type)
	{
		std::cout << userName << std::endl;
		for(const auto& i: ex)
		{
			if (i->getType() == type)
			{
				i->display();
			}
		}
	}
	void saveExp()
	{
		string s = "";
		for(const auto& i: ex)
		{
			s += i->getInfo();
		}
		save(userName,s);
	}
	void saveExp(const string& type)
	{
		string s = "";
		for(const auto& i: ex)
		{	
			if (i->getType() == type)
			{
				s += i->getInfo();
			}
		}
		save(userName + type,s);
	}
};

#endif