#if !defined(MAP)
#define MAP

#include"user.hpp"
#include"enemy.hpp"
#include<random>
#include<ctime>
#include<vector>
#include<fstream>

class Map
{
    public :
    bool IsGameOver = false; // true if game over or false if not over
    bool File_Loading = false; // true if file loading is enabled
    char arr[10][10]{0}; // set null 
    std::vector<Enemy> enemies ; // vector of enemies
    User user ; // user object
    void User_Creator(); // create user
    void Move_User_Shots(); // move user shots
    void Move_User_Up(); // move enemy to up
    void Move_User_Down(); // move enemy to down
    void Move_User_Left(); // move enemy to left
    void Move_User_Right(); // move enemy to right
    void Move_User(); // move enemy
    void Shot_User(); // shoot user helicopter
    

    void Enemy_Creator(); // create enemies
    void Move_Enemy(); // move enemy to left
    void Is_Enemy_Destroyed(); // check that enemy is destroyed or not
    void Is_Enemy_Reach_To_End(); // check if enemy is reach to column 0 or not . if reached , user heal decrease


    void Print() const ; // print map
    void Is_Collision(); // check if collision with enemy
    void Start(); // start the game
    bool Is_Game_Over() ; // check if game over or not

};


#endif // MAP
