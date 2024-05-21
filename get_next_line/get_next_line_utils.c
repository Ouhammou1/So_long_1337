/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:25:17 by bouhammo          #+#    #+#             */
/*   Updated: 2024/03/28 16:49:52 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *ptr)
{
	int	i;

	i = 0;
	if (ptr == NULL)
	{
		return (0);
	}
	while (ptr[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchar(char *s, char c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (s + i);
		}
		i++;
	}
	return (NULL);
}

char	*ft_join(char *str, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[j] != '\0')
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	len;
	char	*str;

	if (!s2)
		return (NULL);
	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
	{
		free(s1);
		s1 = NULL;
		return (NULL);
	}
	str = ft_join(str, s1, s2);
	free(s1);
	s1 = NULL;
	return (str);
}

char	*ft_last_line(char *str)
{
	int	j;
	int	k;
	int	len;
	char	*ptr;

	j = 0;
	while (str[j] != '\0' && str[j] != '\n')
		j++;
	if (str[j] == '\n')
		j++;
	if (str[j] == '\0')
		return (free(str), str = NULL, NULL);
	len = ft_strlen(str) - j;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	k = 0;
	while (k < len)
		ptr[k++] = str[j++];
	ptr[k] = '\0';
	free(str);
	str = NULL;
	return (ptr);
}
