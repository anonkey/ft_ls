/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:10:34 by tseguier          #+#    #+#             */
/*   Updated: 2014/04/19 02:42:02 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t		len;
	char		*newstr;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	newstr = ft_strnew(len);
	while (len-- > 0)
		newstr[len] = (*f)(s[len]);
	return (newstr);
}
