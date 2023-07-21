#ifndef REST_HPP
#define REST_HPP

#include <string>
#include <map>
using std::string;
using std::map;
class Rest
{
	string loc;
	string name;
	map<string, int> menue;
public:
	Rest(const string &l,const string &n):loc(l),name(n) {
		addmanue("Jur",100);
	}
	string getName()
	{
		return name;
	}
	string getLoc()
	{
		return loc;
	}
	void addmanue(const string &s,int i)
	{
		menue.insert(std::make_pair(s,i));
	}
	int find(const string &s)
	{
		try{
			return menue[s];
		}
		catch(...)
		{
			return 0;
		}
	}
};

#endif