/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:57:52 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/26 15:36:43 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check(ssize_t nb, char *str, int j, t_list *lst)
{
	if (str[j] == ' ' && str[j + 1] == '\0')
	{
		ft_putstr("Error\n", 2);
		ft_freeeverything(lst);
		exit(2);
	}
	if (!(str[j] >= '0' && str[j] <= '9') && str[j] != ' ' )
	{
		ft_putstr("Error\n", 2);
		ft_freeeverything(lst);
		exit(2);
	}
	if (nb > INT_MAX || nb < INT_MIN)
	{
		ft_putstr("Error\n", 2);
		ft_freeeverything(lst);
		exit(2);
	}
}

int	ft_atoi(char *str, int *j, t_list *lst)
{
	ssize_t	result;
	int		sign;

	result = 0;
	sign = 1;
	while (str[*j] == 32)
		(*j)++;
	if (str[*j] == '\0')
		check(result, str, *j, lst);
	if ((str[*j] == '+' || str[*j] == '-') && str[*j + 1] != '\0')
	{
		if (str[*j] == '-')
			sign *= -1;
		(*j)++;
	}
	while (str[*j] != ' ' && str[*j] != '\0' )
	{
		result = result * 10 + (str[*j] - '0');
		check(result * sign, str, *j, lst);
		(*j)++;
	}
	while (str[*j] == 32)
		(*j)++;
	return (result * sign);
}

void	checkifthenumberexists(t_list **stacka, int value)
{
	t_list	*curr;

	curr = *stacka;
	while (curr->next != NULL)
	{
		if (value == curr->content)
		{
			ft_putstr("Error\n", 2);
			exit(2);
		}
		curr = curr->next;
	}
}

void	indexing(t_list **stacka)
{
	t_list	*curr;
	t_list	*tmp;

	curr = *stacka;
	while (curr)
	{
		tmp = *stacka;
		while (tmp)
		{
			if (curr->content > tmp->content)
				curr->index++;
			tmp = tmp->next;
		}
		curr = curr->next;
	}
}

int	checksorted(t_list **stacka)
{
	t_list	*curr;

	curr = *stacka;
	while (curr->next)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}
