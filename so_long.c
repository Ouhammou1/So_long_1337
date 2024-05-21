/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:42:23 by bouhammo          #+#    #+#             */
/*   Updated: 2024/05/16 11:42:25 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void    check_errors_map(t_game *vers )
{
    check_length(vers );
    chack_wall(vers );
    check_caracteres(vers );
    check_duplcat_char(vers );
    at_least_collect(vers );
}


void    libriry_m_l_x(t_game *vers )
{
    int i = 0;

    // back_img( vers );

    vers->len_img_x = 0;
    vers->len_img_y = 0;

    // printf("vers .count_len ====   %d\n",vers->count_len);

    while (i < vers->count_len)
    {
        int j =0;
        while (vers->av[i][j])
        {
            if( vers->av[i][j] == '1')
            {
                 mlx_put_image_to_window(vers->mlx, vers->win, vers->img, vers->len_img_x , vers->len_img_y);
            }
            vers->len_img_x+=vers->a;
            j++;
        }
        vers->len_img_y+=vers->b;
        vers->len_img_x = 0;
        i++;
    }
    // back_img( vers );

    collect_point(vers );
    player_start(vers );
    map_exit( vers );

    check_move_ply_to_collcet( *vers );


    // moves_player( vers );

    // printf(" x = %d \n y = %d \n", new.a, new.b);

    // mlx_key_hook(vers .win , handle_key , NULL);

}


int main(int ac, char **av)
{
    (void)ac;
    char *str;
    int fd;
    char *ptr;

    check_fil_name(av[1]);

    t_game *vers = NULL ;
    vers = (t_game *)malloc(sizeof(t_game));
    if (!vers)
        return 1;

    fd = open(av[1], O_RDONLY);
    str = get_next_line(fd);
    vers->count_len =0;
    while (str != NULL)
    {
        ptr = ft_strjoin(ptr,str);
        str = get_next_line(fd);
        vers->count_len++;
    }

    vers->av = ft_split(ptr,'\n');

    check_errors_map(vers );



    vers->len_colon = ft_strlen(vers->av[1]);

    
    vers->mlx = mlx_init();
    vers->img = mlx_xpm_file_to_image(vers->mlx, "./image/uu/wall.xpm", &vers->a , &vers->b);

    vers->x_width = vers->a * vers->len_colon;
    vers->y_height = vers->b * vers->count_len;


    vers->win = mlx_new_window(vers->mlx, vers->x_width ,vers->y_height ,"SO_LOOOOONG");   

    libriry_m_l_x( vers );

    mlx_key_hook(vers->win, handle_key, vers);

    mlx_loop(vers->mlx);

    free(vers);

return 0;
}
