#include "hotel.hpp"


int main() {
    User user1("John", "john@example.com");
    User user2("Alice", "alice@example.com");
    Room room1("stan");
    Room room2("deluxe");
    Hotel hotel;
    hotel.addUser(&user1);
    hotel.addUser(&user2);
    hotel.addRoom(&room1);
    hotel.addRoom(&room2);
    hotel.resorve(1, "stan");
    hotel.resorve(2, "deluxe");
    hotel.free(1);
    hotel.hSave(2);
    hotel.display(2);
    return 0;
}