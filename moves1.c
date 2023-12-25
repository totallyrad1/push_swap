/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:58:26 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/25 20:23:09 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **stacka, int i)
{
	t_list	*tmp;

	if (!stacka)
		return ;
	tmp = *stacka;
	*stacka = (*stacka)->next;
	tmp->next = (*stacka)->next;
	(*stacka)->next = tmp;
	if (i)
		ft_putstr("sa\n", 1);
}

void	ft_sb(t_list **stackb, int i)
{
	t_list	*tmp;

	if (!stackb)
		return ;
	tmp = *stackb;
	*stackb = (*stackb)->next;
	tmp->next = (*stackb)->next;
	(*stackb)->next = tmp;
	if (i)
		ft_putstr("sb\n", 1);
}

void	ft_ss(t_list **stacka, t_list **stackb, int i)
{
	ft_sa(stacka, 0);
	ft_sb(stackb, 0);
	if (i)
		ft_putstr("ss\n", 1);
}

void	ft_pa(t_list **stacka, t_list **stackb, int i)
{
	t_list	*tmp;

	if (!stackb)
		return ;
	tmp = *stacka;
	*stacka = *stackb;
	*stackb = (*stackb)->next;
	(*stacka)->next = tmp;
	if (i)
		ft_putstr("pa\n", 1);
}

void	ft_pb(t_list **stacka, t_list **stackb, int i)
{
	t_list	*tmp;

	if (!stacka)
		return ;
	tmp = *stackb;
	*stackb = *stacka;
	*stacka = (*stackb)->next;
	(*stackb)->next = tmp;
	if (i)
		ft_putstr("pb\n", 1);
}
