#include"../include/location.hpp"

using namespace std;

void Location :: Set_Column(int column)
{
    this->column = column;
}


void Location :: Set_Row(int row)
{
    this->row = row;
}


int Location :: Get_Row() const
{
    return row;
}


int Location :: Get_Column() const
{
    return column;
}