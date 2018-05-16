/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 13:14:41 by vgladush          #+#    #+#             */
/*   Updated: 2018/01/04 14:40:30 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define INVS(j) j < 48 || j > 122 || (j > 57 && j < 65) || (j > 90 && j < 97)
#define INV1(j) (j > 64 && j < 91 && (j > base + 55 || base < 11))
#define INV2(j) (j > 96 && j < 123 && (base < 11 || j > base + 87))

static	int		validbase(char *s, int base, int l, int j)
{
	if (base < 2 || base > 36)
	{
		ft_printf("error: \"%d\" cannot be base", base);
		return (0);
	}
	while (*s)
	{
		if (*s > 64 && *s < 91)
			j = (int)*s;
		else if (*s > 96 && *s < 123)
			l = (int)*s;
		if (INV1(*s) || INV2(*s) || (*s > 47 && *s < 58 && *s > base + 48))
		{
			ft_printf("error: \'%c\' too large or small for %d base", *s, base);
			return (0);
		}
		if (l > 0 && j > 0)
		{
			ft_printf("error: \'%c\' && \'%c\' cannot be in one base", l, j);
			return (0);
		}
		s++;
	}
	return (1);
}

static	char	*transbase(uintmax_t nbr, int base, int reg)
{
	int			i;
	int			tmp;
	int			ost;
	char		buf[65];

	if (reg)
		tmp = ((reg < 91 && reg > 64) ? 55 : 87);
	if (base < 2 || base > 36)
		return (0);
	i = 64;
	buf[i] = '\0';
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr)
	{
		ost = nbr % base;
		nbr = nbr / base;
		i--;
		if (ost > 9)
			buf[i] = ost + tmp;
		else
			buf[i] = ost + 48;
	}
	return (ft_strdup(buf + i));
}

static	char	*sigitoa(intmax_t c, char *res, int i)
{
	i = ft_nbrlen(c, 1);
	if (c < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (!(res = (char *)malloc(i + 1)))
		return (0);
	res[i] = '\0';
	if (c < 0 && (c = -c))
	{
		res[0] = '-';
		while (i-- > 1)
		{
			res[i] = c % 10 + 48;
			c /= 10;
		}
	}
	else
	{
		while (i--)
		{
			res[i] = c % 10 + 48;
			c /= 10;
		}
	}
	return (res);
}

uintmax_t		ft_basetoint(char *s, int base)
{
	uintmax_t	i;
	int			j;
	uintmax_t	l;

	if (!(validbase(s, base, 0, 0)))
		return (0);
	j = ft_strlen(s);
	i = 1;
	l = 0;
	while (j--)
	{
		if (s[j] > 48 && s[j] < 58)
			l += (s[j] - 48) * i;
		else if (s[j] > 96)
			l += (s[j] - 87) * i;
		else if (s[j] > 64)
			l += (s[j] - 55) * i;
		i *= base;
		if (INVS(s[j]))
		{
			ft_printf("error: \'%c\' not belongs to any base", s[j]);
			return (0);
		}
	}
	return (l);
}

char			*ft_itoabase(uintmax_t c, int sys, int rg)
{
	int			i;
	char		*res;

	res = NULL;
	if (sys == 1)
		return (sigitoa(c, res, 0));
	else if (sys)
		return (transbase(c, sys, rg));
	i = ft_nbrlen(c, 0);
	if (!(res = (char *)malloc(i + 1)))
		return (0);
	res[i] = '\0';
	while (i--)
	{
		res[i] = c % 10 + 48;
		c /= 10;
	}
	return (res);
}
