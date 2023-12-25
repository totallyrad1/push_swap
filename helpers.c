/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:39:43 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/25 11:23:14 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freeeverything(t_list *lst)
{
	t_list	*curr;
	t_list	*lastnode;

	curr = lst;
	while (curr)
	{
		lastnode = curr;
		curr = curr->next;
		free(lastnode);
	}
}

void	ft_newnode(t_list **lst, int value)
{
	t_list	*new_node;
	t_list	*curr;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		exit(0);
	curr = *lst;
	new_node->next = NULL;
	new_node->content = value;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

int	listsize(t_list *stack)
{
	int		i;
	t_list	*curr;

	curr = stack;
	i = 0;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}
