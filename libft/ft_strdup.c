/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:15:49 by tseguier          #+#    #+#             */
/*   Updated: 2014/04/19 02:41:47 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*newstr;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	newstr = (char *)malloc(1 + sizeof(char) * ft_strlen(s1));
	if (!newstr)
		return (NULL);
	while ('\0' != s1[i])
	{
		newstr[i] = s1[i];
		++i;
	}
	newstr[i] = '\0';
	return (newstr);
}
