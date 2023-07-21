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
	int count;
	double price;
public:
	Book(const string &T,const string &A,const string &G,int c,double p):title(T),autor(A),genre(G) {
		count = c;
		price = p;
	}
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
	int getCount()
	{
		return count;
	}
	double getPrise()
	{
		return price;
	}
	void operator++()
	{
		count++;
	}
	void operator--()
	{
		count--;
	}
};

#endif