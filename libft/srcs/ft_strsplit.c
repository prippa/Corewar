/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 05:50:07 by vgladush          #+#    #+#             */
/*   Updated: 2017/11/06 05:50:07 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_wordcpy(const char *src, size_t len)
{
	char *dst;

	if (!(dst = (char *)malloc(len + 1)))
		return (0);
	dst[len] = '\0';
	while (len-- > 0)
		dst[len] = src[len];
	return (dst);
}

static	size_t	ft_lenword(char const *str, char c)
{
	size_t		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static	size_t	ft_sumword(char const *st, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (*st)
	{
		if ((j = ft_lenword(st, c)) == 0)
			st++;
		else
		{
			st += j;
			i++;
		}
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**res;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (ft_sumword(s, c) + 1))))
		return (0);
	while (*s)
	{
		if ((j = ft_lenword(s, c)) == 0)
			s++;
		else
		{
			res[i] = ft_wordcpy(s, j);
			s += j;
			i++;
		}
	}
	res[i] = 0;
	return (res);
}
