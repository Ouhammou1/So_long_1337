/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:42:30 by bouhammo          #+#    #+#             */
/*   Updated: 2024/05/16 11:42:32 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"


// struct player
// {
//     int x;
//     int y;
//     // void *player;
// };

typedef struct m_l_x
{
    int count_len;
    char **av;
    int x_width;
    int y_height;
    void *img;
    int a;
    int b;
    int len_img_x;
    int len_img_y;
    int len_colon;
    void *mlx;
    void *win;
    int pos_ply_x;
    int pos_ply_y;
} t_game ;









void    check_length(t_game *vers );
void    chack_wall(t_game *vers );
void    check_duplcat_char(t_game *vers );
void    check_caracteres(t_game *vers );
void    check_fil_name(char *s);
void    check_errors_map(t_game *vers );
void    at_least_collect(t_game *vers );


int     len_collect( t_game *vers );

t_game position_player( t_game vers );

void    libriry_m_l_x(t_game *vers );
void    back_img(t_game *vers );
void    collect_point(t_game *vers );
void    player_start(t_game *vers );
void    map_exit(t_game *vers );



void    check_move_ply_to_collcet( t_game vers  );

void    flood_fill(int x  , int y , char     **list);
void    check_collect_exit(char **list,int  count);
// int handle_key(int key, t_game *vers );

void     moves_player(t_game *vers );

int handle_key(int keycode, void *param);


#endif
