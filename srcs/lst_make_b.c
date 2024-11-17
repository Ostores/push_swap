/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_make_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:42:47 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/17 17:26:21 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target_b(t_list *a, t_list *b)
{
	t_list	*current_a;
	t_list	*target_node;
	int		best_match_index;

	while (b)
	{
		best_match_index = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->content > b->content
				&& current_a->content < best_match_index)
			{
				best_match_index = current_a->content;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == INT_MAX)
			b->target = find_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	make_lst_b(t_list *a, t_list *b)
{
	define_index(a);
	define_index(b);
	find_target_b(a, b);
}
