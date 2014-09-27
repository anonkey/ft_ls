/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 06:33:57 by tseguier          #+#    #+#             */
/*   Updated: 2014/04/19 02:40:33 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int c)
{
	return ((c >= 48 && c <= 57) || (c <= 122 && c >= 97)
			|| (c >= 65 && c <= 90) ? 1 : 0);
}