/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 20:11:19 by vgladush          #+#    #+#             */
/*   Updated: 2017/10/31 20:11:19 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	res[len] = '\0';
	while (i < len)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	return (res);
}
