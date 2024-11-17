/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:34:30 by emlinott          #+#    #+#             */
/*   Updated: 2024/05/04 12:35:08 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}
