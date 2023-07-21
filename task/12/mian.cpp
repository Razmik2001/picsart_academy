#include "system.hpp"

int main()
{
    User user1("Alice", "Contact info for Alice");
    Table table1(4);
    System reservationSystem;
    reservationSystem.addTable(&table1);
    reservationSystem.addUser(&user1);
    reservationSystem.reserve(1, 4);
    reservationSystem.sSave(1);
    return 0;
}