#ifndef MOVIES_HPP
#define  MOVIES_HPP

#include <string>
using std::string;

class Movies
{
	string title;
	double duration;
	double rating;
	string showTime;
	int count;
public:
	Movies(string t,double d,double r,string SH,int c)
	{
		count = c;
		title = t;
		duration = d;
		rating = r;
		showTime = SH;
	}
	string getTitle()
	{
		return title;
	}
	string getShowTime()
	{
		return showTime;
	}
	double getDuration(){
		return duration;
	}
	double getRating(){
		return rating;
	}
	int getCount()
	{
		return count;
	}
};


#endif //MOVIES_HPP