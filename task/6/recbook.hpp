#ifndef RECBOOK_HPP
#define RECBOOK_HPP

#include "rec.hpp"


class Recbook
{
	vector<Rec *> rec;
public:
	Recbook()
	{
		int N = 1;
		while(1)
		{
			string s = "Rec" + std::to_string(N);
			std::ifstream f(s);
			if(!f)
			{
				f.close();
				break;
			}
			string inst;
			std::getline(f, inst);
			vector<string> ing;
			std::string line;
   			while (std::getline(f, line))
   				ing.push_back(line);
   			N++;
   			rec.push_back(new Rec(inst,ing));
   			f.close();
		}
	}
	void addRec(Rec * r)
	{
		rec.push_back(r);
	}
	void findRec(vector<string> &ing)
	{
		for(const auto& i :rec)
		{
			if(i->isIn(ing))
				i->display();
			std::cout <<"\n\n";
		}
	}
};

#endif