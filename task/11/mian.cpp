#include "airline.hpp"

int main()
{
    User user1("John Doe", "john.doe@example.com");
    Plane plane1(101, 200, "New York", "Los Angeles", 20230720);
    Airline airline;
    airline.addUser(&user1);
    airline.addPlane(&plane1);
    airline.resorve(1, "New York", "Los Angeles", 20230719, 20230721);
    airline.display(1);
    airline.aSave(1);
    return 0;
}