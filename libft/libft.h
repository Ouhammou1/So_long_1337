/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:46:20 by bouhammo          #+#    #+#             */
/*   Updated: 2024/06/04 23:36:12 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(char *str);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s);
int		ft_strlen(char *s);
char	*ft_substr(char *s, int start, int len);
int		ft_strcmp(char *s1, char *s2);
void	ft_putnbr(int n);
void	ft_putchar(char c);

#endif