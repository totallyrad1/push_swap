/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivotessorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:22:28 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/24 19:46:37 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void pivotessorting(t_list **stacka, t_list **stackb)
{
	int	lastpv1;
	int	pv1;
	int	pv2;

	lastpv1 = -1;
	pv1 = ft_list_size(*stacka) / 3;
	pv2 = ft_list_size(*stacka) / 6;
	while(ft_list_size(*stacka) > 3)
	{
		if((*stacka)->index < pv1)
			ft_pb(stacka, stackb, 1);
		else
			ft_ra(stacka,1);
		if(ft_list_size(*stackb) > 1 && ((*stackb)->index >= lastpv1 && pv2 <= (*stackb)->index))
			ft_rb(stackb, 1);
		if(ft_list_size(*stackb) == pv1)
		{
			lastpv1 = pv1;
			pv1 += ft_list_size(*stacka) / 3;
			pv2 = ft_list_size(*stacka) / 6 + lastpv1;
		}
	}
	sort_size_3(stacka);
	pivotessorting1(stacka, stackb);
}


void getbottom(t_list **stacka, t_list **bot)
{
	*bot = *stacka;
	while((*bot)->next)
		*bot = (*bot)->next;	
}

void pivotessorting1(t_list **stacka, t_list **stackb)
{
	t_list *bota;
	int i;
	
	i = 0;
	// int init = 1;
	getbottom(stacka, &bota);
	while(stackb)
	{
		i = 0;
		while((*stackb) && (*stackb)->index + 1 != (*stacka)->index)
		{
			if(getspot(stackb, (*stacka)->index - 1) > ft_list_size(*stackb) / 2)
			{
				// printf("THE FIRST \n");
				if(bota->index < (*stackb)->index)
				{
					ft_pa(stacka, stackb, 1);
					ft_ra(stacka, 1);
					getbottom(stacka, &bota);
				}
				else if(stackb)
					ft_rrb(stackb, 1);
			}
			else
			{
				if(bota->index < (*stackb)->index)
				{
					ft_pa(stacka, stackb, 1);
					ft_ra(stacka, 1);
					getbottom(stacka, &bota);
				}
				else if(stackb)
					ft_rb(stackb, 1);
			}
		}
		if((*stackb)->index == (*stacka)->index - 1)
			ft_pa(stacka, stackb, 1);
		if ((*stacka)->index - 1 == bota->index)
		{
			while(bota->index == (*stacka)->index - 1)
			{
				ft_rra(stacka, 1);
				getbottom(stacka, &bota);
			}
		}
		if(checksorted(stacka) == 1 && *stackb == NULL)
			break;
		i++;
	}
	}
