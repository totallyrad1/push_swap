/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:40:00 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/26 16:44:06 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	fullfillstacka(t_list **stacka, int ac, char **av)
{
	int	i;
	int	j;
	int	tnp;
	int	value;

	i = 1;
	j = 0;
	tnp = 1;
	while (i < ac)
	{
		value = ft_atoi(av[i], &j, *stacka);
		if (tnp == 1)
			(*stacka)->content = value;
		else
			ft_newnode(stacka, value);
		tnp = 0;
		checkifthenumberexists(stacka, value);
		if (av[i][j] == '\0')
		{
			j = 0;
			i++;
		}
	}
}

char	**ft_read(void)
{
	char	*moves;
	char	*buffer;
	char	**res;
	int		bytes_read;

	bytes_read = 1;
	buffer = malloc(100 + 1);
	if (!buffer)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(0, buffer, 100);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		moves = ft_strjoin(moves, buffer);
	}
	free(buffer);
	res = ft_split(moves, '\n');
	free(moves);
	return (res);
}

int	main(int ac, char **av)
{
	t_list	*stacka;
	t_list	*stackb;
	char	**moves;

	stackb = NULL;
	if (ac != 1)
	{
		stacka = malloc(sizeof(t_list));
		if (!stacka)
			exit(2);
		fullfillstacka(&stacka, ac, av);
		indexing(&stacka);
		moves = ft_read();
		applymovesonstack(moves, &stacka, &stackb);
		if (checksorted(&stacka) == 1 && stackb == NULL)
			ft_putstr("OK\n", 1);
		else
			ft_putstr("KO\n", 2);
		ft_free(moves);
		ft_freeeverything(stacka);
	}
}
