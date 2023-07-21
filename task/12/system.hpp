#ifndef  SYSTEM_HPP
#define  SYSTEM_HPP

#include <vector>
#include "user.hpp"
#include "table.hpp"
#include <fstream>
#include <iostream>

using std::cout;
using std::endl;
void save(const string& user, const string& order)
    {
        string s = user + ".txt";
        std::ofstream f(s); // Use std::ofstream in output mode
        f << order;
        f.close();
    }
class System
{
	std::vector<Table *> tables;
	std::vector<User *> users;  
public:
	void addTable(Table *t)
	{
		tables.push_back(t);
	}
	void addUser(User *u)
	{
		users.push_back(u);
	}
	void reserve(int userNumber,int capacity)
	{
		int count = 1;
		for(const auto& i :tables)
		{
			if(i->getCapacity() <= capacity && i->getStatus())
			{
				users[userNumber - 1]->setTubNum(count);
				i->reserv();
			}
			count ++;
		}
	}
	void free(int userNumber)
	{
		int i = users[userNumber - 1]->getTubNum();
		tables[i - 1]->free();
		users[userNumber - 1]->setTubNum(0);
	}
	void sSave(int userNumber)
	{
		string s = "Table -> " + std::to_string(users[userNumber - 1]->getTubNum()) + "\n";
		int i = users[userNumber - 1]->getTubNum();
		s+= std::to_string(i) + "\n";
		save( users[userNumber - 1]->getName(),s);
	}
};
#endif 