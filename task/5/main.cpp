#include "lib.hpp"

int main()
{
	Lib l;
	l.addBook(new Book("shxakat","Armen,Poxos","romantik"));
	l.addUser(new User("Valod","125400"));
	l.chouse(1,"shxakat");
	l.display(1);
	l.lSave(1);
	string s = "shxakat";
	l.free(1,s);
	l.display(1);
}