#ifndef SYS_HPP
#define SYS_HPP

#include <iostream>
#include "user.hpp"
#include "job.hpp"

class sys
{
	vector<Job *> job;
	vector<User*> users;
public:
    void addUser(User* u)
    {
        users.push_back(u);
    }
    void addJob(Job *j)
    {
    	job.push_back(j);
    	for(const auto&i: users)
    	{
    		if(j->isIn(i->getReq()))
    		{
    			std::cout<<"find job for "<< i->getName() << '\n';
    		}
    	}
    }
    void find(int userNum,const string& str)
    {
    	std::cout<<"job for"<<users[userNum -1]->getName() << '\n';
    	for(const auto& i: job)
    	{
    		if (str == i->getTitle()|| str == i->getDesc()|| str == i->getComp())
    		{
    			std::cout << i->getInfo();
    		}
    	}
    	std::cout<< "\n\n\n";
    }
    void find(int userNum,int salary)
    {
    	std::cout<<"job for"<<users[userNum -1]->getName() << '\n';
    	for(const auto& i: job)
    	{
    		if (salary <= i->getSalary())
    		{
    			std::cout << i->getInfo();
    		}
    	}
    	std::cout<< "\n\n\n";
    }
    void find(int userNum,vector<string> r)
    {
    	std::cout<<"job for"<<users[userNum -1]->getName() << '\n';
    	for(const auto& i: job)
    	{
    		if (i->isIn(r))
    		{
    			std::cout << i->getInfo();
    		}
    	}
    	std::cout<< "\n\n\n";
    }
};

#endif