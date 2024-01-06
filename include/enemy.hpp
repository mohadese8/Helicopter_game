#if !defined(ENEMY)
#define ENEMY

#include"location.hpp"

class Enemy
{
    private :
    Location location ;
    size_t point = 0;

    public :
    void Set_Location(int ,int);
    Location Get_Location() const;

    void Set_Point(size_t);
    size_t Get_Point() const;
};


#endif // ENEMY
