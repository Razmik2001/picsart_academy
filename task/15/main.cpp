#include "agency.hpp"

int main()
{
    Place paris(100, "Paris");
    User user1("John", "Contact Info 1");
    Agency agency;
    agency.addUser(&user1);
    agency.addPlace(&paris);
    agency.resorv(1, 100, "Paris"); 
    agency.placeSave(1); 
    return 0;
}