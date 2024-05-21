
#include "so_long.h"

void    back_img(t_game  *vers )
{ 
    
    int i =0;

    vers->len_colon = ft_strlen(vers->av[0]);
    vers->img = mlx_xpm_file_to_image( vers->img , "./image/image1.xpm" , &vers->a, &vers->b);

    vers->len_img_x = 0;
    vers->len_img_y = 0;
    while (i < vers->count_len)
    {
        int j =0;
        while (vers->av[i][j] != '\0')
        {
                mlx_put_image_to_window(vers->mlx, vers->win, vers->img, vers->len_img_x , vers->len_img_y);
                vers->len_img_x+=vers->a;

            j++;
        }
        vers->len_img_y+=vers->b;
        vers->len_img_x = 0;
        i++;
    }
}

void collect_point(t_game * vers )
{
    int i =0;

    vers->img = mlx_xpm_file_to_image(vers->mlx, "./image/uu/collect.xpm", &vers->a, &vers->b);

    vers->len_img_x = 0;
    vers->len_img_y = 0;

    while (i < vers->count_len)
    {
        int j =0;
        while (vers->av[i][j])
        {
            if(vers->av[i][j] == 'C')
                mlx_put_image_to_window(vers->mlx, vers->win, vers->img, vers->len_img_x, vers->len_img_y);

            vers->len_img_x +=vers->a;
            j++;
        }
        vers->len_img_y+=vers->b;
        vers->len_img_x = 0;
        i++;
    }
}
void player_start(t_game *vers )
{
    int i =0;

    vers->img = mlx_xpm_file_to_image(vers->mlx, "./image/uu/2.xpm" , &vers->a, &vers->b);

// printf("%d ================== \n",vers->a);
// printf("%d ================== \n",vers->b);
    vers->len_img_x = 0;
    vers->len_img_y = 0;
    while ( i < vers->count_len )
    {
        int j =0;
        while (vers->av[i][j])
        {
            if(vers->av[i][j] == 'P')
            {
                mlx_put_image_to_window(vers->mlx, vers->win ,vers->img ,vers->len_img_x, vers->len_img_y);
            }
            vers->len_img_x += vers->a;
            j++;
        }
        vers->len_img_y +=vers->b;
        vers->len_img_x= 0;
        i++;
    } 
}

void map_exit(t_game *vers )
{
    int i =0;
    vers->img = mlx_xpm_file_to_image(vers->img, "./image/uu/exit.xpm", &vers->a, &vers->b);

    vers->len_img_x = 0;
    vers->len_img_y = 0;

    while (i < vers->count_len )
    {
        int j =0;
        while (vers->av[i][j])
        {
            if( vers->av[i][j]  == 'E')
                mlx_put_image_to_window(vers->mlx, vers->win, vers->img, vers->len_img_x, vers->len_img_y);
            j++;
            vers->len_img_x+= vers->a;
        }
        vers->len_img_y+=vers->b;
        vers->len_img_x=0;
        i++;        
    }
}


