/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:44:05 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/24 15:59:08 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_ra(t_list **stacka, int i)
{
	t_list *tmp;
	t_list *curr;
	
	if(!(*stacka))
		return ;
	tmp = *stacka;
	*stacka = (*stacka)->next;
	curr = *stacka;
	while(curr->next != NULL)
		curr = curr->next;
	curr->next = tmp;
	tmp->next = NULL;
	if(i)
		ft_putstr("ra\n", 1);
}

void ft_rb(t_list **stackb, int i)
{
	t_list *tmp;
	t_list *curr;
	
	if(!stackb)
		return ;
	tmp = *stackb;
	*stackb = (*stackb)->next;
	curr = *stackb;
	if(curr)
	{
		while(curr->next != NULL)
			curr = curr->next;
		curr->next = tmp;
	}
	tmp->next = NULL;
	if(i)
		ft_putstr("rb\n", 1);
}

void ft_rr(t_list **stacka, t_list **stackb)
{
	ft_ra(stacka, 0);
	ft_rb(stackb, 0);
	ft_putstr("rr\n", 1);
}