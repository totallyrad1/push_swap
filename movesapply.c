/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesapply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:02:38 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/26 15:15:45 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	applymoves(char *moves, t_list **stacka, t_list **stackb)
{
	if (ft_strcmp(moves, "sa") == 0)
		ft_sa(stacka, 0);
	else if (ft_strcmp(moves, "sb") == 0)
		ft_sb(stackb, 0);
	else if (ft_strcmp(moves, "ss") == 0)
		ft_ss(stacka, stackb, 0);
	else if (ft_strcmp(moves, "pa") == 0)
		ft_pa(stacka, stackb, 0);
	else if (ft_strcmp(moves, "pb") == 0)
		ft_pb(stacka, stackb, 0);
}

int	validmove(char *moves)
{
	if (ft_strcmp(moves, "sa") == 0)
		return (1);
	else if (ft_strcmp(moves, "sb") == 0)
		return (1);
	else if (ft_strcmp(moves, "ss") == 0)
		return (1);
	else if (ft_strcmp(moves, "pa") == 0)
		return (1);
	else if (ft_strcmp(moves, "pb") == 0)
		return (1);
	else if (ft_strcmp(moves, "ra") == 0)
		return (1);
	else if (ft_strcmp(moves, "rb") == 0)
		return (1);
	else if (ft_strcmp(moves, "rr") == 0)
		return (1);
	else if (ft_strcmp(moves, "rra") == 0)
		return (1);
	else if (ft_strcmp(moves, "rrb") == 0)
		return (1);
	else if (ft_strcmp(moves, "rrr") == 0)
		return (1);
	return (0);
}

void	applymoves1(char *moves, t_list **stacka, t_list **stackb)
{
	if (ft_strcmp(moves, "ra") == 0)
		ft_ra(stacka, 0);
	else if (ft_strcmp(moves, "rb") == 0)
		ft_rb(stackb, 0);
	else if (ft_strcmp(moves, "rr") == 0)
		ft_rr(stacka, stackb, 0);
	else if (ft_strcmp(moves, "rra") == 0)
		ft_rra(stacka, 0);
	else if (ft_strcmp(moves, "rrb") == 0)
		ft_rrb(stackb, 0);
	else if (ft_strcmp(moves, "rrr") == 0)
		ft_rrr(stacka, stackb, 0);
}

void	applymovesonstack(char **moves, t_list **stacka, t_list **stackb)
{
	int	i;

	i = 0;
	while (moves[i])
	{
		if (validmove(moves[i]) == 0)
		{
			ft_putstr("Error\n", 2);
			exit(2);
		}
		applymoves(moves[i], stacka, stackb);
		applymoves1(moves[i], stacka, stackb);
		i++;
	}
}
