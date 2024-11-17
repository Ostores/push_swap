/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:26:25 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/17 17:27:55 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_b(t_list **a, t_list **b)
{
	t_list	*cheap;

	cheap = get_cheapest_nb(*a);
	if (cheap->div && cheap->target->div)
		rotate_both(a, b, cheap);
	else if (!(cheap->div)
		&& !(cheap->target->div))
		rev_rot_both(a, b, cheap);
	prep_to_push(a, cheap, 'a');
	prep_to_push(b, cheap->target, 'b');
	pb(b, a, false);
}

void	move_b_to_a(t_list **a, t_list **b)
{
	if (*b)
	{
		prep_to_push(a, (*b)->target, 'a');
		pa(a, b, false);
	}
}
