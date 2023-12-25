/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingfunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:38:19 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/25 11:23:40 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getmaxindex(t_list **stack)
{
	int		value;
	int		index;
	t_list	*curr;

	value = (*stack)->content;
	index = (*stack)->index;
	curr = *stack;
	while (curr)
	{
		if (curr->content > value)
		{
			value = curr->content;
			index = curr->index;
		}
		curr = curr->next;
	}
	return (index);
}

void	sort_size_2(t_list **stack)
{
	ft_sa(stack, 1);
}

void	sort_size_3(t_list **stack)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stack)->index;
	mid = (*stack)->next->index;
	bot = (*stack)->next->next->index;
	if (checksorted(stack) == 0 && top > mid && top > bot)
		ft_ra(stack, 1);
	top = (*stack)->index;
	mid = (*stack)->next->index;
	bot = (*stack)->next->next->index;
	if (checksorted(stack) == 0 && (bot < top || bot < mid))
		ft_rra(stack, 1);
	top = (*stack)->index;
	mid = (*stack)->next->index;
	bot = (*stack)->next->next->index;
	if (checksorted(stack) == 0 && (bot > top || bot > mid))
		ft_sa(stack, 1);
	top = (*stack)->index;
	mid = (*stack)->next->index;
	bot = (*stack)->next->next->index;
}

int	getspot(t_list **stack, int index)
{
	t_list	*curr;
	int		i;

	curr = *stack;
	i = 0;
	while (curr && curr->index != index)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

void	sort_size_5(t_list **stack, t_list **stackb)
{
	t_list	*curr;
	int		index;
	int		list_size;

	list_size = listsize(*stack);
	curr = *stack;
	index = 0;
	while (listsize(*stack) > 3)
	{
		if (getspot(stack, index) > list_size / 2)
		{
			while ((*stack)->index != index)
				ft_rra(stack, 1);
		}
		else
		{
			while ((*stack)->index != index)
				ft_ra(stack, 1);
		}
		index++;
		ft_pb (stack, stackb, 1);
	}
	sort_size_3(stack);
	while (*stackb)
		ft_pa(stack, stackb, 1);
}
