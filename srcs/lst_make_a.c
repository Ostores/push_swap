/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:21:18 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/10 16:33:22 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_target_in_b(t_list *a, t_list *b)
{
	t_list	*tmp_b;
	t_list	*target;
	int		match;

	tmp_b = b;
	target = NULL;
	match = INT_MIN;
	while (tmp_b)
	{
		if (tmp_b->content < a->content && tmp_b->content > match)
		{
			match = tmp_b->content;
			target = tmp_b;
		}
		tmp_b = tmp_b->next;
	}
	if (!target)
		target = find_max(b);
	return (target);
}

void	find_target_a(t_list *a, t_list *b)
{
	while (a)
	{
		if (!b)
			a->target = NULL;
		else
			a->target = find_target_in_b(a, b);
		a = a->next;
	}
}

void	cost_move(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_a = lst_size(a);
	len_b = lst_size(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->div))
			a->cost = len_a - (a->index);
		if (a->target->div)
			a->cost += a->target->index;
		else
			a->cost += len_b - (a->target->index);
		a = a->next;
	}
}

void	cheapest_moves(t_list *lst)
{
	t_list	*cheap;
	int		min_val;

	if (!lst)
		return ;
	cheap = NULL;
	min_val = INT_MAX;
	while (lst)
	{
		if (lst->cost < min_val)
		{
			min_val = lst->cost;
			cheap = lst;
		}
		lst = lst->next;
	}
	cheap->cheapest = true;
}

void	make_lst_a(t_list *a, t_list *b)
{
	define_index(a);
	define_index(b);
	find_target_a(a, b);
	cost_move(a, b);
	cheapest_moves(a);
}
