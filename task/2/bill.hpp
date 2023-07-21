#ifndef BILL_HPP
#define BILL_HPP

#include <iostream>
#include "user.hpp"
#include <fstream>

void save(const string& user, const string& bill)
    {
        std::ofstream f(user);
        f << bill;
        f.close();
    }

class Bill
{
private:
	int costPerHour;
	string price(User * u)
	{
		string s = u->getName() + "\n" + u->getConInf() + "\n";
		s += std::to_string(u->Time() * costPerHour) + "$\n";
		return s;
	}
public:
	Bill(int CPH):costPerHour(CPH) {}
	void displeyBill(User * u)
	{
		std::cout<< price(u) << std::endl;
	}
	void saveBill(User * u)
	{
		std::time_t t = std::time(nullptr);
		std::tm* now = std::localtime(&t);
		std::string s = u->getName() + "->";
 		s += std::to_string(now->tm_mday);
 		s += ".txt";
 		save(s,price(u));
	}
};

#endif