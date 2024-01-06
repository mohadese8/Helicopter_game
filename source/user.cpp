#include"../include/user.hpp"

using namespace std;

void User :: Set_Location(int row ,int column)
{
    location.Set_Row(row);
    location.Set_Column(column);
}


Location User :: Get_Location() const
{
    return location;
}


void User :: Set_Heal(int heal)
{
    this->heal = heal;
}


int User :: Get_Heal() const
{
    return heal;
}


void User :: Set_User_Point(size_t point)
{
    this->user_point = point;
}


size_t User :: Get_User_Point() const
{
    return user_point ;
}


void User :: Add_Point(size_t point)
{
    user_point += point;
}


void User :: Decrease_Heal()
{
    heal--;
}

bool User :: Check_Heal() const
{
    if (heal == 0)
        return true;

    return false;
}