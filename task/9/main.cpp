#include "fitnes.hpp"

int main() {
    User user1("John", "john@example.com", "prem");
    User user2("Alice", "alice@example.com", "all");

    Fitnes fitnessCenter;
    fitnessCenter.addUser(&user1);
    fitnessCenter.addUser(&user2);

    fitnessCenter.goGym(1);
    fitnessCenter.goGym(1);
    fitnessCenter.goMassag(1);
    fitnessCenter.goPool(2);

    fitnessCenter.display();
    fitnessCenter.fSave();
    return 0;
}