#include"../include/map.hpp"


using namespace std;


void Map ::User_Creator() // Create user helicopter
{
    default_random_engine eng(time(nullptr)); // random
    uniform_int_distribution<unsigned> rand1(0 , 10 - 1); // random
    uniform_int_distribution<unsigned> rand2(0 , 4); // random

    int first ,second ;
    first = rand1(eng);
    second = rand2(eng);

    user.Set_Location(first ,second);
    arr[first][second] = 'U';
}


void Map :: Move_User_Shots() // move user shots (helicopter)
{
    for (size_t i = 0; i < 10; i++)
    {
        for (int j = 9 ; j >= 0 ; j--)
        {
            if (arr[i][j] == '*')
            {
                if (j == 9)
                    arr[i][j] = 0;
                

                else if (arr[i][j + 1] == 0)
                {
                    arr[i][j] = 0;
                    arr[i][j + 1] = '*';
                }

                if (arr[i][j + 1] == 'E')
                {
                    //cout << "move_user_shots" << endl;
                    //cin.get();
                    Is_Enemy_Destroyed();
                }
            }
        }
    }
}


void Map :: Move_User_Up() // user helicopter can move up
{
    Location temp = user.Get_Location();

    if (temp.Get_Row() - 1 >= 0 && arr[temp.Get_Row()- 1][temp.Get_Column()] == 0)
    {
        arr[temp.Get_Row()][temp.Get_Column()] = 0;
        user.Set_Location(temp.Get_Row() - 1 , temp.Get_Column());
        temp = user.Get_Location();
        arr[temp.Get_Row()][temp.Get_Column()] = 'U';
    }
}


void Map :: Move_User_Down() // user helicopter can move down
{
    Location temp = user.Get_Location();

    if (temp.Get_Row() + 1 < 10 && arr[temp.Get_Row() + 1][temp.Get_Column()] == 0)
    {
        arr[temp.Get_Row()][temp.Get_Column()] = 0;
        user.Set_Location(temp.Get_Row() + 1 ,temp.Get_Column());
        temp = user.Get_Location();
        arr[temp.Get_Row()][temp.Get_Column()] = 'U';
    }
}


void Map :: Move_User_Left() // user helicopter can move left
{
    Location temp = user.Get_Location();

    if (temp.Get_Column() - 1 >= 0 && arr[temp.Get_Row()][temp.Get_Column() - 1] == 0)
    {
        arr[temp.Get_Row()][temp.Get_Column()] = 0;
        user.Set_Location(temp.Get_Row() ,temp.Get_Column() - 1);
        temp = user.Get_Location();
        arr[temp.Get_Row()][temp.Get_Column()] = 'U';
    }
}


void Map :: Move_User_Right() // user helicopter can move right
{
    Location temp = user.Get_Location();

    if (temp.Get_Column() + 1 < 10 && arr[temp.Get_Row()][temp.Get_Column() + 1] == 0)
    {
        arr[temp.Get_Row()][temp.Get_Column()] = 0;
        user.Set_Location(temp.Get_Row() ,temp.Get_Column() + 1);
        temp = user.Get_Location();
        arr[temp.Get_Row()][temp.Get_Column()] = 'U';
    }
}


void Map :: Move_User() // we can move to 4 different locations
{
    cout << "w : up , s : down , a : left , d : right (q : quit)" << endl;
    cout << "Enter Move Char : ";
    char command;
    cin >> command; // receive char from user
    cin.get();

    switch (command)
    {
        case 'w':
        case 'W':
        {
            Move_User_Up();
            break;
        }
    
        case 's':
        case 'S':
        {
            Move_User_Down();
            break;
        }

        case 'a':
        case 'A':
        {
            Move_User_Left();
            break;
        }

        case 'd':
        case 'D':
        {
            Move_User_Right();
            break;
        }

        case 'q':
        case 'Q': // quit and save game in file
        {
            ofstream outFile("game.txt");

            if (!outFile.is_open())
            {
                cerr << "Error: Unable to open file for writing." << std::endl;
                exit(EXIT_FAILURE);
            }

            Location temp = user.Get_Location();

            outFile << temp.Get_Row() << ' ' ;
            outFile << temp.Get_Column() << ' ' << user.Get_Heal() << ' ' << user.Get_User_Point() << endl;

            outFile << enemies.size() << endl;

            for (size_t i = 0; i < enemies.size() ; i++)
            {
                temp = enemies[i].Get_Location();
                outFile << temp.Get_Row() << ' ' ;
                outFile << temp.Get_Column() << ' ' << enemies[i].Get_Point() << endl;
            }

            for (size_t i = 0; i < 10; i++)
            {
                for (size_t j = 0; j < 10 ; j++)
                {
                    outFile << arr[i][j] << ' ';
                }
                outFile << endl;
            }
            
            exit(EXIT_SUCCESS);
        }

        default:
        {
            cerr << "You Entered Invalid Character !!!" << endl;
            break;
        }
    }
}


void Map :: Shot_User() // user helicopter can shot in every move
{
    Location temp = user.Get_Location();


    if (arr[temp.Get_Row()][temp.Get_Column() + 1] == 0)
    {
        arr[temp.Get_Row()][temp.Get_Column() + 1] = '*';
    }

    if (arr[temp.Get_Row()][temp.Get_Column() + 1] == 'E')
    {
        arr[temp.Get_Row()][temp.Get_Column()] = '*';
        Is_Enemy_Destroyed();
        arr[temp.Get_Row()][temp.Get_Column()] = 'U';
    }
}


