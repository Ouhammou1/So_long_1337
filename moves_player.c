#include "so_long.h"


void	delet_image_with_indices(t_game *vers ) 
{
    vers->len_colon = ft_strlen(vers->av[0]);
    vers->img = mlx_xpm_file_to_image(vers->img, "./image/test/back.xpm", &vers->a, &vers->b);

    vers->len_img_x = vers->a *  vers->pos_ply_y ;
    vers->len_img_y = vers->b *  vers->pos_ply_x ;
    mlx_put_image_to_window(vers->mlx, vers->win, vers->img, vers->len_img_x, vers->len_img_y);

}

void	put_image_with_indices(t_game *vers ) 
{
    vers->len_colon = ft_strlen(vers->av[0]);
    vers->img = mlx_xpm_file_to_image(vers->img, "./image/test/play.xpm", &vers->a, &vers->b);

    vers->len_img_x = vers->a * vers->pos_ply_y ;
    vers->len_img_y = vers->b *  vers->pos_ply_x ;
    mlx_put_image_to_window(vers->mlx, vers->win, vers->img, vers->len_img_x, vers->len_img_y);
}

void	put_image_exit(t_game *vers ) 
{
    vers->len_colon = ft_strlen(vers->av[0]);
    vers->img = mlx_xpm_file_to_image(vers->img, "./image/test/exit.xpm", &vers->a, &vers->b);

    vers->len_img_x = vers->a *  vers->pos_ply_y ;
    vers->len_img_y = vers->b *  vers->pos_ply_x ;
    mlx_put_image_to_window(vers->mlx, vers->win, vers->img, vers->len_img_x, vers->len_img_y);
   
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
    if(keycode == 0 || keycode == 123)
        direct_left(vers , &nbr_collect);

    if(keycode == 1  || keycode == 125)
        direct_down(vers , &nbr_collect);

    if(keycode == 2 || keycode == 124 )
        direct_right(vers , &nbr_collect);

    if(keycode == 13 || keycode == 126 )
        direct_up(vers , &nbr_collect);
    return 0;
}

