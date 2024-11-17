/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:52:57 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/09 11:53:14 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

void	rra(t_list **a, bool print)
{
	reverse_rotate(a);
	if (!print)
		write(1, "rra\n", 4);
}

void	rrb(t_list **b, bool print)
{
	reverse_rotate(b);
	if (!print)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
		write(1, "rrr\n", 4);
}