void Map ::Enemy_Creator() // create enemies in the map
{
    enemies.clear();
    default_random_engine eng(time(nullptr)); // random
    uniform_int_distribution<unsigned> rand1(0 , 9); // random

    int number;

    for (size_t i = 0; i < 4; i++) // size of the enemy = 4 
    {
       // cout << i << endl;
        number = rand1(eng);
        

        if (arr[number][9] == 0)
        {
            arr[number][9] = 'E';
            Enemy temp;
            temp.Set_Location(number ,9);

            int point = rand1(eng);
            temp.Set_Point(point * 10);

            enemies.push_back(temp);
        }

        else
            i--; // It means that the loop must turn again
    }
}


void Map :: Move_Enemy() // move enemies to the left side
{
    for (size_t i = 0; i < enemies.size() ; i++)
    {
        Location temp = enemies[i].Get_Location();

        if (temp.Get_Column() >= 0 && arr[temp.Get_Row()][temp.Get_Column() - 1] == 0);
        {
            enemies[i].Set_Location(temp.Get_Row() ,temp.Get_Column() - 1);
            arr[temp.Get_Row()][temp.Get_Column() - 1] = 'E';
            arr[temp.Get_Row()][temp.Get_Column()] = 0;
        }
    }
}



void Map :: Is_Enemy_Destroyed() // If the bullet hits the helicopter . we destroy helicopter and delete it from vector
{
    vector <Enemy> flag ;

    for (size_t i = 0; i < enemies.size() ; i++)
    {
        Location temp = enemies[i].Get_Location();

        if (arr[temp.Get_Row()][temp.Get_Column() - 1] == '*')
        {
            arr[temp.Get_Row()][temp.Get_Column()] = 0;
            arr[temp.Get_Row()][temp.Get_Column() - 1] = 0;
            user.Add_Point(enemies[i].Get_Point());
            continue;
        }
        
        flag.push_back(enemies[i]);
    }
    
    enemies = flag ;
}


void Map :: Is_Enemy_Reach_To_End() // if enemy reach to the 0 column , user heal decrease
{
    vector<Enemy> flag ;
    for (size_t i = 0; i < enemies.size() ; i++)
    {
        Location temp = enemies[i].Get_Location();

        if (temp.Get_Column() == 0)
        {
            arr[temp.Get_Row()][temp.Get_Column()] = 0;
            user.Decrease_Heal();

            if(Is_Game_Over() == true)
            {
                IsGameOver = true;
                return ;
            }

            continue;
        }
        
        flag.push_back(enemies[i]);
    }

    enemies = flag;
}


void Map :: Print() const // print map
{
    for (size_t i = 0; i <= 10; i++)
    {
        for (size_t k = 0; k < 41; k++)
            cout << "-" ;
        cout << endl;

        for (size_t j = 0; j < 10 && i != 10; j++)
        {
            cout << (j == 0 ? "| " : " ");

            if (arr[i][j] == 0)
                cout << ' ';

            else if(arr[i][j] == 'U')
                cout << "\033[34m" << '>' << "\033[0m";

            else if (arr[i][j] == 'E')
                cout << "\033[31m" << '<' << "\033[0m";

            else if(arr[i][j] == '*')
                cout << "\033[35m" << '*' << "\033[0m";

            cout << " |";
        }
        cout << endl;
    }
}


bool Map ::Is_Game_Over() // check if game is over or not
{
    if (user.Check_Heal() == true)
    {
        cout << "Game Over" << endl;
        IsGameOver = true;
        return true;
    }
    
    return false;
}




void Map :: Is_Collision() // If the helicopter and the enemy collide . we decrease user heal and delete enemy
{
    vector<Enemy> flag ;

    for (size_t i = 0; i < enemies.size() ; i++)
    {
        Location temp1 ,temp2;
        temp1 = enemies[i].Get_Location();
        temp2 = user.Get_Location();

        if (temp1.Get_Row() == temp2.Get_Row())
        {
            if (temp1.Get_Column() == temp2.Get_Column())
            {
                user.Decrease_Heal();

                if(Is_Game_Over() == true)
                {
                    IsGameOver = true;
                    return ;
                }

                continue;
            }
        }
        
        flag.push_back(enemies[i]);
    }

    enemies.clear();
    enemies = flag;
}





void Map :: Start() // start game until game is over
{
    if (File_Loading == false) // if game loaded into file we recover that file
    {
        User_Creator(); 

        Enemy_Creator();
    }

    while (IsGameOver == false) // game loop
    {
        Shot_User();
        Is_Enemy_Destroyed();
        system("cls");
        cout << "Health: " << user.Get_Heal() << endl;
        cout << "Point : " << user.Get_User_Point() << endl;
        Print();
        Move_User();
        Is_Enemy_Destroyed();
        Print();
        Move_Enemy();
        Is_Enemy_Destroyed();
        Move_User_Shots();
        Is_Enemy_Reach_To_End();

        if (enemies.size() == 0)
            Enemy_Creator(); // cerate new enemy
    }
}


