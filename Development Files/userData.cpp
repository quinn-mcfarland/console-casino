// Library Inclusions
#include <iostream>
#include <string>

//Header Inclusion
#include "userData.h"

userData::userData()
{
    playerChips = 100;
}

std::ostream& userData::operator<<(std::ostream& os, const UserData& data)
{
    os << playerChips;
    return os;
}

std::istream& userData::operator>>(std::istream& is, UserData& data)
{
    is >> playerChips;
    return is;
}
