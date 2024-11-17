/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:42:20 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/09 11:42:23 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

void	ra(t_list **a, bool print)
{
	rotate(a);
	if (!print)
		write(1, "ra\n", 3);
}

void	rb(t_list **b, bool print)
{
	rotate(b);
	if (!print)
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		write(1, "rr\n", 3);
}
