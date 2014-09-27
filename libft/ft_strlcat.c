/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 23:59:54 by tseguier          #+#    #+#             */
/*   Updated: 2014/04/19 02:42:00 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (i < size && dst[i] != '\0')
		++i;
	if (size == i)
		return (i + ft_strlen(src));
	while (src[j] != '\0' && size - j - 1 > i)
	{
		dst[i + j] = src[j];
		++j;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
