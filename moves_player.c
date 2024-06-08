/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:54:31 by bouhammo          #+#    #+#             */
/*   Updated: 2024/06/06 22:41:50 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delet_image_with_indices(t_game *vers)
{
	vers->img_2 = mlx_xpm_file_to_image(vers->img_2, PATH_1, &vers->a,
			&vers->b);
	vers->len_img_x = vers->a * vers->pos_ply_y;
	vers->len_img_y = vers->b * vers->pos_ply_x;
	mlx_put_image_to_window(vers->mlx, vers->win, vers->img_2, vers->len_img_x,
		vers->len_img_y);
}

void	put_image_with_indices(t_game *vers)
{
	vers->img_6 = mlx_xpm_file_to_image(vers->img_6, PATH_5, &vers->a,
			&vers->b);
	vers->len_img_x = vers->a * vers->pos_ply_y;
	vers->len_img_y = vers->b * vers->pos_ply_x;
	mlx_put_image_to_window(vers->mlx, vers->win, vers->img_6, vers->len_img_x,
		vers->len_img_y);
}

void	put_image_exit(t_game *vers)
{
	vers->img_4 = mlx_xpm_file_to_image(vers->img_4, PATH_4, &vers->a,
			&vers->b);
	vers->len_img_x = vers->a * vers->pos_ply_y;
	vers->len_img_y = vers->b * vers->pos_ply_x;
	mlx_put_image_to_window(vers->mlx, vers->win, vers->img_4, vers->len_img_x,
		vers->len_img_y);
}

void	print_moves(t_game *vers)
{
	write(1, "Moves : ", 8);
	vers->count_mov++;
	ft_putnbr(vers->count_mov);
	ft_putchar('\n');
}

int	handle_key(int keycode, void *param)
{
	t_game	*vers;
	t_game	pos;
	int		nbr_collect;

	vers = param;
	pos = position_player(*vers);
	nbr_collect = len_collect(vers);
	vers->pos_ply_x = pos.pos_ply_x;
	vers->pos_ply_y = pos.pos_ply_y;
	if (keycode == 53)
	{
		ft_free(vers);
		exit(0);
	}
	if (keycode == 0 || keycode == 123)
		direct_left(vers, &nbr_collect);
	if (keycode == 1 || keycode == 125)
		direct_down(vers, &nbr_collect);
	if (keycode == 2 || keycode == 124)
		direct_right(vers, &nbr_collect);
	if (keycode == 13 || keycode == 126)
		direct_up(vers, &nbr_collect);
	return (0);
}
