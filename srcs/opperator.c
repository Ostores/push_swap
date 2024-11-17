/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opperator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:42:52 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/10 16:56:03 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **dest, t_list **src)
{
	t_list	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}

void	swap(t_list **head)
{
	t_list	*first;
	t_list	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*head = second;
}

void	rotate(t_list **lst)
{
	t_list	*last_node;
	t_list	*first_node;

	if (!*lst || !(*lst)->next)
		return ;
	first_node = *lst;
	last_node = lst_last(*lst);
	*lst = first_node->next;
	(*lst)->prev = NULL;
	first_node->next = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
}

void	reverse_rotate(t_list **lst)
{
	t_list	*second_last_node;
	t_list	*last_node;

	if (!*lst || !(*lst)->next)
		return ;
	last_node = lst_last(*lst);
	second_last_node = last_node->prev;
	second_last_node->next = NULL;
	last_node->prev = NULL;
	last_node->next = *lst;
	(*lst)->prev = last_node;
	*lst = last_node;
}
