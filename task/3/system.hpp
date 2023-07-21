#include "inter.hpp"
#include "user.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
using std::vector;
void save(const string& user, const string& bill)
    {
        std::time_t t = std::time(nullptr);
        std::tm* now = std::localtime(&t);
        string s = user + std::to_string(now->tm_mday);
        std::ofstream f(s + ".txt");
        f << bill;
        f.close();
    }
class System
{
private:
    User user;
    vector<Inter *> inter;
public:
    System(const User &u):user(u){}
    void addInter(Inter *i)
    {
        inter.push_back(i);
    }
    string info()
    {
        string s = "";
        for (const auto& i : inter) {
            s+= i->getInfo();
        }
        return s;
    }
    void display()
    {
        std::cout << info();
    }
    void sysSave()
    {
        save(user.getName(),info());
    }
};