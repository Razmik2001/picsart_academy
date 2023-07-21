#include "bank.hpp"
#include <iostream>

int main()
{
    User user1("John", "Contact info 1", 1); // User with blood type 1
    User user2("Alice", "Contact info 2", 2); // User with blood type 2
    Bank bloodBank;
    bloodBank.addUser(&user1);
    bloodBank.addUser(&user2);
    bloodBank.addBlood(1, 2500); // Add 500ml of blood of type 1 to the bank
    bloodBank.addBlood(2, 300); // Add 300ml of blood of type 2 to the bank
    bloodBank.subBlood(1, 100); // Subtract 100ml of blood of type 1 from the bank
    std::cout << "Blood Bank Status:\n";
    bloodBank.status();
    bloodBank.bSave();
    return 0;
}