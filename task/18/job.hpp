#ifndef JOB_HPP
#define JOB_HPP

#include <string>
using std::string;
#include <vector>
using std::vector;

class Job
{
	const string title;
	const string desc;
	vector<string> req;
	const string comp;
	int salary;
public:
	Job(const string& t,const string& d,const vector<string>& r,const string&c,int s):title(t),desc(d),req(r),comp(c),salary(s){}
	bool isIn(const vector<string>& vs) const
	{
    for (const auto& i : vs)
    {
        bool found = false;
        for (const auto& v : req)
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
    string getTitle(){
    	return title;
    }
    string getDesc(){
    	return desc;
    }
    string getComp(){
    	return comp;
    }
    int getSalary(){
    	return salary;
    }
    string getInfo()
    {
    	string s = "title " + title;
    	s+= "\ndescrip " + desc;
    	s += "\n| ";
    	for(const auto& i:req)
    	{
    		s += i + " | ";
    	} 
    	s += "\nsalary " + std::to_string(salary) + "\n\n";
    	return s;
    }
};

#endif