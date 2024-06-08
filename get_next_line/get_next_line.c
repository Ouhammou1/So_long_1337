/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:24:32 by bouhammo          #+#    #+#             */
/*   Updated: 2024/03/28 00:24:41 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_return_line(char *ptr)
{
	int		i;
	char	*str;

	if (ptr[0] == '\0')
		return (NULL);
	i = 0;
	while (ptr[i] != '\0' && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\n')
		i++;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (ptr[++i] != '\0' && ptr[i] != '\n')
		str[i] = ptr[i];
	if (ptr[i] == '\n')
	{
		str[i] = ptr[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_read_string(int fd, char *string)
{
	int		nbr;
	char	*buff;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	nbr = 1;
	while (!ft_strchar(string, '\n') && nbr > 0)
	{
		nbr = read(fd, buff, BUFFER_SIZE);
		if (nbr == -1)
		{
			free(buff);
			buff = NULL;
			return (NULL);
		}
		buff[nbr] = '\0';
		string = ft_strjoin(string, buff);
	}
	free(buff);
	buff = NULL;
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) == -1)
	{
		free(string);
		string = NULL;
		return (NULL);
	}
	string = ft_read_string(fd, string);
	if (string == NULL)
	{
		return (NULL);
	}
	line = ft_return_line(string);
	string = ft_last_line(string);
	return (line);
}
