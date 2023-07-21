#ifndef PLACE_HPP
#define PLACE_HPP


#include <string>
using std::string;

class Place
{
	int price;
	const string dest;
	int count = 75;
public:
	Place(int p,const string & d):price(p),dest(d){}
	int getCount()
	{
		return count;
	}
	int getPrice()
	{
		return price;
	}
	string getDest()
	{
		return dest;
	}
	void reserv()
	{
		count--;
	}
	bool isIn(int p,const string& d)
	{
		if(count != 0 && price == p && dest == d)
			return true;
		return false;
	}
	string getInfo()
	{
		string s = "place -> " + dest;
		s+= "\nprice -> " + std::to_string(price);
		s+= "\ncount -> " + std::to_string(count) + "\n";
		return s;
	}
};

#endif