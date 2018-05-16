/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prfoper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:50:45 by vgladush          #+#    #+#             */
/*   Updated: 2018/01/15 13:31:30 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			strendf(char s, int *i)
{
	if (!s && i[13] != 1 && i[8] != 9)
		*i -= 1;
	else
	{
		if (i[3] == 2)
		{
			if (s)
				i[1] += write(1, &s, 1);
			else
				i[1] += write(1, "\0", 1);
			while ((i[10] -= 1) > 0)
				i[1] += write(1, " ", 1);
		}
		else
		{
			while (i[3] == 1 && (i[10] -= 1) > 0)
				i[1] += write(1, "0", 1);
			while (!i[3] && (i[10] -= 1) > 0)
				i[1] += write(1, " ", 1);
			if (s)
				i[1] += write(1, &s, 1);
			else if (i[8] == 9)
				i[1] += write(1, "\0", 1);
		}
	}
}

static	int		prstsec(va_list *ar, int *i, char *un, int f)
{
	va_list		rrr;

	va_copy(rrr, *ar);
	if (f && !va_arg(rrr, void *))
		return (1);
	else if (f)
		return (0);
	if (!(un = va_arg(*ar, char *)))
	{
		if (i[11] < 0)
			un = ft_strdup("(null)");
		else
			un = ft_strdup("");
		while (i[11] > (int)ft_strlen(un))
			un = ft_joinfree("0", un, 2);
		ft_qstr(un, i);
		free(un);
	}
	else
		ft_qstr(un, i);
	return (0);
}

static	void	prfstr(char s, va_list *ar, int *i, char *un)
{
	if (i[7] || s == 'S' || s == 'C')
	{
		if ((s == 'c' || s == 'C') && (i[8] = 9)
			&& (i[16] = -1))
		{
			if (!(un = unicd(va_arg(*ar, int))) && (i[10] -= 1))
				un = ft_strdup("");
			ft_qstr(un, i);
		}
		if (s == 's' || s == 'S')
		{
			if (!(un = unistr(va_arg(*ar, wchar_t *), i))
				&& (i[16] = 7))
				un = ft_strdup("(null)");
			ft_outun(un, i, 0, 0);
		}
		free(un);
	}
	else
		prstsec(ar, i, un, 0);
}

static	void	opersec(char *s, va_list *ar, int *i, char *st)
{
	if (OPER(s[*i]) && OPE2(s[*i]) && OPE3(s[*i]))
		strendf(s[*i], i);
	else if (s[*i] == 'Z')
		ft_qstr(ft_rotnb(va_arg(*ar, char *), 42), i);
	else if (s[*i] == 'Y')
		ft_qstr(ft_rotnb(va_arg(*ar, char *), -42), i);
	else if ((s[*i] == 'a' || s[*i] == 'A') && i[5])
		ft_dblhex(va_arg(*ar, long double), i, s[*i]);
	else if (s[*i] == 'a' || s[*i] == 'A')
		ft_dblhex(va_arg(*ar, double), i, s[*i]);
	else if (DEVAL(s[*i]) || DEVA2(s[*i]))
		ft_prfnbr(s[*i], i, ar, st);
	else if (s[*i] == 'p' && (st = ft_itoabase(va_arg(*ar, uintmax_t), 16, 97)))
		ft_precforp(st, i);
	else if (s[*i] == 'R' || s[*i] == 'r' || s[*i] == 'B')
	{
		if (s[*i] == 'R')
			i[13] = 16;
		else
			i[13] = (s[*i] == 'r' ? 8 : 2);
		ft_qstr(ft_itoabase(ft_basetoint(va_arg(*ar, char *), i[13]), 0, 0), i);
	}
	else
		ft_prfdbl(s[*i], i, ar);
}

void			ft_prfoper(char *s, va_list *ar, int *i)
{
	char		*st;
	char		c;

	st = NULL;
	if (s[*i] == 'n')
	{
		if (prstsec(0, 0, 0, 1))
			return ;
		if (i[8] != 2 && i[8] != 1)
			*va_arg(*ar, unsigned int *) = i[1];
		else if (i[8] == 2)
			*va_arg(*ar, int *) = (unsigned short int)i[1];
		else if (i[8] == 1)
			*va_arg(*ar, int *) = (unsigned char)i[1];
	}
	else if (s[*i] == 'c' || s[*i] == 'C' || s[*i] == 's' || s[*i] == 'S')
	{
		if (!i[7] && s[*i] == 'c' && ((c = va_arg(*ar, int))
			|| (i[8] = 9)))
			strendf(c, i);
		else
			prfstr(s[*i], ar, i, st);
	}
	else
		opersec(s, ar, i, st);
}
