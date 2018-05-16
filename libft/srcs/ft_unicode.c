/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:06:56 by vgladush          #+#    #+#             */
/*   Updated: 2018/01/13 15:51:01 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	uninasc(char *s)
{
	int			i;
	int			sum;
	int			bt;

	i = 8;
	sum = 0;
	bt = 1;
	while (i--)
	{
		if (s[i] == '1')
			sum += bt;
		bt *= 2;
	}
	return ((char)sum);
}

static	char	lascod(char *s, int y)
{
	int			j;
	char		res[9];

	res[0] = '1';
	j = 8;
	res[j] = '\0';
	while (j > 1)
		res[--j] = '0';
	while (j++ < 7)
		res[j] = s[y++];
	return (uninasc(res));
}

static	char	*transcode(char *s, int i, char *res, int c)
{
	int			j;
	char		cd[9];

	cd[8] = '\0';
	cd[c] = '0';
	if (c)
		j = i - (c * 6 - 6);
	else if ((j = i))
		i = 1;
	while (c)
		cd[--c] = '1';
	while (cd[c] == '1')
		c++;
	while (c++ < 7)
		cd[c] = '0';
	while (j > 0 && c)
		cd[--c] = s[--j];
	res[j++] = uninasc(cd);
	c = i;
	while (c > 6 && (c -= 6))
		res[j++] = lascod(s, i - (6 + (c / 6) * 6));
	res[j] = '\0';
	return (res);
}

char			*unicd(wint_t c)
{
	char		*res;
	char		*s;
	int			i;

	if (c == 0)
		return (0);
	s = ft_itoabase(c, 2, '0');
	i = ft_strlen(s);
	if (!(res = (char *)malloc(sizeof(char) * 5)))
		return (0);
	if (i > 16)
		res = transcode(s, i, res, 4);
	else if (i > 11)
		res = transcode(s, i, res, 3);
	else if (i > 7)
		res = transcode(s, i, res, 2);
	else
		res = transcode(s, i, res, 0);
	free(s);
	return (res);
}

char			*unistr(wchar_t *s, int *j)
{
	int			i;
	char		*str;
	char		*tmp;

	i = 0;
	if (!s || !(str = (char *)malloc(sizeof(char) * ft_wcharlen(s) + 1)))
		return (0);
	while (*s)
	{
		tmp = unicd(*s++);
		while (tmp[i])
		{
			str[j[16]] = tmp[i++];
			j[16] += 1;
		}
		str[j[16]] = '\0';
		j[16] += 1;
		free(tmp);
		i = 0;
	}
	str[j[16]] = '\0';
	return (str);
}
