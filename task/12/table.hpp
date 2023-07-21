#ifndef TABLE_HPP
#define TABLE_HPP


#include <string>
using std::string;

class Table
{
private:
	bool status = true;//if true then Table is free
	int capacity;
public:
	Table(int capacity): capacity(capacity){}
	int getCapacity()
	{
		return capacity;
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