#include  "so_long.h"

void right(t_game *vers , int *nbr )
{
	if (vers->av[vers->pos_ply_x][vers->pos_ply_y  ] == 'K')
	{
		vers->pos_ply_y++;
		put_image_with_indices( vers  );
		vers->av[vers->pos_ply_x][vers->pos_ply_y ] = 'P';

		vers->pos_ply_y--;
		put_image_exit(vers ) ; // tape image de exit 
		vers->av[vers->pos_ply_x][vers->pos_ply_y ] = 'E';
		vers->pos_ply_y++;
	}
	else
	{
		if (vers->av[vers->pos_ply_x][vers->pos_ply_y + 1] == 'C')
			nbr--;

		delet_image_with_indices(vers ) ;// tape image bakx
		vers->pos_ply_y++;
		put_image_with_indices( vers  ); // tape image de player 
		vers->av[vers->pos_ply_x][vers->pos_ply_y ] = 'P';
		vers->av[vers->pos_ply_x][vers->pos_ply_y - 1] = '0';
	}
}

void direct_right(t_game *vers ,int *nbr)
{
    if(vers->av[vers->pos_ply_x][vers->pos_ply_y + 1] == '0'  || vers->av[vers->pos_ply_x][vers->pos_ply_y + 1] == 'C' )
    {
		right(vers , nbr);
    }
    else if(vers->av[vers->pos_ply_x][vers->pos_ply_y + 1] == 'E'   && *nbr != 0)
    {
        delet_image_with_indices(vers ) ;
        vers->pos_ply_y++;
        put_image_with_indices( vers  );

        vers->av[vers->pos_ply_x][vers->pos_ply_y ] = 'K';
        vers->av[vers->pos_ply_x][vers->pos_ply_y -1] = '0';
    }
    else if(vers->av[vers->pos_ply_x][vers->pos_ply_y + 1] == 'E'   && *nbr == 0)
    {
            delet_image_with_indices( vers  ); 
            vers->pos_ply_y++;
            put_image_with_indices( vers  );
            exit(0);
    }
}
