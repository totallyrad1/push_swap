/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivotessorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:22:28 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/25 11:25:36 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pivotessorting(t_list **sa, t_list **sb)
{
	int	lp1;
	int	p1;
	int	p2;

	lp1 = -1;
	p1 = listsize(*sa) / 3;
	p2 = listsize(*sa) / 6;
	while (listsize(*sa) > 3)
	{
		if ((*sa)->index < p1)
			ft_pb(sa, sb, 1);
		else
			ft_ra(sa, 1);
		if (listsize(*sb) > 1 && ((*sb)->index >= lp1 && p2 <= (*sb)->index))
			ft_rb(sb, 1);
		if (listsize(*sb) == p1)
		{
			lp1 = p1;
			p1 += listsize(*sa) / 3;
			p2 = listsize(*sa) / 6 + lp1;
		}
	}
	sort_size_3(sa);
	pivotessorting1(sa, sb);
}

void	getbottom(t_list **stacka, t_list **bot)
{
	*bot = *stacka;
	while ((*bot)->next)
		*bot = (*bot)->next;
}

void	parrb(t_list **stacka, t_list **stackb, int value, t_list **bota)
{
	if (getspot(stackb, (*stacka)->index - 1) > listsize(*stackb) / 2)
	{
		if (((*bota)->index < (*stackb)->index || (*bota)->index == value))
		{
			ft_pa(stacka, stackb, 1);
			ft_ra(stacka, 1);
			getbottom(stacka, bota);
		}
		else if (stackb)
			ft_rrb(stackb, 1);
	}
	else
	{
		if ((*bota)->index < (*stackb)->index || (*bota)->index == value)
		{
			ft_pa(stacka, stackb, 1);
			ft_ra(stacka, 1);
			getbottom(stacka, bota);
		}
		else if (stackb)
			ft_rb(stackb, 1);
	}
}

void	pivotessorting1(t_list **stacka, t_list **stackb)
{
	t_list	*bota;
	int		value;

	getbottom(stacka, &bota);
	value = bota->index;
	while (stackb)
	{
		while ((*stackb) && (*stackb)->index + 1 != (*stacka)->index)
		{
			parrb(stacka, stackb, value, &bota);
		}
		if (*stackb && (*stackb)->index == (*stacka)->index - 1)
			ft_pa(stacka, stackb, 1);
		if ((*stacka)->index - 1 == bota->index)
		{
			while (bota->index == (*stacka)->index - 1)
			{
				ft_rra(stacka, 1);
				getbottom(stacka, &bota);
			}
		}
		if (checksorted(stacka) == 1 && *stackb == NULL)
			break ;
	}
}
