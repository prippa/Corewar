/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:44:00 by vgladush          #+#    #+#             */
/*   Updated: 2017/10/26 13:44:01 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;
	size_t res;

	i = 0;
	j = 0;
	i = ft_strlen(s1);
	res = i;
	while (i + 1 < n && s2[j])
		s1[i++] = s2[j++];
	s1[i] = '\0';
	while (s2[j])
		j++;
	if (res > n)
		return (j + n);
	return (j + res);
}
