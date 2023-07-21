#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
using std::string;

class Book
{
private:
	const string title;
	const string autor;
	const string genre;
	bool isAval = true;//book in lib;
public:
	Book(const string &T,const string &A,const string &G):title(T),autor(A),genre(G) {}
	string  getTitle()
	{
		return title;
	}
	string  getAutor()
	{
		return autor;
	}
	string  getGenre()
	{
		return genre;
	}
	bool getStatus()
	{
		return isAval;
	}
	void chouse(){isAval = false;}
	void free(){isAval = true;}
};

#endif