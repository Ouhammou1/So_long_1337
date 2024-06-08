/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_collectible.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:54:17 by bouhammo          #+#    #+#             */
/*   Updated: 2024/06/07 21:35:08 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_collect(t_game *vers)
{
	int	i;
	int	j;
	int	nbr;

	i = 0;
	nbr = 0;
	while (i < vers->count_len)
	{
		j = 0;
		while (vers->av[i][j])
		{
			if (vers->av[i][j] == 'C')
				nbr++;
			j++;
		}
		i++;
	}
	return (nbr);
}

t_game	position_player(t_game vers)
{
	int	i;
	int	j;

	i = 0;
	while (i < vers.count_len)
	{
		j = 0;
		while (vers.av[i][j])
		{
			if (vers.av[i][j] == 'P')
			{
				vers.pos_ply_x = i;
				vers.pos_ply_y = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (vers);
}

void	at_least_collect(t_game *vers)
{
	int	i;
	int	j;
	int	nbr;

	i = 0;
	nbr = 0;
	while (i < vers->count_len)
	{
		j = 0;
		while (vers->av[i][j])
		{
			if (vers->av[i][j] == 'C')
				nbr++;
			j++;
		}
		i++;
	}
	if (nbr == 0)
		ft_write(vers, "Error\nAt least one collect \n");
}
