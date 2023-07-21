#include "system.hpp"
#include "movies.hpp"
#include "user.hpp"


int main()
{
	System s;
	User* d = new User("armen","212");
	s.addUser(d);
	s.addMovies(new Movies("XALK",4.5,3.5,"18:30",20));
	s.bayTicket(1,"XALK");
}