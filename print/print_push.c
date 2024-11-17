/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:53:07 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/09 11:42:05 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

void	pa(t_list **a, t_list **b, bool print)
{
	push(a, b);
	if (!print)
		write(1, "pa\n", 3);
}

void	pb(t_list **b, t_list **a, bool print)
{
	push(b, a);
	if (!print)
		write(1, "pb\n", 3);
}
