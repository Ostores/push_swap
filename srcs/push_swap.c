/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:53:02 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/10 16:56:27 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include <stdio.h>

static void	lst_new(t_list **lst, int nb)
{
	t_list	*last_node;
	t_list	*node;

	if (!lst)
		return ;
	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->next = NULL;
	node->content = nb;
	if (!(*lst))
	{
		*lst = node;
		node->prev = NULL;
	}
	else
	{
		last_node = lst_last(*lst);
		last_node->next = node;
		node->prev = last_node;
	}
}

static void	launch_sort(t_list **a, t_list **b)
{
	if (!lst_sorted(*a))
	{
		if (lst_size(*a) == 2)
			sa(a, false);
		else if (lst_size(*a) == 3)
			sort_three(a);
		else
			sort_lst(a, b);
	}
}

static void	lst_check_a(t_list **a, char **av)
{
	long	nb;
	int		i;

	i = 0;
	while (av[i])
	{
		if (syntax_errors(av[i]))
			free_errors(a);
		nb = ft_atol(av[i]);
		if (nb > INT_MAX || nb < INT_MIN || nb == LONG_MAX || nb == LONG_MIN)
			free_errors(a);
		if (dup_error(*a, (int)nb))
			free_errors(a);
		lst_new(a, (int)nb);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	**strs;

	a = NULL;
	b = NULL;
	strs = NULL;
	if (ac > 1)
	{
		if (ac == 2)
		{
			strs = ft_split(av[1], ' ');
			if (!strs || !strs[0])
				exit_error_av(NULL, NULL);
			lst_check_a(&a, strs);
		}
		else
			lst_check_a(&a, av + 1);
		launch_sort(&a, &b);
		free_lst(&a);
		return (0);
	}
	else
		return (1);
}

// t_list *tmp = a;
// 		while (tmp)
// 		{
// 			printf("%d ", tmp->content);
// 			tmp = tmp->next;
// 		}