#ifndef SYSTEM_HPP
#define  SYSTEM_HPP

#include <iostream>
#include "movies.hpp"
#include "user.hpp"
#include <vector>
#include <fstream>

using std::vector;
using std::cout;

void save(string title,string file)
{
	std::fstream f(title + ".TXT");
	f << file;
	f.close();
}

class System
{
	vector<Movies *> mov;
	vector<User *> user;
public:
	void addMovies(Movies * m){
		mov.push_back(m);
	}
	void addUser(User* u)
	{
		user.push_back(u);
	}
	string find(const string& title) {
        for (const auto& i : mov) {
            if (title == i->getTitle() && i->getCount() > 0) {
                string s = "Movie: " + i->getTitle() + "\nShow Time: " + i->getShowTime() + "\nPlace: " + std::to_string(i->getCount());
                return s;
            }
        }

        cout << "No such film." << std::endl;
        return "";
    }
	void bayTicket(int userNum,string title)
	{
		string s = find(title);
		if (!s.empty())
            save(user[userNum - 1]->getName(), s);
	}
};

#endif 
