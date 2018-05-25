/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:34:45 by vgladush          #+#    #+#             */
/*   Updated: 2017/10/31 19:34:46 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	int		i;

	i = 0;
	if (s)
	{
		if (!(res = (char *)malloc(ft_strlen(s) + 1)))
			return (0);
		res[ft_strlen(s)] = '\0';
		while (s[i])
		{
			res[i] = f((char)s[i]);
			i++;
		}
		return (res);
	}
	return (0);
}
