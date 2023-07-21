#ifndef INTER_HPP
#define INTER_HPP

#include <string>
using std::string;


class Inter
{
public:
	virtual string getInfo() = 0;
};

class sale : public Inter
{
private:
	string s;
public:
	sale(int date,const string& user,int amount,const string& warrantPeriod)
	{
		s = std::to_string(date) + "\n" + user + "\n" + std::to_string(amount);
		s +="\n"+ warrantPeriod + "\n";
	}
	string getInfo() override {return s;}
};

class warrantyService : public Inter
{
private:
	string s;
public:
	warrantyService(const string& sale,const string& user,int cost)
	{
		s = sale + "\n" + user + "\n" + std::to_string(cost) + "\n";
	}
	string getInfo() override {return s;}
};

class compliant: public Inter
{
private:
	string s;
public:
	compliant(const string& sale,const string& user,const string& desOFCom)
	{
		s = sale + "\n" + user + "\n" + desOFCom + "\n";
	}
	string getInfo() override {return s;}
};

#endif