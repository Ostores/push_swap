/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 00:01:19 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/09 12:31:49 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	syntax_errors(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	dup_error(t_list *a, int nb)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->content == nb)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_lst(t_list **lst)
{
	t_list	*tmp;
	t_list	*current;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		tmp = current->next;
		current->content = 0;
		free(current);
		current = tmp;
	}
	*lst = NULL;
}

void	free_errors(t_list **a)
{
	free_lst(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	exit_error_av(t_list **a, t_list **b)
{
	if (a == NULL || *a != NULL)
		free_lst(a);
	if (b == NULL || *b != NULL)
		free_lst(b);
	write(2, "Error\n", 6);
	exit(1);
}
