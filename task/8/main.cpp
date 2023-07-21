#include "lib.hpp"

int main()
{
	Lib l;
	l.addBook(new Book("shxakat","Armen,Poxos","romantik",12,1));
	l.addBook(new Book("piu","Armen,Poxos","roman",12,1));
	l.addBook(new Book("miu","Nata","romantik",12,1));
	l.addUser(new User("Armenchik","125400"));
	l.chouse(1,"shxakat");
	l.chouse(1,"roman");
	l.chouse(1,"Nata");
	l.display(1);
	l.lSave(1);
	string s = "shxakat";
	l.free(1,s);
	l.display(1);
}