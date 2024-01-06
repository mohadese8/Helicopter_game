#if !defined(LOCATION)
#define LOCATION

#include<iostream>

class Location
{
    private :
    int row = -1; // set to -1 to disable
    int column = -1; // set to -1 to disable

    public :
    void Set_Row(int); // row setter 
    void Set_Column(int); // column setter

    int Get_Row() const;
    int Get_Column() const;
};


#endif // LOCATION
