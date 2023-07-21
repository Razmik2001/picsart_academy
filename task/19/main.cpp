#include "system.hpp"

int main() {
    User user1("John Doe", "123 Main St");
    Del delivery1("Item1", "Warehouse A", "Home", 2);
    System system;
    system.addDel(&delivery1, &user1);
    system.display(1);
    system.sSave(1);
    return 0;
}