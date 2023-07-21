#ifndef BANK_HPP
#define BANK_HPP

#include "blood.hpp"
#include "user.hpp"
#include <fstream>
#include <vector>
using std::vector;
void save(const string& user, const string& o)
    {
        string s = user + ".txt";
        std::ofstream f(s);
        f << o;
        f.close();
    }

class Bank
{
	Blood blood;
	vector<User *> user;
public:
	void addUser(User *u)
    {
        user.push_back(u);
    }
    void addBlood(int userNum,int size)
    {
    	blood.addBlood(user[userNum -1]->getBloodType(),size);
    }
    void subBlood(int userNum,int size)
    {
    	blood.subBlood(user[userNum -1]->getBloodType(),size);
    }
    void status()
    {
    	std::cout << blood.getInfo();
    }
    void bSave()
    {
    	save("Bank",blood.info());
    }
};

#endif