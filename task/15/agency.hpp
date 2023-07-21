#ifndef AGENCY_HPP
#define AGENCY_HPP

#include <iostream>
#include <fstream>
#include <vector>
using std::vector;
#include "place.hpp"
#include "user.hpp"
void save(const string& user, const string& o)
    {
        string s = user + ".txt";
        std::ofstream f(s);
        f << o;
        f.close();
    }
class Agency
{
	vector<User *> user;
	vector<Place *> place;
public:
	void addUser(User* u)
    {
        user.push_back(u);
    }

    void addPlace(Place* p)
    {
        place.push_back(p);
    }
    void resorv(int userNum,int p,const string& de)
    {
    	int count = 1;
    	for(const auto& i : place)
    		{
    			if(i->isIn(p,de))
    			{
    				user[userNum - 1]->setPlaceNum(count);
    				i->reserv();
    				std::cout << user[userNum - 1]->getName()<< '\n';
    				std::cout << i->getInfo();
    				return;
    			}
    			count++;
    		}
    }
    void placeSave(int placenum)
    {
    	save(place[placenum - 1]->getDest(),place[placenum - 1]->getInfo());
    }
};

#endif