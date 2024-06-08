/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:20:18 by bouhammo          #+#    #+#             */
/*   Updated: 2024/01/02 22:48:06 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	int		k;
	char	*ptr;
	int		i;

	k = ft_strlen(s) + 1;
	ptr = (char *)malloc(k * sizeof(char));
	i = 0;
	if (ptr == NULL)
		return (NULL);
	while (i < k - 1)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
