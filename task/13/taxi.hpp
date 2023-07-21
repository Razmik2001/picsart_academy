#ifndef TAXI_HPP
#define TAXI_HPP

#include <string>

using std::string;

class Taxi
{
private:
	string name;
	string carNum;
	char clas;
	bool status = true;//free
public:
	Taxi(const string& n,const string& cn,char c):name(n),carNum(cn),clas(c) {}
	string getName()
	{
		return name;
	}
	string getCarNum()
	{
		return carNum;
	}
	char getClas()
	{
		return clas;
	}
	bool getStatus()
	{
		return status;
	}
	void chuose()
	{
		status = false;
	}
	void free()
	{
		status = true;
	}
};

#endif 