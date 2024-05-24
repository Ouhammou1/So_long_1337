#include "so_long.h"


void	 down(t_game  *vers, int *nbr  )
{
        if(vers->av[vers->pos_ply_x ][vers->pos_ply_y] == 'K')
        {
            vers->pos_ply_x++;
            put_image_with_indices(vers);
            vers->av[vers->pos_ply_x][vers->pos_ply_y] = 'P';

            vers->pos_ply_x--;
            put_image_exit(vers);
            vers->av[vers->pos_ply_x][vers->pos_ply_y] = 'E';
            vers->pos_ply_x++;
        }
        else
        {
            if(vers->av[vers->pos_ply_x + 1][vers->pos_ply_y] == 'C')
                nbr--;

            delet_image_with_indices(vers);
            vers->pos_ply_x++;
            put_image_with_indices(vers);
            vers->av[vers->pos_ply_x ][vers->pos_ply_y ] = 'P';
            vers->av[vers->pos_ply_x - 1][vers->pos_ply_y ] = '0';
        }

}


void direct_down(t_game *vers , int *nbr )
{
	
	if(vers->av[vers->pos_ply_x + 1][vers->pos_ply_y] == '0' || vers->av[vers->pos_ply_x + 1][vers->pos_ply_y] == 'C' )
    {
		down(vers,nbr);
    }
    else if( vers->av[vers->pos_ply_x + 1][vers->pos_ply_y] == 'E' && *nbr != 0 )
    {
        vers->pos_ply_x++;
        put_image_with_indices(vers);
        vers->pos_ply_x--;
        delet_image_with_indices(vers);
        vers->av[vers->pos_ply_x][vers->pos_ply_y] = '0';
        vers->pos_ply_x++;
        vers->av[vers->pos_ply_x][vers->pos_ply_y] = 'K';
    }

    else if( vers->av[vers->pos_ply_x +1][vers->pos_ply_y] == 'E' && *nbr == 0 )
    {
            delet_image_with_indices(vers);
            vers->pos_ply_x++;
            put_image_with_indices(vers);
            exit(0);
    }
}
