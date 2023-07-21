#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <iostream>
#include <fstream>
#include <vector>
using std::vector;
#include "park.hpp"
#include "user.hpp"
void save(const string& user, const string& o)
    {
        string s = user + ".txt";
        std::ofstream f(s);
        f << o;
        f.close();
    }

class System
{
    int time = 0;
    int reCount = 0;
    int c = 0;
    vector<User *> user;
    vector<Park *> park;
public:
    void addPark(Park *p)
    {
        park.push_back(p);
    }
    void addUser(User *u)
    {
        user.push_back(u);
    }
    void reserve(int userNumber,const string& size)
    {
        int count = 1;
        for(const auto& i :park)
        {
            if(i->getSize() == size && i->getStatus())
            {
                user[userNumber - 1]->setParkNum(count);
                i->reserv();
                reCount++;
                c++;
                return;
            }
            count ++;
        }
    }
    void free(int userNumber)
    {
        int i = user[userNumber - 1]->getParkNum();
        int p = park[i -1] -> getPrice();
        park[i -1] ->free();
        reCount--;
        int t = (std::time(nullptr) - user[userNumber - 1]->getTime()) / 60;
        time += t;
        int sum = p * t;
        std::cout << user[userNumber - 1]->getName() << '\n';
        std::cout << t << " minutes\n";
        std::cout << sum << "$\n";
    }
    void sSave()
    {
        double t = 0;
        if(c != 0)
        t = (double)time / c; 
        string s = "mid time " + std::to_string(t);
        double sum = 0;
        for(const auto& i :park)
        {
            sum += i->getPrice() * t;
        }
        s += "\nmid price " + std::to_string(sum);
        s += "\nfree park place " + std::to_string(park.size() - reCount);
        save("System",s); 
    } 
};

#endif