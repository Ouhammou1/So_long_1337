#include "so_long.h"

#include <mlx.h>
void	delet_image_with_indices(t_game *vers ) 
{
    vers->len_colon = ft_strlen(vers->av[0]);
    vers->img = mlx_xpm_file_to_image(vers->img, "./image/uu/new.xpm", &vers->a, &vers->b);

    vers->len_img_x = vers->a *  vers->pos_ply_y ;
    vers->len_img_y = vers->b *  vers->pos_ply_x ;
    mlx_put_image_to_window(vers->mlx, vers->win, vers->img, vers->len_img_x, vers->len_img_y);

}

void	put_image_with_indices(t_game *vers ) 
{
    vers->len_colon = ft_strlen(vers->av[0]);
    vers->img = mlx_xpm_file_to_image(vers->img, "./image/uu/2.xpm", &vers->a, &vers->b);

    vers->len_img_x = vers->a * vers->pos_ply_y ;
    vers->len_img_y = vers->b *  vers->pos_ply_x ;
    mlx_put_image_to_window(vers->mlx, vers->win, vers->img, vers->len_img_x, vers->len_img_y);
}


void direct_right(t_game *vers ,int *nbr)
{
    if(vers->av[vers->pos_ply_x][vers->pos_ply_y + 1] == 'X'  || vers->av[vers->pos_ply_x][vers->pos_ply_y + 1] == 'c')
    {
        if (vers->av[vers->pos_ply_x][vers->pos_ply_y + 1] == 'c')
        {
            nbr--;
        }
        
        delet_image_with_indices(vers ) ;
        vers->pos_ply_y++;
        put_image_with_indices( vers  );
        vers->av[vers->pos_ply_x][vers->pos_ply_y ]= 'P';
        vers->av[vers->pos_ply_x][vers->pos_ply_y -1]= 'X';
    }
    if(vers->av[vers->pos_ply_x][vers->pos_ply_y + 1] == 'e'   && *nbr == 0)
    {
            delet_image_with_indices(vers ) ;
            vers->pos_ply_y++;
            put_image_with_indices( vers  );
            exit(0);
    }
}
void direct_left(t_game *vers , int *nbr  )
{
    if(vers->av[vers->pos_ply_x][vers->pos_ply_y - 1] == 'X'  || vers->av[vers->pos_ply_x][vers->pos_ply_y - 1] == 'c' )
    {
        if(vers->av[vers->pos_ply_x][vers->pos_ply_y - 1] == 'c')
        {
            nbr--;
        }
        delet_image_with_indices(vers);
        vers->pos_ply_y--;
        put_image_with_indices( vers );
        vers->av[vers->pos_ply_x][vers->pos_ply_y ]= 'P';
        vers->av[vers->pos_ply_x][vers->pos_ply_y +1]= 'X';
    }
    if(vers->av[vers->pos_ply_x][vers->pos_ply_y - 1] == 'e'  && *nbr == 0 )
    {
            delet_image_with_indices(vers);
            vers->pos_ply_y--;
            put_image_with_indices( vers );
            exit(0); 
    }
}
void direct_up(t_game *vers, int *nbr)
{

    if(vers->av[vers->pos_ply_x - 1][vers->pos_ply_y] == 'X' || vers->av[vers->pos_ply_x - 1][vers->pos_ply_y] == 'c')
    {
        if (vers->av[vers->pos_ply_x - 1][vers->pos_ply_y] == 'c')
        {
            nbr--;
        }
        
        delet_image_with_indices(vers);
        vers->pos_ply_x--;
        put_image_with_indices(vers);
        vers->av[vers->pos_ply_x ][vers->pos_ply_y ] = 'P';
        vers->av[vers->pos_ply_x +1][vers->pos_ply_y ] = 'X';
    }
    if (vers->av[vers->pos_ply_x - 1][vers->pos_ply_y] == 'e' && *nbr  == 0 )
    {
            delet_image_with_indices(vers);
            vers->pos_ply_x--;
            put_image_with_indices(vers);
            exit(0);
    }
}

void direct_down(t_game *vers , int *nbr )
{

    if(vers->av[vers->pos_ply_x + 1][vers->pos_ply_y] == 'X' || vers->av[vers->pos_ply_x + 1][vers->pos_ply_y] == 'c' )
    {
        if(vers->av[vers->pos_ply_x + 1][vers->pos_ply_y] == 'c')
        {
            nbr--;
        }
        delet_image_with_indices(vers);
        vers->pos_ply_x++;
        put_image_with_indices(vers);
        vers->av[vers->pos_ply_x ][vers->pos_ply_y ] = 'P';
        vers->av[vers->pos_ply_x - 1][vers->pos_ply_y ] = 'X';
    }
    if( vers->av[vers->pos_ply_x +1][vers->pos_ply_y] == 'e' && *nbr == 0 )
    {
            delet_image_with_indices(vers);
            vers->pos_ply_x++;
            put_image_with_indices(vers);
            exit(0);
    }
}

int handle_key(int keycode, void *param)
{
    t_game      *vers;
    t_game      pos;
    int nbr_collect;
    vers = param;
    pos  = position_player( *vers);
    nbr_collect =  len_collect(vers);

    vers->pos_ply_x = pos.pos_ply_x ;
    vers->pos_ply_y = pos.pos_ply_y ; 
    printf("keycode : %d\n",keycode);
    if(keycode == 53 )
        exit(0);
    if(keycode == 2 )
        direct_right(vers , &nbr_collect);
    if(keycode == 0 )
        direct_left(vers , &nbr_collect);
    if(keycode == 13 )
        direct_up(vers , &nbr_collect);
    if(keycode == 1 )
        direct_down(vers , &nbr_collect);

    return 0;
}

