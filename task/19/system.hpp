#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include "user.hpp"
#include "del.hpp"

using std::vector;
void save(const string& user, const string& o)
    {
        string s = user + ".txt";
        std::ofstream f(s);
        f << o;
        f.close();
    }
class System
{
    vector<User *> user;
    vector<Del *> del;
public:
    void addDel(Del * d,User * u)
    {
        del.push_back(d);
        u->setDelNum(del.size());
        user.push_back(u);
    }
    void display(int delNum)
    {
        std::cout << user[delNum - 1]->getName() << '\n';
        std::cout << del[delNum -1]->getInfo() << '\n';
    }
    void sSave(int delNum)
    {
        save(user[delNum - 1]->getName(),del[delNum -1]->getInfo());
    }
};

#endif