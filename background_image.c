/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:54:47 by bouhammo          #+#    #+#             */
/*   Updated: 2024/06/07 20:27:16 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	back_img(t_game *vers)
{
	int	i;
	int	j;

	i = 0;
	vers->img_2 = mlx_xpm_file_to_image(vers->mlx, PATH_1, &vers->a, &vers->b);
	vers->len_img_x = 0;
	vers->len_img_y = 0;
	while (i < vers->count_len)
	{
		j = 0;
		while (vers->av[i][j] != '\0')
		{
			if (vers->av[i][j] == '0')
			{
				mlx_put_image_to_window(vers->mlx, vers->win, vers->img_2,
					vers->len_img_x, vers->len_img_y);
			}
			vers->len_img_x += vers->a;
			j++;
		}
		vers->len_img_y += vers->b;
		vers->len_img_x = 0;
		i++;
	}
	vers->count_mov = 0;
}

void	collect_point(t_game *vers)
{
	int	i;
	int	j;

	i = 0;
	vers->img_3 = mlx_xpm_file_to_image(vers->mlx, PATH_2, &vers->a, &vers->b);
	vers->len_img_x = 0;
	vers->len_img_y = 0;
	while (i < vers->count_len)
	{
		j = 0;
		while (vers->av[i][j])
		{
			if (vers->av[i][j] == 'C')
				mlx_put_image_to_window(vers->mlx, vers->win, vers->img_3,
					vers->len_img_x, vers->len_img_y);
			vers->len_img_x += vers->a;
			j++;
		}
		vers->len_img_y += vers->b;
		vers->len_img_x = 0;
		i++;
	}
}

void	player_start(t_game *vers)
{
	int	i;
	int	j;

	i = 0;
	vers->img_4 = mlx_xpm_file_to_image(vers->mlx, PATH_3, &vers->a, &vers->b);
	vers->len_img_x = 0;
	vers->len_img_y = 0;
	while (i < vers->count_len)
	{
		j = 0;
		while (vers->av[i][j])
		{
			if (vers->av[i][j] == 'P')
			{
				mlx_put_image_to_window(vers->mlx, vers->win, vers->img_4,
					vers->len_img_x, vers->len_img_y);
			}
			vers->len_img_x += vers->a;
			j++;
		}
		vers->len_img_y += vers->b;
		vers->len_img_x = 0;
		i++;
	}
}

void	map_exit(t_game *vers)
{
	int	i;
	int	j;

	i = 0;
	vers->img_5 = mlx_xpm_file_to_image(vers->img_5, PATH_4, &vers->a,
			&vers->b);
	vers->len_img_x = 0;
	vers->len_img_y = 0;
	while (i < vers->count_len)
	{
		j = 0;
		while (vers->av[i][j])
		{
			if (vers->av[i][j] == 'E')
				mlx_put_image_to_window(vers->mlx, vers->win, vers->img_5,
					vers->len_img_x, vers->len_img_y);
			j++;
			vers->len_img_x += vers->a;
		}
		vers->len_img_y += vers->b;
		vers->len_img_x = 0;
		i++;
	}
}

void	check_image(t_game *vers)
{
	vers->img_1 = mlx_xpm_file_to_image(vers->mlx, PATH, &vers->a, &vers->b);
	if (vers->img_1 == NULL)
		ft_putstr(vers, "Error\nFailed to load image  : wall.xpm\n");
	vers->img_2 = mlx_xpm_file_to_image(vers->mlx, PATH_1, &vers->a, &vers->b);
	if (vers->img_2 == NULL)
		ft_putstr(vers, "Error\nFailed to load image  : back.xpm\n");
	vers->img_3 = mlx_xpm_file_to_image(vers->mlx, PATH_2, &vers->a, &vers->b);
	if (vers->img_3 == NULL)
		ft_putstr(vers, "Error\nFailed to load image : collect.xpm\n");
	vers->img_4 = mlx_xpm_file_to_image(vers->mlx, PATH_4, &vers->a, &vers->b);
	if (vers->img_4 == NULL)
		ft_putstr(vers, "Error\nFailed to load image : exit.xpm");
	vers->img_5 = mlx_xpm_file_to_image(vers->mlx, PATH_5, &vers->a, &vers->b);
	if (vers->img_5 == NULL)
		ft_putstr(vers, "Error\nFailed to load image : play.xpm\n");
	vers->img_6 = mlx_xpm_file_to_image(vers->mlx, PATH_3, &vers->a, &vers->b);
	if (vers->img_6 == NULL)
		ft_putstr(vers, "Error\nFailed to load image : player_back.xpm\n");
}
