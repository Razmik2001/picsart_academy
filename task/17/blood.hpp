#ifndef BLOOD_HPP
#define BLOOD_HPP

#include <iostream>
#include <map>
using std::map;
#include <string>
using std::string;
class Blood
{
	string s = "";
	map<int,int> m = {{1,0},{2,0},{3,0},{4,0}};
public:
	void addBlood(int type,int size)
	{
		m[type] += size;
		s += "add type" + std::to_string(type) + "  " + std::to_string(size) + "ml\n";
	}
	void subBlood(int type,int size)
	{
		if(m[type] >= size)
		{
			m[type] -= size;
			s += "sub type" + std::to_string(type) + "  " + std::to_string(size) + "ml\n";
		}
		std::cout << "FAIL\n";
	}
	string getInfo()
	{
		string str = "";
		for(int i = 1;i < 5;i++)
		{	
			str += "type" + std::to_string(i) + "  " + std::to_string(m[i]) + "ml";
			if(m[i] <= 2000)
				str += "  need more";
			str += '\n';
		}
		return str;
	}
	string info()
	{
		return s;
	}
};

#endif