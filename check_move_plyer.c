#include "so_long.h"

void    check_collect_exit(char **list,int  count)
{
    int i =0;
    int j =0;
    while (i < count)
    {
        j =0;
        while (list[i][j])
        {
            if( list[i][j] == 'C' || list[i][j] == 'E')
            {
                printf("Votre Map Inccorct !\n");
                exit(0);
            }
            j++;
        }
        i++;
    }
}

void     flood_fill(int x  , int y, char     **list)
{   
    if(list[x][y] != 'P')
    {
        if(list[x][y] != 'E' && list[x][y] != 'C' && list[x][y] != '0')
            return ;
        else
        {
            if (list[x][y] == 'E')
                list[x][y] = 'e';
            if (list[x][y] == 'C')
                list[x][y] = 'c';
            if (list[x][y] == '0')
                list[x][y] = 'X';
        }
    }

    flood_fill(x - 1 , y, list);
    flood_fill(x + 1 , y, list);
    flood_fill(x , y + 1, list);
    flood_fill(x , y - 1, list);
    return ;
    
}



void    check_move_ply_to_collcet( t_game  vers )
{
    t_game new;
    new = vers;
    new = position_player(vers);

    flood_fill(new.pos_ply_x  , new.pos_ply_y , new.map);
    check_collect_exit(new.map , new.count_len);     
}
