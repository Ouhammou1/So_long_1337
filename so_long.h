/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:42:30 by bouhammo          #+#    #+#             */
/*   Updated: 2024/06/07 22:12:39 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>

# define PATH "./textures/wall.xpm"
# define PATH_1 "./textures/back.xpm"
# define PATH_2 "./textures/collect.xpm"
# define PATH_3 "./textures/player_back.xpm"
# define PATH_4 "./textures/exit.xpm"
# define PATH_5 "./textures/play.xpm"

typedef struct m_l_x
{
	int		count_len;
	char	**av;
	char	**map;
	int		x_width;
	int		y_height;
	int		a;
	int		b;
	int		len_img_x;
	int		len_img_y;
	int		len_colon;
	void	*mlx;
	void	*win;
	int		pos_ply_x;
	int		pos_ply_y;
	int		count_mov;
	void	*img_1;
	void	*img_2;
	void	*img_3;
	void	*img_4;
	void	*img_5;
	void	*img_6;

}			t_game;
char		*get_line(t_game *vers, int fd);
void		join_string(t_game *vers, char *s);

void		check_length(t_game *vers);
void		chack_wall(t_game *vers);
void		check_duplcat_char(t_game *vers);
void		check_caracteres(t_game *vers);
void		check_fil_name(t_game *vers, char *s);
void		check_errors_map(t_game *vers);
void		at_least_collect(t_game *vers);
void		check_image(t_game *vers);

int			len_collect(t_game *vers);

t_game		position_player(t_game vers);

void		libriry_m_l_x(t_game *vers);
void		back_img(t_game *vers);
void		collect_point(t_game *vers);
void		player_start(t_game *vers);
void		map_exit(t_game *vers);

void		flood_fill(int x, int y, char **list);
void		check_collect_exit(char **list, int count);

void		moves_player(t_game *vers);

void		check_move_ply_to_collcet(t_game vers);

int			handle_key(int keycode, void *param);
int			handle_close(void *param);

void		delet_image_with_indices(t_game *vers);
void		put_image_with_indices(t_game *vers);
void		put_image_exit(t_game *vers);

void		direct_down(t_game *vers, int *nbr);
void		down(t_game *vers, int *nbr);

void		direct_up(t_game *vers, int *nbr);
void		up(t_game *vers, int *nbr);

void		direct_left(t_game *vers, int *nbr);
void		left(t_game *vers, int *nbr);

void		direct_right(t_game *vers, int *nbr);
void		right(t_game *vers, int *nbr);

void		print_moves(t_game *vers);

void		ft_putstr(t_game *vers, char *s);
void		ft_write(t_game *vers, char *s);

void		ft_free(t_game *vers);

#endif