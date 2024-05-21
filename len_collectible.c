#include "so_long.h" 

int len_collect(t_game  *vers )
{
    int i ;
    int j ;
    int nbr;

    i = 0;
    nbr = 0;
    while ( i < vers->count_len )
    {
        j=0;
        while (vers->av[i][j])
        {
            if(vers->av[i][j] == 'c')
                nbr++;
            j++;
        }
        i++;
    }

    return nbr;
}


t_game  position_player( t_game vers )
{
    int i=0;
    while (i < vers.count_len)
    {
        int j= 0;
        while (vers.av[i][j])
        {
            if(vers.av[i][j] == 'P')
            {
               vers.pos_ply_x = i;
               vers.pos_ply_y = j;
                break;
            }
            j++;
        }
        i++;
    }
    return vers ;
}
void    at_least_collect( t_game *vers  )
{
    int i ;
    int j ;
    int nbr;

    i = 0;
    nbr = 0;
    while ( i < vers->count_len )
    {
        j=0;
        while (vers->av[i][j])
        {
            if(vers->av[i][j] == 'C')
                nbr++;
            j++;
        }
        i++;
    }
    if(nbr == 0)
    {
        printf("at _least one collect ");
        exit(0);
    }
}