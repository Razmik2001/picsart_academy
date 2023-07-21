#ifndef ORDER_HPP
#define ORDER_HPP
#include <fstream>
#include <iostream>
#include "rest.hpp"
#include "user.hpp"

void save(const std::string& user, int bill) {
    std::string s = user + ".txt";
    std::ofstream f(s);
    f << bill << "$\n";
    f.close();
}

class Order
{
	User user;
	int bill = 0;
public:
	Order(const User& u):user(u) {std::cout << "preparing" << std::endl;}
	~Order(){std::cout << "delivered" << std::endl;}
	void addOrder(const string& name,Rest &r)
	{
		bill += r.find(name);
	}
	void display()
	{
		std::cout << user.getName() << std::endl << bill << "$\n";
		std::cout << "dispatched" << std::endl;
	}
	void orSave()
	{
		save(user.getName(),bill);
	}
};

#endif