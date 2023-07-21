#ifndef SYSYTEM_HPP
#define SYSYTEM_HPP

#include "user.hpp"
#include "taxi.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
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

class Sysytem
{
private:
    vector<Taxi*> taxis; // Use smart pointers to avoid memory leaks
    vector<User*> users; // Use smart pointers to avoid memory leaks

public:
    void addUser(User* u)
    {
        users.push_back(u);
    }

    void addTaxi(Taxi* t)
    {
        taxis.push_back(t);
    }

    string order(char prefClas, int len)
    {
        for (auto& i : taxis)
        {
            if (i->getClas() == prefClas && i->getStatus())
            {
                double bill = len;
                if (prefClas == 'c')
                {
                    bill += 1.8; // Add the extra cost for class 'c'
                }
                else if (prefClas == 'b')
                {
                    bill += 3.0; // Add the extra cost for class 'b'
                }
                i->chuose();
                string s = "Taxist: " + i->getName() + "\nCar num: " + i->getCarNum() + "\nBill: " + std::to_string(bill);
                return s;
            }
        }
        return "";
    }

    void consolOrder(char prefClas, int len)
    {
        for (auto& i : taxis)
        {
            if (i->getClas() == prefClas && i->getStatus())
            {
                double bill = len;
                if (prefClas == 'c')
                {
                    bill += 1.8; // Add the extra cost for class 'c'
                }
                else if (prefClas == 'b')
                {
                    bill += 3.0; // Add the extra cost for class 'b'
                }
                i->chuose();
                string s = "Taxist: " + i->getName() + "\nCar num: " + i->getCarNum() + "\nBill: " + std::to_string(bill);
                cout << s;
                return;
            }
        }
        cout << "Fail";
    }

    void ordSave(int userNum, const string& o)
    {
        if (!o.empty())
            save(users[userNum - 1]->getName(), o);
    }   
};


#endif