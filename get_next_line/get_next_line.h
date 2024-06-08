/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:24:49 by bouhammo          #+#    #+#             */
/*   Updated: 2024/06/04 12:39:04 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*ft_read_string(int fd, char *string);
char	*ft_strchar(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_return_line(char *ptr);
char	*ft_last_line(char *str);
int		ft_strlen(char *ptr);
char	*ft_join(char *s, char *s1, char *s2);

#endif