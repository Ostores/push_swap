/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:21:23 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/10 16:20:16 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_size(t_list *lst)
{
	t_list	*tmp;
	int		count;

	tmp = lst;
	count = 0;
	if (!tmp)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

t_list	*lst_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

bool	lst_sorted(t_list *lst)
{
	if (!lst)
		return (true);
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			return (false);
		lst = lst->next;
	}
	return (true);
}

void	define_index(t_list *lst)
{
	int	i;
	int	divide;

	i = 0;
	if (!lst)
		return ;
	divide = lst_size(lst) / 2;
	while (lst)
	{
		lst->index = i;
		if (i <= divide)
			lst->div = true;
		else
			lst->div = false;
		lst = lst->next;
		i++;
	}
}
