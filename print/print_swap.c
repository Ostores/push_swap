/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:40:15 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/09 11:42:26 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

void	sa(t_list **a, bool print)
{
	swap(a);
	if (!print)
		write(1, "sa\n", 3);
}

void	sb(t_list **b, bool print)
{
	swap(b);
	if (!print)
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		write(1, "ss\n", 3);
}
