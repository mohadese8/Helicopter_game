#include"../include/enemy.hpp"

using namespace std;

void Enemy::Set_Location(int row ,int column)
{
    location.Set_Row(row);
    location.Set_Column(column);
}


Location Enemy::Get_Location() const
{
    return location;
}


void Enemy ::Set_Point(size_t point)
{
    this->point = point;
}


size_t Enemy :: Get_Point() const
{
    return point;
}

