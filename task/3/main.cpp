#include "system.hpp"

int main()
{
	System s(User("Armen","123"));
	s.addInter(new sale(1,"2",3,"4"));
	s.addInter(new warrantyService("5","6",7));
	s.display();
	s.sysSave();
}