#ifndef HOTEL_HPP
#define HOTEL_HPP

#include "user.hpp"
#include "room.hpp"
#include <vector>
#include <fstream>
#include <iostream>

void save(const string& user, const string& RN)
    {
        string s = user + ".txt";
        std::ofstream f(s); // Use std::ofstream in output mode
        f << RN << '\n';
        f.close();
    }

using std::vector;

class Hotel
{
	vector<User *> user;
	vector<Room *> room;
public:
	void addUser(User* u)
    {
        user.push_back(u);
    }
    void addRoom(Room* r)
    {
        room.push_back(r);
    }
    void resorve(int userNum,const string&type)
    {
    	int count = 1;
    	for(const auto& i: room)
		{
			if(i->getType() == type && i->getStatus())
			{
				i->res();
				user[userNum - 1]->setRoomNum(count);
				return;
			}
			count++;
		}
		std::cerr << "fail" << std::endl;
    }
    void free(int userNum)
    {
    	room[user[userNum - 1]->getRoomNum()]->free();
    	user[userNum - 1]->setRoomNum(0);
    }
    void hSave(int userNum)
    {
    	string s = std::to_string(user[userNum - 1]->getRoomNum()) + "\n" ;
    	s += room[user[userNum - 1]->getRoomNum() - 1]->getType();
    	save(user[userNum - 1]->getName(),s);
    }
    void display(int userNum)
    {
    	std::cout<<user[userNum - 1]->getName() << '\n' << user[userNum - 1]->getRoomNum();
    	std::cout << "\n" <<  room[user[userNum - 1]->getRoomNum() - 1]->getType() << '\n';
    }
};

#endif