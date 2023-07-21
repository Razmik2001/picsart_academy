#include "system.hpp"
#include <chrono>
#include <thread>

int main()
{
    Park park1("small");
    Park park2("mid");
    Park park3("big");
    User user1("John", "john@example.com");
    User user2("Alice", "alice@example.com");
    System sys;
    sys.addPark(&park1);
    sys.addPark(&park2);
    sys.addPark(&park3);
    sys.addUser(&user1);
    sys.addUser(&user2);
    sys.reserve(1, "mid");
    sys.reserve(2, "small");
    std::chrono::seconds delay(60);
    std::this_thread::sleep_for(delay);
    sys.free(1);
    sys.sSave();
}