/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:43:25 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/29 16:07:32 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **stacka, int i)
{
	t_list	*tmp;
	t_list	*curr;

	if (!(*stacka))
		return ;
	curr = *stacka;
	while (curr->next->next != NULL)
		curr = curr->next;
	tmp = curr->next;
	curr->next = NULL;
	tmp->next = *stacka;
	*stacka = tmp;
	if (i)
		ft_putstr("rra\n", 1);
}

void	ft_rrb(t_list **stackb, int i)
{
	t_list	*tmp;
	t_list	*curr;

	if (!(*stackb))
		return ;
	curr = *stackb;
	while (curr->next->next != NULL)
		curr = curr->next;
	tmp = curr->next;
	curr->next = NULL;
	tmp->next = *stackb;
	*stackb = tmp;
	if (i)
		ft_putstr("rrb\n", 1);
}

void	ft_rrr(t_list **stacka, t_list **stackb, int i)
{
	ft_rra(stacka, 0);
	ft_rrb(stackb, 0);
	if (i)
		ft_putstr("rrr\n", 1);
}
