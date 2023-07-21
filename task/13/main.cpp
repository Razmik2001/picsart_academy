#include "sysytem.hpp"

int main()
{
	Sysytem s;
    s.addUser(new User("a", "12"));
    s.addTaxi(new Taxi("S", "12qa121", 'c'));
    s.addTaxi(new Taxi("D", "12qa121", 'c'));
    s.consolOrder('c', 12); 
    s.ordSave(1, s.order('c', 12)); 
}