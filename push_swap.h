#ifndef PUSH_SWAP_H
 #define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int			content;
	int			index;
	struct s_list	*next;
}	t_list;

//helper functions 
//helpers.c
void	ft_freeeverything(t_list *lst);
void	ft_newnode(t_list **lst, int value);
int ft_list_size(t_list *stack);
//moves1.c
void	ft_sa(t_list **stacka, int i);
void	ft_sb(t_list **stackb, int i);
void	ft_ss(t_list **stacka, t_list **stackb);
void	ft_pa(t_list **stacka, t_list **stackb,int i);
void	ft_pb(t_list **stacka, t_list **stackb, int i);
//moves2.c
void	ft_ra(t_list **stacka, int i);
void	ft_rb(t_list **stackb, int i);
void	ft_rr(t_list **stacka, t_list **stackb);
//moves3.c
void	ft_rra(t_list **stacka, int i);
void	ft_rrb(t_list **stackb, int i);
void	ft_rrr(t_list **stacka, t_list **stackb);
//printingtools.c
void	ft_putchar(int c, int fd);
void	ft_putstr(char *str, int fd);
void	ft_putnbr(int nb, int fd);
//tools.c
int		ft_atoi(char *str, int *j, t_list *lst);
void	check(ssize_t nb, char *str, int j, t_list *lst);
void	checkifthenumberexists(t_list **stacka, int value);
void	indexing(t_list **stacka);
int	checksorted(t_list **stacka);
//sortingfunction.c
void sort_size_3(t_list **stack);
void sort_size_5(t_list **stack,t_list **stackb);
int getmaxindex(t_list **stack);
int getspot(t_list **stack, int index);

#endif