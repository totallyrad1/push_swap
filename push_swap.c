/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:32:24 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/23 21:57:25 by asnaji           ###   ########.fr       */
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
		int tnp = 1;
		int lstsize;
		int value;
		stacka = malloc(sizeof(t_list));
		if(!stacka)
			exit(2);
		stackb = malloc(sizeof(t_list));
		if(!stackb)
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
		if(checksorted(&stacka) == 1)
			return 0;
		lstsize = ft_list_size(stacka);
		sort_size_5(&stacka, &stackb);
		if(checksorted(&stacka) == 1)
			return 0;
		// t_list *tmp = stacka;
		// while(tmp)
		// {
		// 	printf("the number %d\n", tmp->content);
		// 	tmp = tmp->next;
		// }
		ft_freeeverything(stacka);
	}
}
