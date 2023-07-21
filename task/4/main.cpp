#include "order.hpp"

int main()
{
	Rest r("manuk","abovyan");
	r.addmanue("Sok",1200);
	Order o(User("arman","123","cart"));
	o.orSave();
	o.addOrder("Sok",r);
	o.addOrder("Jur",r);
	o.orSave();
	o.display();
}