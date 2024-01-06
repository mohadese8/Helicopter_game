#include"include/map.hpp"

using namespace std;

int main()
{
    Map map ;
    
    ifstream inFile("game.txt");

    if (inFile.is_open())
    {
        int file_number ;
        for (size_t i = 0; i < 4; i++)
        {
            inFile >> file_number;

            switch (i)
            {
                case 0:
                {
                    map.user.Set_Location(file_number ,0);
                    break;
                }
            
                case 1:
                {
                    Location temp = map.user.Get_Location();
                    map.user.Set_Location(temp.Get_Row() ,file_number);
                    break;
                }

                case 2:
                {
                    map.user.Set_Heal(file_number);
                    break;
                }

                case 3:
                {
                    map.user.Set_User_Point(file_number);
                    break;
                }
            }      
        }

        int size ;
        inFile >> size ;

        for (size_t i = 0; i < size ; i++)
        {
            int first ,second ,hit;
            inFile >> first >> second >> hit;
            Enemy temp ;
            temp.Set_Location(first ,second);
            temp.Set_Point(hit);
            map.enemies.push_back(temp);
        }
        
        char command;

        for (size_t i = 0; i < 10; i++)
        {
            for (size_t j = 0; j < 10 ; j++)
            {
                inFile >> command;
                map.arr[i][j] = command;
            }
        }

        map.File_Loading = true;
    }

    map.Start();

    if (map.IsGameOver == true)
    {
        remove("game.txt");
    }

    return 0;
}