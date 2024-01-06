#if !defined(USER)
#define USER

#include"location.hpp"

class User
{
    private :
    Location location ; // store location of user
    size_t user_point = 0; // point of user 
    int heal = 3; // user has 3 heal

    public :
    void Set_Location(int ,int);
    Location Get_Location() const;

    void Set_User_Point(size_t);
    size_t Get_User_Point() const;

    void Set_Heal(int);
    int Get_Heal() const;

    void Add_Point(size_t);
    void Decrease_Heal();
    bool Check_Heal() const;
};


#endif // USER
