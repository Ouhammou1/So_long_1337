/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:15:12 by bouhammo          #+#    #+#             */
/*   Updated: 2024/06/07 22:15:44 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_close(void *param)
{
	t_game	*vers;

	vers = param;
	ft_free(vers);
	exit(1);
	return (0);
}

void	ft_free(t_game *vers)
{
	int	i;

	i = 0;
	if (vers->av != NULL)
	{
		while (vers->av[i] != NULL)
		{
			free(vers->av[i]);
			i++;
		}
		free(vers->av);
	}
	i = 0;
	if (vers->map != NULL)
	{
		while (vers->map[i] != NULL)
		{
			free(vers->map[i]);
			i++;
		}
		free(vers->map);
	}
	free(vers);
}

void	ft_putstr(t_game *vers, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	ft_free(vers);
	mlx_destroy_window(vers->mlx, vers->win);
	exit(1);
}

void	ft_write(t_game *vers, char *s)
{
	int	i;

	(void)vers;
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	ft_free(vers);
	exit(1);
}
