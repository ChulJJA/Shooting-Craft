/**
\file        Enemy_Move_Phase_1_first.cpp
\author      Chulseung Lee
\brief
This will when phase_1 move the first array of enemy.

copyright   All content ?2018 DigiPen (USA) Corporation, all rights reserved

*/


#include "Enemy_Move_Phase_1_first.h"
#include "MapStatus.h"
#include "Ship_Status.h"
#include "Enemy_Part.h"
#include "stdlib.h"
#include "time.h"

void Enemy_Move3(Game_Map game_map, XY_Position_Ship* current_ship_xy, Map_Status_Count current_map_status, bool enemy_arr_2)
{
    int x = 0, y = 0;
    int end_x = 0, end_y = 0;
    int temp = 0;


    if (!enemy_arr_2)
    {
        for (int i = 0, a = current_map_status.count_all_enemy - 1; i < current_map_status.count_all_enemy && a >= 0; i++, a--)
        {
            x = current_ship_xy->all_enemy_x[a];
            y = current_ship_xy->all_enemy_y[a];


            if ((game_map[y][x] <= Enemy_Body_Left && game_map[y][x] >= Enemy_Body_Left - 2) && y != Enemy_Arr1_Shoot_Range - 1)
            {
                temp = game_map[y][x];
                game_map[y][x] = AIR;
                game_map[y + 1][x] = temp;

            }
            if ((game_map[y][x] <= Enemy_Body_Right && game_map[y][x] >= Enemy_Body_Right - 2) && y != Enemy_Arr1_Shoot_Range - 1)
            {
                temp = game_map[y][x];
                game_map[y][x] = AIR;
                game_map[y + 1][x] = temp;

            }
            if ((game_map[y][x] <= Enemy_Head && game_map[y][x] >= Enemy_Head - 2) && y != Enemy_Arr1_Shoot_Range - 1)
            {
                temp = game_map[y][x];
                game_map[y][x] = AIR;
                game_map[y + 1][x] = temp;

            }
            if ((game_map[y][x] <= Enemy_Weapon && game_map[y][x] >= Enemy_Weapon - 2) && y != Enemy_Arr1_Shoot_Range)
            {
                temp = game_map[y][x];
                game_map[y][x] = AIR;
                game_map[y + 1][x] = temp;

            }
        }
    }
    if (enemy_arr_2)
    {
        for (int i = 0, a = current_map_status.count_all_enemy - 1; i < current_map_status.count_all_enemy && a >= 0; i++, a--)
        {
            x = current_ship_xy->all_enemy_x[i];
            y = current_ship_xy->all_enemy_y[i];

            end_x = current_ship_xy->all_enemy_x[a];
            end_y = current_ship_xy->all_enemy_y[a];


            if (end_x > (COL / 2))
            {
                if ((game_map[end_y][end_x] <= Enemy_Body_Left && game_map[end_y][end_x] >= Enemy_Body_Left - 2)
                    || (game_map[end_y][end_x] <= Enemy_Body_Right && game_map[end_y][end_x] >= Enemy_Body_Right - 2)
                    || (game_map[end_y][end_x] <= Enemy_Head && game_map[end_y][end_x] >= Enemy_Head - 2)
                    || (game_map[end_y][end_x] <= Enemy_Weapon && game_map[end_y][end_x] >= Enemy_Weapon - 2))
                {


                    temp = game_map[end_y][end_x];
                    game_map[end_y][end_x] = AIR;
                    game_map[end_y][end_x + 1] = temp;

                }

            }

            if (x <= (COL / 2))
            {
                if ((game_map[y][x] <= Enemy_Body_Left && game_map[y][x] >= Enemy_Body_Left - 2)
                    || (game_map[y][x] <= Enemy_Body_Right && game_map[y][x] >= Enemy_Body_Right - 2)
                    || (game_map[y][x] <= Enemy_Head && game_map[y][x] >= Enemy_Head - 2)
                    || (game_map[y][x] <= Enemy_Weapon && game_map[y][x] >= Enemy_Weapon - 2))
                {
                    temp = game_map[y][x];
                    game_map[y][x] = AIR;
                    game_map[y][x - 1] = temp;

                }

            }


        }


    }
}

/*if ((game_map[y][x] <= Enemy_Body_Left && game_map[y][x] >= Enemy_Body_Left - 2))
{
if (x > (COL) / 2)
{
temp = game_map[y][x];
game_map[y][x] = AIR;
game_map[y + 1][x] = temp;
}
}
if ((game_map[y][x] <= Enemy_Body_Right && game_map[y][x] >= Enemy_Body_Right - 2))
{
temp = game_map[y][x];
game_map[y][x] = AIR;
game_map[y + 1][x] = temp;

}
if ((game_map[y][x] <= Enemy_Head && game_map[y][x] >= Enemy_Head - 2))
{
temp = game_map[y][x];
game_map[y][x] = AIR;
game_map[y + 1][x] = temp;

}
if ((game_map[y][x] <= Enemy_Weapon && game_map[y][x] >= Enemy_Weapon - 2))
{
temp = game_map[y][x];
game_map[y][x] = AIR;
game_map[y + 1][x] = temp;

}*/