/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:42:35 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/10 16:45:23 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	if_a_if_b(t_list **lst, t_list *top_node, char lst_name)
{
	if (lst_name == 'a')
	{
		if (top_node->div)
			ra(lst, false);
		else
			rra(lst, false);
	}
	else if (lst_name == 'b')
	{
		if (top_node->div)
			rb(lst, false);
		else
			rrb(lst, false);
	}
}

void	prep_to_push(t_list **lst, t_list *top_node, char lst_name)
{
	t_list	*tmp;
	bool	found;

	tmp = *lst;
	found = false;
	while (tmp)
	{
		if (tmp == top_node)
		{
			found = true;
			break ;
		}
		tmp = tmp->next;
	}
	if (!found)
		return ;
	while (*lst != top_node)
	{
		if_a_if_b(lst, top_node, lst_name);
	}
}

t_list	*find_min(t_list *lst)
{
	int		min;
	t_list	*min_node;

	if (!lst)
		return (NULL);
	min = INT_MAX;
	while (lst)
	{
		if (lst->content < min)
		{
			min = lst->content;
			min_node = lst;
		}
		lst = lst->next;
	}
	return (min_node);
}

t_list	*find_max(t_list *lst)
{
	int		max;
	t_list	*max_node;

	if (!lst)
		return (NULL);
	max = INT_MIN;
	while (lst)
	{
		if (lst->content > max)
		{
			max = lst->content;
			max_node = lst;
		}
		lst = lst->next;
	}
	return (max_node);
}

t_list	*get_cheapest_nb(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->cheapest)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
