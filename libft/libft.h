/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:54:18 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/09 12:06:05 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

long	ft_atol(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *src);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *str, int c);

#endif