#include <iostream>
#include <string>
#include <vector>

typedef unsigned int  UI;

struct Customer
{
	UI account_number;
	UI money;
};

class BankSystem
{
	UI m_money = 0;
	std::vector<Customer> customer;
public:
	void add_customer(int money);
	void withdraw(UI a_n,UI money);//-
	void deposit(UI a_n,UI money);//+
	UI get_customer_check(UI a_n);
	UI get_bank_check(){return m_money;}
};

void BankSystem::add_customer(int money)
{
	try
    {
        if (money < 0)
        {
        	throw std::invalid_argument("the amount of money can't be negated;");
        }
    customer.emplace_back();
	UI index = customer.size();
	customer[index - 1].account_number = index;
    customer[index - 1].money = money;
    m_money += money;
    }
    catch (std::invalid_argument& e)
    {
    	customer.pop_back();
        std::cerr << e.what() << std::endl;
        return ;
    }
}

void BankSystem::withdraw(UI a_n,UI money)
{
	try{
		if (customer.size() < a_n)
		{
			throw std::invalid_argument("we don't have a customer with this account number;");
		}
		if (customer[a_n - 1].money - money < 0)
		{
				throw std::invalid_argument("insufficient balance on the account;");
		}
		customer[a_n - 1].money -= money;
		m_money -= money;
	}
	 catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return;
    }
}

void BankSystem::deposit(UI a_n,UI money)
{
	try
	{
		if (customer.size() < a_n)
		{
			throw std::invalid_argument("we don't have a customer with this account number;");
		}
		customer[a_n - 1].money += money;
		m_money += money;
	}
	catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return;
    }
}

UI BankSystem::get_customer_check(UI a_n)
{
	try
	{
		if (customer.size() < a_n)
		{
			throw std::invalid_argument("we don't have a customer with this account number;");
		}
		return	customer[a_n - 1].money;
	}
	catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return 0;
    }
}

int main()
{
    BankSystem bank;

    // Add customers with initial balances
    bank.add_customer(100); // Customer 1 with $100
    bank.add_customer(200); // Customer 2 with $200
    bank.add_customer(300); // Customer 3 with $300

    // Perform transactions
    bank.deposit(1, 50);   // Deposit $50 to Customer 1
    bank.withdraw(2, 100); // Withdraw $100 from Customer 2
    bank.deposit(3, 200);  // Deposit $200 to Customer 3

    // Print customer balances
    std::cout << "Customer 1 balance: $" << bank.get_customer_check(1) << std::endl;
    std::cout << "Customer 2 balance: $" << bank.get_customer_check(2) << std::endl;
    std::cout << "Customer 3 balance: $" << bank.get_customer_check(3) << std::endl;

    // Print bank balance
    std::cout << "Bank balance: $" << bank.get_bank_check() << std::endl;

    return 0;
}







