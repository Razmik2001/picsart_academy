#ifndef PARK_HPP
#define PARK_HPP


#include <string>
using std::string;

class Park
{
private:
	bool status = true;//if true then Park is free
	const string size;
	int price = 1;
public:
	Park(const string& s): size(s){
		if(s == "mid")
		{
			price = 2;
		}
		else if(s == "big")
		{
			price = 3;
		}
	}
	int getPrice()
	{
		return price;
	}
	string getSize()
	{
		return size;
	}
	bool getStatus()
	{
		return status;
	}
	void reserv()
	{
		status = false;
	}
	void free()
	{
		status = true;
	}
};


#endif 