/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:41:05 by vgladush          #+#    #+#             */
/*   Updated: 2017/10/31 19:41:05 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = 0;
	if (s)
	{
		if (!(res = (char *)malloc(ft_strlen(s) + 1)))
			return (0);
		res[ft_strlen(s)] = '\0';
		while (*s)
		{
			res[i] = f(i, *s++);
			i++;
		}
		return (res);
	}
	return (0);
}
