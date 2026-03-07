#ifndef USERDATA_H
#define USERDATA_H

// Necessary Library Inclusions
#include <iostream>
#include <string>

class UserData
{
public:
    UserData();
    void showChips() const
    {return playerChips;}
    int playerChips;
};

std::ostream& operator<<(std::ostream& os, const userData& data);
std::istream& operator>>(std::istream& is, const userData& data);

#endif //USERDATA_H
