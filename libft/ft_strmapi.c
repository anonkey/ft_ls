/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 11:10:34 by tseguier          #+#    #+#             */
/*   Updated: 2014/04/19 02:42:02 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newstr;
	size_t	len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	newstr = ft_strnew(len);
	while (len-- > 0)
		newstr[len] = (*f)(len, s[len]);
	return (newstr);
}
