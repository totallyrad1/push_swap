/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:32:24 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/22 22:42:59 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void leak()
{
	system("leaks a.out");
}

int main(int ac, char **av)
{
	// atexit(leak);
	t_list *stacka;
	t_list *stackb;

	if(ac != 1)
	{
		int i = 1;
		int j = 0;
		int index = 0;
		int tnp = 1;
		int lstsize;
		int value;
		stacka = malloc(sizeof(t_list));
		if(!stacka)
			exit(2);
		while(i < ac)
		{
			value = ft_atoi(av[i], &j, stacka);
			if(tnp == 1)
				stacka->content = value;
			else
				ft_newnode(&stacka, value);
			tnp = 0;
			checkifthenumberexists(&stacka, value);
			if(av[i][j] == '\0')
			{
				j = 0;
				i++;
			}
		}
		indexing(&stacka);
		checksorted(&stacka);
		lstsize = ft_list_size(stacka);
		if(lstsize == 2)
			sort_size_2(&stacka);
		checksorted(&stacka);
		t_list *tmp = stacka;
		while(tmp)
		{
			printf("the number %d and its index is %d\n", tmp->content, tmp->index);
			tmp = tmp->next;
		}
		ft_freeeverything(stacka);
	}
}
