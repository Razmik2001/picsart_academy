#ifndef REC_HPP
#define REC_HPP

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using std::vector;
using std::string;

int N = 1;

class Rec
{
	const string inst;
	vector<string> ing;
	bool find();
public:
	Rec(const string& it,vector<string> ig):inst(it),ing(ig)
	{
		string s = "Rec" + std::to_string(N);
		N++;
		std::fstream f(s, std::ios::out);
		{
			f << it << '\n';
			for (const auto& it : ing)
			{
				f << it << '\n';
			}
			f.close();
		}
	}
	string geInst()
	{
		return inst;
	}
	vector<string> getIng()
	{
		return ing;
	}
	bool isIn(const vector<string>& vs) const
	{
    for (const auto& i : vs)
    {
        bool found = false;
        for (const auto& v : ing)
        {
            if (i == v)
            {
                found = true;
                break;
            }
        }
        if (!found)
            return false; 
    }
    return true;
    }
	void display()
	{
		std::cout << inst << "\n";
		for(const auto& it : ing)
		{
			std::cout << it << '\n';
		}
	}
};

#endif