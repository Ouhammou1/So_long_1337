/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:56:12 by bouhammo          #+#    #+#             */
/*   Updated: 2024/06/02 22:07:45 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right(t_game *vers, int *nbr)
{
	if (vers->av[vers->pos_ply_x][vers->pos_ply_y] == 'K')
	{
		vers->pos_ply_y++;
		put_image_with_indices(vers);
		vers->av[vers->pos_ply_x][vers->pos_ply_y] = 'P';
		vers->pos_ply_y--;
		put_image_exit(vers);
		vers->av[vers->pos_ply_x][vers->pos_ply_y] = 'E';
		vers->pos_ply_y++;
	}
	else
	{
		if (vers->av[vers->pos_ply_x][vers->pos_ply_y + 1] == 'C')
			nbr--;
		delet_image_with_indices(vers);
		vers->pos_ply_y++;
		put_image_with_indices(vers);
		vers->av[vers->pos_ply_x][vers->pos_ply_y] = 'P';
		vers->av[vers->pos_ply_x][vers->pos_ply_y - 1] = '0';
	}
}

void	direct_right(t_game *vers, int *nbr)
{
	if (vers->av[vers->pos_ply_x][vers->pos_ply_y + 1] == '0'
		|| vers->av[vers->pos_ply_x][vers->pos_ply_y + 1] == 'C')
	{
		right(vers, nbr);
		print_moves(vers);
	}
	else if (vers->av[vers->pos_ply_x][vers->pos_ply_y + 1] == 'E' && *nbr != 0)
	{
		delet_image_with_indices(vers);
		vers->pos_ply_y++;
		put_image_with_indices(vers);
		vers->av[vers->pos_ply_x][vers->pos_ply_y] = 'K';
		vers->av[vers->pos_ply_x][vers->pos_ply_y - 1] = '0';
		print_moves(vers);
	}
	else if (vers->av[vers->pos_ply_x][vers->pos_ply_y + 1] == 'E' && *nbr == 0)
	{
		delet_image_with_indices(vers);
		vers->pos_ply_y++;
		put_image_with_indices(vers);
		print_moves(vers);
		exit(0);
	}
}
