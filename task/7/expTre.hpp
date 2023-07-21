
#ifndef EXPTRE_HPP
#define EXPTRE_HPP

#include <iostream>
#include <string>
#include <ctime>
using std::string;

class Expense
{
	int amount;
	const string desc;
	string data;
	const string type;

public:
	Expense(int amount, const string& desc, const string& ty)
		: amount(amount), desc(desc), type(ty)
	{
		std::time_t t = std::time(nullptr);
		std::tm* now = std::localtime(&t);
		std::string s = std::to_string(now->tm_mday);
		data = s;
	}

	string getType()
	{
		return type;
	}

	string getInfo()
	{
		return desc + "  " + std::to_string(amount) + "$   |" + data + '\n';
	}

	void display()
	{
		std::cout << getInfo();
	}
};
#endif