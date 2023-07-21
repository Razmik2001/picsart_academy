#ifndef AIRLINE_HPP
#define AIRLINE_HPP

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "user.hpp"
#include "plane.hpp"
using std::vector;
using std::string;
using std::cout;
using std::endl;
void save(const string& user, const string& order)
    {
        string s = user + ".txt";
        std::ofstream f(s); // Use std::ofstream in output mode
        f << order;
        f.close();
    }

class Airline
{
	vector<User *> user;
	vector<Plane *> plane;
public:
	void addUser(User* u)
    {
        user.push_back(u);
    }

    void addPlane(Plane* p)
    {
        plane.push_back(p);
    }
    void resorve(int userNum,const string& o,const string& de,int start,int end)
    {
    	for(const auto& i : plane)
    		{
    			if(i->isIn(o,de,start,end))
    			{
    				user[userNum - 1]->setFliNum(i->getFliNum());
    				return;
    			}
    		}
    }
    void display(int userNum)
    {
    	cout << user[userNum - 1]->getName() << endl;
    	for(const auto& i : plane)
    		{
    			if (i->getFliNum() == user[userNum - 1]->getFliNum())
    				cout << i->getInfo() << endl;
    			return ;
    		}
    }
    void aSave(int userNum)
    {
    	for(const auto& i : plane)
    		{
    			if (i->getFliNum() == user[userNum - 1]->getFliNum())
    				save(user[userNum - 1]->getName(),i->getInfo());
    			return ;
    		}
    	
    }
};

#endif