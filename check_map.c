/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:55:56 by bouhammo          #+#    #+#             */
/*   Updated: 2024/06/07 22:18:22 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_fil_name(t_game *vers, char *s)
{
	int	len;

	len = ft_strlen(s) - 1;
	while (len >= 0)
	{
		if (s[len] == '.')
		{
			if (ft_strcmp(s + len, ".ber") == 0)
			{
				return ;
			}
			else
			{
				write(1, "Error\nThe File Name  \n", 23);
				free(vers);
				exit(0);
			}
		}
		len--;
	}
	write(1, "Error\nThe File Name  \n", 23);
	free(vers);
	exit(0);
}

void	check_caracteres(t_game *vers)
{
	int	i;
	int	j;

	i = 0;
	while (i < vers->count_len)
	{
		j = 0;
		while (vers->map[i][j])
		{
			if (vers->map[i][j] != '1' && vers->map[i][j] != '0'
				&& vers->map[i][j] != 'P' && vers->map[i][j] != 'E'
				&& vers->map[i][j] != 'C')
			{
				ft_write(vers, "Error\nYour Character is incorrect\n");
			}
			j++;
		}
		i++;
	}
}

void	check_duplcat_char(t_game *vers)
{
	int	i;
	int	j;
	int	p;
	int	e;

	i = 0;
	e = 0;
	p = 0;
	while (i < vers->count_len)
	{
		j = 0;
		while (vers->map[i][j])
		{
			if (vers->map[i][j] == 'P')
				p++;
			if (vers->map[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (p != 1 || e != 1)
	{
		ft_write(vers, "Error\nFor E or P \n");
	}
}

void	chack_wall(t_game *vers)
{
	int	i;
	int	j;

	vers->len_colon = ft_strlen(vers->map[0]) - 1;
	i = 0;
	j = 0;
	while (vers->map[i][j])
	{
		if (vers->map[i][j] != '1' || vers->map[vers->count_len - 1][j] != '1')
		{
			ft_write(vers, "Error\nYour wall is wrong\n");
		}
		j++;
	}
	i = 0;
	j = 0;
	while (i < vers->count_len)
	{
		if (vers->map[i][j] != '1' || vers->map[i][vers->len_colon] != '1')
		{
			ft_write(vers, "Error\nYour wall is wrong\n");
		}
		i++;
	}
}

void	check_length(t_game *vers)
{
	int	i;

	vers->len_colon = ft_strlen(vers->map[0]);
	if (vers->len_colon > 51)
	{
		ft_write(vers, "Error\nYour map is long\n");
	}
	i = 0;
	while (i < vers->count_len)
	{
		if (vers->len_colon != ft_strlen(vers->map[i]))
		{
			ft_write(vers, "Error\nLength \n");
		}
		vers->len_colon = ft_strlen(vers->map[i]);
		i++;
	}
	if (vers->count_len > 28)
		ft_write(vers, "Error\nYour map is long\n");
}
