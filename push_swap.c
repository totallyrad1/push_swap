/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:32:24 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/26 16:53:13 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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

int	main(int ac, char **av)
{
	t_list	*stacka;
	t_list	*stackb;

	stackb = NULL;
	if (ac != 1)
	{
		stacka = malloc(sizeof(t_list));
		if (!stacka)
			exit(2);
		fullfillstacka(&stacka, ac, av);
		indexing(&stacka);
		if (listsize(stacka) != 1)
		{
			if (checksorted(&stacka) == 0 && listsize(stacka) == 2)
				sort_size_2(&stacka);
			else if (checksorted(&stacka) == 0 && listsize(stacka) == 3)
				sort_size_3(&stacka);
			else if (checksorted(&stacka) == 0 && listsize(stacka) == 5)
				sort_size_5(&stacka, &stackb);
			else if (checksorted(&stacka) == 0)
				pivotessorting(&stacka, &stackb);
		}
		ft_freeeverything(stacka);
	}
}
