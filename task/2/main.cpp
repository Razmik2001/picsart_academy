#include "bill.hpp"
#include <thread>


int main()
{
	Bill b(12);
	User *u = new User("ar","12s","1e313");
	std::chrono::seconds delay(4);
	std::this_thread::sleep_for(delay);
	b.displeyBill(u);
	b.saveBill(u);
}