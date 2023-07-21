#ifndef FITNES_HPP
#define FITNES_HPP

#include <vector>
#include "user.hpp"
class Fitnes
{
	std::vector<User *> user;
public:
	void goGym(int userNum)
	{
		user[userNum - 1]->goGym();
	}
	void goMassag(int userNum)
	{
		user[userNum - 1]->goMassag();
	}
	void goPool(int userNum)
	{
		user[userNum - 1]->goPool();
	}
	void addUser(User *u)
	{
		user.push_back(u);
	}
	void display()
	{
		for(const auto& i: user)
		{
			std::cout << i->getName() << std::endl;
			i->display();
		}
	}
	void display(const string& name)
	{
		for(const auto& i: user)
		{	
			if (i->getName() == name)
			{
				std::cout << name << std::endl;
				i->display();
				return;
			}
		}
	}
	void fSave()
	{
		for(const auto& i: user)
		{
			i->uSave();
		}
	}void fSave(const string& name)
	{
		for(const auto& i: user)
		{	
			if (i->getName() == name)
			{
				i->uSave();
				return;
			}
		}
	}
};

#endif