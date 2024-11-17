/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:42:41 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/17 17:25:55 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_on_top(t_list **a)
{
	while ((*a)->content != find_min(*a)->content)
	{
		if (find_min(*a)->div)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	rotate_both(t_list **a, t_list **b, t_list *cheap)
{
	while (*b != cheap->target && *a != cheap)
		rr(a, b, false);
	define_index(*a);
	define_index(*b);
}

void	rev_rot_both(t_list **a, t_list **b, t_list *cheap)
{
	while (*b != cheap->target && *a != cheap)
		rrr(a, b, false);
	define_index(*a);
	define_index(*b);
}

void	sort_three(t_list **a)
{
	t_list	*big_nb;

	big_nb = find_max(*a);
	if (big_nb == *a)
		ra(a, false);
	else if ((*a)->next == big_nb)
		rra(a, false);
	if ((*a)->content > (*a)->next->content)
		sa(a, false);
}

void	sort_lst(t_list **a, t_list **b)
{
	int	len;

	len = lst_size(*a);
	if (len > 3 && !lst_sorted(*a))
		pb(b, a, false);
	len -= 1;
	if (len > 3 && !lst_sorted(*a))
		pb(b, a, false);
	len -= 1;
	while (len > 3 && !lst_sorted(*a))
	{
		make_lst_a(*a, *b);
		move_a_to_b(a, b);
		len -= 1;
	}
	sort_three(a);
	while (*b)
	{
		make_lst_b(*a, *b);
		move_b_to_a(a, b);
	}
	define_index(*a);
	min_on_top(a);
}
