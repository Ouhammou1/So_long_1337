/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move_plyer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:53:18 by bouhammo          #+#    #+#             */
/*   Updated: 2024/06/07 20:34:37 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_errors_map(t_game *vers)
{
	check_length(vers);
	chack_wall(vers);
	check_caracteres(vers);
	check_duplcat_char(vers);
	at_least_collect(vers);
}

void	check_collect_exit(char **list, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count)
	{
		j = 0;
		while (list[i][j])
		{
			if (list[i][j] == 'C' || list[i][j] == 'E')
			{
				write(1, "Error\nIncorrect map!\n", 22);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(int x, int y, char **list)
{
	if (list[x][y] != 'P')
	{
		if (list[x][y] != 'E' && list[x][y] != 'C' && list[x][y] != '0')
			return ;
		else
		{
			if (list[x][y] == 'E')
				list[x][y] = 'e';
			if (list[x][y] == 'C')
				list[x][y] = 'c';
			if (list[x][y] == '0')
				list[x][y] = 'X';
		}
	}
	flood_fill(x - 1, y, list);
	flood_fill(x + 1, y, list);
	flood_fill(x, y + 1, list);
	flood_fill(x, y - 1, list);
	return ;
}

void	check_move_ply_to_collcet(t_game vers)
{
	t_game	new;

	new = vers;
	new = position_player(vers);
	flood_fill(new.pos_ply_x, new.pos_ply_y, new.map);
	check_collect_exit(new.map, new.count_len);
}
