/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:42:23 by bouhammo          #+#    #+#             */
/*   Updated: 2024/06/07 22:18:43 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	libriry_m_l_x(t_game *vers)
{
	int	i;
	int	j;

	vers->len_img_x = 0;
	vers->len_img_y = 0;
	i = 0;
	while (i < vers->count_len)
	{
		j = 0;
		while (vers->av[i][j])
		{
			if (vers->av[i][j] == '1')
				mlx_put_image_to_window(vers->mlx, vers->win, vers->img_1,
					vers->len_img_x, vers->len_img_y);
			vers->len_img_x += vers->a;
			j++;
		}
		vers->len_img_y += vers->b;
		vers->len_img_x = 0;
		i++;
	}
	collect_point(vers);
	player_start(vers);
	map_exit(vers);
	check_move_ply_to_collcet(*vers);
}

char	*get_line(t_game *vers, int fd)
{
	char	*str;
	char	*ptr;

	str = get_next_line(fd);
	if (!str)
	{
		write(1, "Error\nEmpty map", 15);
		exit(1);
	}
	vers->count_len = 0;
	while (str != NULL)
	{
		ptr = ft_strjoin(ptr, str);
		free(str);
		str = get_next_line(fd);
		vers->count_len++;
	}
	free(str);
	return (ptr);
}

void	join_string(t_game *vers, char *s)
{
	int		fd;
	char	*ptr;

	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error\nFile Not Found\n", 22);
		exit(1);
	}
	check_fil_name(vers, s);
	ptr = get_line(vers, fd);
	vers->av = ft_split(ptr, '\n');
	vers->map = ft_split(ptr, '\n');
	close(fd);
	free(ptr);
}

void	size_image(t_game *vers)
{
	vers->img_1 = mlx_xpm_file_to_image(vers->mlx, PATH, &vers->a, &vers->b);
	if (vers->img_1 == NULL)
	{
		write(1, "Error\nFailed to load image : wall.xpm", 38);
		exit(1);
	}
	vers->x_width = vers->a * vers->len_colon;
	vers->y_height = vers->b * vers->count_len;
}

int	main(int ac, char **av)
{
	t_game	*vers;

	if (ac != 2)
		exit(0);
	vers = NULL;
	vers = (t_game *)malloc(sizeof(t_game));
	if (!vers)
		return (0);
	join_string(vers, av[1]);
	check_errors_map(vers);
	vers->len_colon = ft_strlen(vers->av[1]);
	vers->mlx = mlx_init();
	size_image(vers);
	vers->win = mlx_new_window(vers->mlx, vers->x_width, vers->y_height,
			"SO_LOOONG");
	check_image(vers);
	libriry_m_l_x(vers);
	back_img(vers);
	mlx_key_hook(vers->win, handle_key, vers);
	mlx_hook(vers->win, 17, 0, handle_close, vers);
	mlx_loop(vers->mlx);
	mlx_destroy_window(vers->mlx, vers->win);
	ft_free(vers);
	return (0);
}
