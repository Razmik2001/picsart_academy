#ifndef LIB_HPP
#define LIB_HPP

#include "user.hpp"
#include <iostream>
#include <fstream>
void save(User * u) {
    std::string s = u->getName() + ".txt";
    std::ofstream f(s);
    auto b = u->getBook();
    for(auto &i :b)
		{
			f <<  i->getTitle() << "\n"  <<  i->getAutor() << "\n"  <<   i->getGenre() << "\n\n\n";
		}
    f.close();
}

class Lib
{
	vector<User *> user;
	vector<Book *> book;
public:
	void addUser(User *u)
	{
		user.push_back(u);
	}
	void addBook(Book* b)
	{
		book.push_back(b);
	}
	void free(int userNum,const string& title)
	{
		user[userNum - 1]->free(title);
	}
	void display(int userNum)
	{
		std::cout << user[userNum -1]->getName()<<std::endl;
	    auto  b = user[userNum -1]->getBook();
    	for(auto &i :b)
		{
			std::cout <<  i->getTitle() << "\n"  <<  i->getAutor() << "\n"  <<   i->getGenre() << "\n\n";
		}
	}
	void chouse(int userNum,const string& str)
	{
		for(auto &i :book)
		{
			if((i->getTitle() == str || i->getAutor() == str || i->getGenre() == str) && i->getStatus())
			{
				user[userNum - 1]->addBook(i);
				return ;
			}
		}
	}
	void lSave(int userNum)
	{
		save(user[userNum - 1]);
	}
};

#endif