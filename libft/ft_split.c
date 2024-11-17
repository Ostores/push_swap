/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:18:24 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/09 12:02:00 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_substr_split(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*str_ptr;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (start > l)
		len = 0;
	else if (len > (l - start))
		len = l - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		return (NULL);
	}
	s += start;
	str_ptr = str;
	*(str + len) = '\0';
	while (len-- && *s)
		*str++ = *s++;
	return (str_ptr);
}

static size_t	ft_countword(const char *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static void	free_array(size_t i, char **strs)
{
	while (i > 0)
	{
		i--;
		free(*(strs + i));
	}
	free(strs);
}

static char	**ft_split_sub(const char *s, char **strs, const char c, size_t n)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (i < n - 1)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, c) - s;
			strs[i] = ft_substr_split(&*s, 0, len);
			if (!*(strs + i++))
			{
				free_array(i, strs);
				return (NULL);
			}
			s += len;
		}
	}
	strs[i] = NULL;
	return (strs);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	size_t	n;

	if (!s || !c)
		return (NULL);
	n = ft_countword(s, c) + 1;
	strs = (char **)malloc(sizeof(char *) * n);
	if (!strs)
	{
		return (NULL);
	}
	strs = ft_split_sub(s, strs, c, n);
	return (strs);
}
