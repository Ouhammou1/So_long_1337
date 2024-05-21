/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:41:03 by bouhammo          #+#    #+#             */
/*   Updated: 2024/01/08 22:35:26 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	word_count(char  *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_fre(char **list, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (NULL);
}

static int	length( char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
	}
	return (i);
}

char	**ft_split(char  *s, char c)
{
	char	**list;
	int	j;
	int	word;

	if (!s)
		return (0);
	word = word_count(s, c);
	j = 0;
	list = (char **)malloc((word + 1) * sizeof(char *));
	if (!list)
		return (NULL);
	while (j < word)
	{
		while (*s == c && *s)
			s++;
		list[j] = ft_substr(s, 0, length(s, c));
		s = s + length(s, c);
		if (list[j] == NULL)
			return (ft_fre(list, j));
		j++;
	}
	list[j] = NULL;
	return (list);
}
