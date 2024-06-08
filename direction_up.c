/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:53:30 by bouhammo          #+#    #+#             */
/*   Updated: 2024/05/24 14:53:32 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_game *vers, int *nbr)
{
	if (vers->av[vers->pos_ply_x][vers->pos_ply_y] == 'K')
	{
		vers->pos_ply_x--;
		put_image_with_indices(vers);
		vers->av[vers->pos_ply_x][vers->pos_ply_y] = 'P';
		vers->pos_ply_x++;
		put_image_exit(vers);
		vers->av[vers->pos_ply_x][vers->pos_ply_y] = 'E';
	}
	else
	{
		if (vers->av[vers->pos_ply_x - 1][vers->pos_ply_y] == 'C')
			nbr--;
		delet_image_with_indices(vers);
		vers->pos_ply_x--;
		put_image_with_indices(vers);
		vers->av[vers->pos_ply_x][vers->pos_ply_y] = 'P';
		vers->av[vers->pos_ply_x + 1][vers->pos_ply_y] = '0';
	}
}

void	direct_up(t_game *vers, int *nbr)
{
	if (vers->av[vers->pos_ply_x - 1][vers->pos_ply_y] == '0'
		|| vers->av[vers->pos_ply_x - 1][vers->pos_ply_y] == 'C')
	{
		up(vers, nbr);
		print_moves(vers);
	}
	else if (vers->av[vers->pos_ply_x - 1][vers->pos_ply_y] == 'E' && *nbr != 0)
	{
		vers->pos_ply_x--;
		put_image_with_indices(vers);
		vers->pos_ply_x++;
		delet_image_with_indices(vers);
		vers->av[vers->pos_ply_x][vers->pos_ply_y] = '0';
		vers->pos_ply_x--;
		vers->av[vers->pos_ply_x][vers->pos_ply_y] = 'K';
		print_moves(vers);
	}
	else if (vers->av[vers->pos_ply_x - 1][vers->pos_ply_y] == 'E' && *nbr == 0)
	{
		delet_image_with_indices(vers);
		vers->pos_ply_x--;
		put_image_with_indices(vers);
		print_moves(vers);
		exit(0);
	}
}
