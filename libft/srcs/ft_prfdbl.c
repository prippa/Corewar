/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prfdbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 18:54:53 by vgladush          #+#    #+#             */
/*   Updated: 2018/01/15 12:15:27 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		justfree(char **ito, int a, char c)
{
	if (!ito)
	{
		if (c == 'G' || c == 'E')
			write(1, "E+", 2);
		else
			write(1, "e+", 2);
		ft_printf("%.2d", a);
		return (0);
	}
	if (a)
	{
		free(ito[0]);
		free(ito[1]);
	}
	if (a == 2)
		free(ito);
	else if (!(ito[0] = 0))
	{
		ito[1] = 0;
		ito[3] = 0;
	}
	return (0);
}

static	char	*enddbl(char *s, int *i, int r, int l)
{
	if (l != -1)
		r += 4;
	if (*s != '-' && (i[2] == 2 || (i[2] == 1 && (i[1] += write(1, " ", 1)))))
		i[10] -= 1;
	else if (*s == '-' && i[3] == 1 && (i[14] = 1))
		i[1] += write(1, "-", 1);
	if (i[3] == 2 && i[2] == 2 && *s != '-' && (i[1] += write(1, "+", 1)))
		i[1] += write(1, &s[i[14]], ft_strlen(&s[i[14]]));
	else if (i[3] == 2)
		i[1] += write(1, &s[i[14]], ft_strlen(&s[i[14]]));
	while (i[3] != 1 && ((i[10] -= 1) - r > -2))
		i[1] += write(1, " ", 1);
	if (i[2] == 2 && *s != '-' && i[3] != 2)
		i[1] += write(1, "+", 1);
	while (i[3] == 1 && (i[10] -= 1) - r > -2)
		i[1] += write(1, "0", 1);
	if (i[3] != 2)
		i[1] += write(1, &s[i[14]], ft_strlen(&s[i[14]]));
	return (s);
}

static	int		dbltoa(long double c, int i, char **s, long double y)
{
	intmax_t	x;
	int			j;

	if (i == -1)
		i = 6;
	j = i;
	while (j--)
		y /= 10;
	(c < 0 ? c -= y : (c += y));
	x = c;
	s[0] = ft_itoabase(x, 1, '0');
	c -= x;
	if (c < 0)
		c = -c;
	x = 1;
	while ((i -= 1) > -1 && (c *= 10))
	{
		j = c;
		x = x * 10 + j;
		c -= j;
	}
	s[1] = ft_itoabase(x, 0, '0');
	if (ft_strlen(s[0]) + ft_strlen(s[1]) > 8)
		return (0);
	return (1);
}

void			ft_precforp(char *s, int *i)
{
	if (i[11] > -1 && i[3] == 1)
		i[3] = 0;
	if (*s == '0' && !s[1] && !i[11])
	{
		free(s);
		s = ft_strdup("0x");
	}
	else
	{
		while (i[3] == 1 && i[10] - 2 > (int)ft_strlen(s))
			s = ft_joinfree("0", s, 2);
		while (i[11] > (int)ft_strlen(s))
			s = ft_joinfree("0", s, 2);
		s = ft_joinfree("0x", s, 2);
	}
	while (i[3] == 2 && i[10] > (int)ft_strlen(s))
		s = ft_joinfree(s, " ", 1);
	while (i[3] != 2 && i[10] > (int)ft_strlen(s))
		s = ft_joinfree(" ", s, 2);
	i[1] += write(1, s, ft_strlen(s));
	free(s);
}

void			ft_prfdbl(char c, int *i, va_list *ar)
{
	long double	o;
	char		**ito;
	int			l;

	l = -1;
	if (!(ito = (char **)malloc(sizeof(char *) * 3)))
		return ;
	justfree(ito, 0, 0);
	o = ((i[5]) ? va_arg(*ar, long double) : va_arg(*ar, double));
	if (c == 'f' || c == 'F')
		dbltoa(o, i[11], ito, 0.5);
	if ((c == 'e' || c == 'E') || ((c == 'g' || c == 'G') &&
	!(dbltoa(o, i[11], ito, 0.5)) && (justfree(ito, 1, 0))))
	{
		while ((++l > -1) && (o >= 10 || o <= -10))
			o /= 10;
		dbltoa(o, i[11], ito, 0.5);
	}
	enddbl(ito[0], i, ft_strlen(ito[0]) + ft_strlen(ito[1]) + 1, l);
	if (i[11] && (i[1] += write(1, ".", 1)))
		i[1] += write(1, &ito[1][1], ft_strlen(&ito[1][1]));
	if (l != -1 && (i[1] += 4))
		justfree(0, l, c);
	justfree(ito, 2, 0);
}
