/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:53:23 by bouhammo          #+#    #+#             */
/*   Updated: 2024/05/24 15:53:26 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			n = n * (-1);
			ft_putchar('-');
		}
		if (n < 10)
		{
			ft_putchar(n % 10 + '0');
		}
		else
		{
			ft_putnbr(n / 10);
			ft_putchar(n % 10 + '0');
		}
	}
}