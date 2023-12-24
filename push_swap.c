/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:32:24 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/24 19:46:27 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void leak()
{
	system("leaks push_swap");
}

void fullfillstacka(t_list **stacka,int ac, char **av)
{
	int	i;
	int	j;
	int	tnp;
	int	value;

	i = 1;
	j = 0;
	tnp = 1;
	while(i < ac)
	{
		value = ft_atoi(av[i], &j, *stacka);
		if(tnp == 1)
			(*stacka)->content = value;
		else
			ft_newnode(stacka, value);
		tnp = 0;
		checkifthenumberexists(stacka, value);
		if(av[i][j] == '\0')
		{
			j = 0;
			i++;
		}
	}
}

int main(int ac, char **av)
{
	// atexit(leak);
	t_list *stacka;
	t_list *stackb;

	stackb = NULL;
	if(ac != 1)
	{
		int lstsize;
		stacka = malloc(sizeof(t_list));
		if(!stacka)
			exit(2);
		fullfillstacka(&stacka, ac, av);
		indexing(&stacka);
		lstsize = ft_list_size(stacka);
		if(checksorted(&stacka) == 0 && lstsize == 2)
			sort_size_2(&stacka);
		else if(checksorted(&stacka) == 0 && lstsize == 3)
			sort_size_3(&stacka);
		else if(checksorted(&stacka) == 0 && lstsize == 5)
			sort_size_5(&stacka, &stackb);
		else
			pivotessorting(&stacka, &stackb);
		ft_freeeverything(stacka);
		ft_freeeverything(stackb);
	}
	// printf_stack(&stacka);
	// printf("////////--------------//////////\n");
	// printf_stack(&stackb);
}
