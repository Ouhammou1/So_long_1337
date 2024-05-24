#include "so_long.h"


void	left(t_game *vers, int *nbr )
{
	if(vers->av[vers->pos_ply_x][vers->pos_ply_y ] == 'K')
	{
		vers->pos_ply_y--;
		put_image_with_indices(vers);
		vers->av[vers->pos_ply_x][vers->pos_ply_y ] = 'P';

		vers->pos_ply_y++;
		put_image_exit(vers);
		vers->av[vers->pos_ply_x][vers->pos_ply_y ] = 'E';
		vers->pos_ply_y--;
	}
	else
	{
		if(vers->av[vers->pos_ply_x][vers->pos_ply_y - 1] == 'C')
			nbr--;

		delet_image_with_indices(vers);
		vers->pos_ply_y--;
		put_image_with_indices( vers );
		vers->av[vers->pos_ply_x][vers->pos_ply_y ]= 'P';
		vers->av[vers->pos_ply_x][vers->pos_ply_y +1]= '0';
	}
}

void direct_left(t_game *vers , int *nbr  )
{
    if(vers->av[vers->pos_ply_x][vers->pos_ply_y - 1] == '0'  || vers->av[vers->pos_ply_x][vers->pos_ply_y - 1] == 'C' )
    {
		left(vers , nbr);
    }
    else if(vers->av[vers->pos_ply_x][vers->pos_ply_y - 1] == 'E' && *nbr != 0 )
    {
        delet_image_with_indices(vers);
        vers->pos_ply_y--;
        put_image_with_indices(vers);

        vers->av[vers->pos_ply_x][vers->pos_ply_y] = 'K';
        vers->av[vers->pos_ply_x][vers->pos_ply_y +1] = '0';
    }
    else if (vers->av[vers->pos_ply_x][vers->pos_ply_y - 1] == 'E'  && *nbr == 0 )
    {
        delet_image_with_indices(vers);
        vers->pos_ply_y--;
        put_image_with_indices( vers );
        exit(0); 
    }
}
