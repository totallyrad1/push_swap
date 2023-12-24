/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingfunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:38:19 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/24 19:45:23 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int getmaxindex(t_list **stack)
{
	int value;
	int index;
	t_list *curr;

	value = (*stack)->content;
	index = (*stack)->index;
	curr = *stack;
	while(curr)
	{
		if(curr->content > value)
		{
			value = curr->content;
			index = curr->index;
		}
		curr = curr->next;
	}
	return index;
}

void sort_size_2(t_list **stack)
{
	ft_sa(stack, 1);
}

void sort_size_3(t_list **stack)
{
	if(checksorted(stack) == 0 && (*stack)->index > (*stack)->next->index && (*stack)->index > (*stack)->next->next->index)
		ft_ra(stack, 1);
	if(checksorted(stack) == 0 && ((*stack)->next->next->index < (*stack)->index || (*stack)->next->next->index < (*stack)->next->index))
		ft_rra(stack, 1);
	if(checksorted(stack) == 0 && ((*stack)->next->next->index > (*stack)->index || (*stack)->next->next->index > (*stack)->next->index))
		ft_sa(stack, 1);
}

int getspot(t_list **stack, int index)
{
	t_list	*curr;
	int		i;

	curr = *stack;
	i = 0;
	while(curr && curr->index != index)
	{
		curr = curr->next;
		i++;
	}
	return i;	
}

void sort_size_5(t_list **stack,t_list **stackb)
{
	t_list	*curr;
	int index;
	int list_size = ft_list_size(*stack);
	
	curr = *stack;
	index = 0;
	while(ft_list_size(*stack) > 3)
	{
		if(getspot(stack, index) > list_size / 2)
		{
			while((*stack)->index != index)
				ft_rra(stack, 1);
		}
		else {
			while((*stack)->index != index)
				ft_ra(stack, 1);
		}
		index++;
		ft_pb(stack, stackb, 1);
	}
	sort_size_3(stack);
	while(*stackb)
		ft_pa(stack, stackb, 1);
}
