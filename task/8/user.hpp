#ifndef USER_HPP
#define  USER_HPP

#include <vector>
#include "book.hpp"
#include <string>
using std::string;
using std::vector;

class User
{
	const string name;
	const string conInf;
	vector<Book *> book;
public:
	User(string n,string cI):name(n),conInf(cI) {}
	string getName()
	{
		return name;
	}
	string getConInf()
	{
		return conInf;
	}
	void addBook(Book *b)
	{
		book.push_back(b);
		b->operator--();
	}
	void free(const string &title)
	{
		int count = 0;
    	for (auto it = book.begin(); it != book.end(); ++it) {
        if ((*it)->getTitle() == title) {
        	(*it)->operator++();
            book.erase(it);
            return;
        }
        count++;
    }
	}
	double getPrise()
	{
		double price = 0;
		for(const auto &i : book)
		{
			price+= i->getPrise();
		}
		return price;
	}
	vector<Book *> getBook()
	{
		return book;
	} 
};

#endif //USER_HPP