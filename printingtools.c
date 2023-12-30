/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printingtools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:07:10 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/29 16:08:40 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar(int c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++], fd);
}

void	ft_putnbr(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar('-', fd);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, fd);
		ft_putnbr(nb % 10, fd);
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48, fd);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
