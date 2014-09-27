/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/17 21:36:51 by tseguier          #+#    #+#             */
/*   Updated: 2014/04/19 02:41:40 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (*s2 == '\0')
		return (s1);
	while (s1[i] != '\0')
		++i;
	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		++i;
		++j;
	}
	s1[i] = '\0';
	return (s1);
}
