/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:26:32 by vgladush          #+#    #+#             */
/*   Updated: 2018/01/12 12:28:14 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		flbax(char *s, va_list *ar2, int *i)
{
	if (ar2)
	{
		if (i[15] == 1 && (*i += 1))
		{
			i[15] = ft_atoi(&s[*i]);
			while (i[15] > 1 && (i[15] -= 1))
				va_arg(*ar2, void *);
			*i += ft_nbrlen(i[15], 1);
		}
		return (1);
	}
	while (*s)
	{
		if (*s == '%' && (*s++))
		{
			while (OPER(*s) && OPE2(*s) && OPE3(*s) && *s)
			{
				if (*s > 47 && *s < 58 && *(s + 1) == '$' && (i[15] = 1))
					return (1);
				s++;
			}
		}
		s++;
	}
	return (0);
}

static	void	flg_sec(char *s, int *i, va_list *ar2)
{
	if (s[*i] == 'h' && s[*i + 1] != 'h' && i[8] < 2)
		i[8] = 2;
	else if (s[*i] == 'h' && s[*i + 1] == 'h' && (*i += 1) && !i[8])
		i[8] = 1;
	else if (s[*i] == 'j' || (s[*i] == 'l' && s[*i + 1] == 'l' && (*i += 1)))
		i[8] = 3;
	else if (s[*i] == '*' && (flbax(s, ar2, i)))
	{
		if (((i[10] = va_arg(*ar2, int)) < 0) && (i[10] *= -1))
			i[3] = 2;
	}
	else if (s[*i] > 48 && s[*i] < 58 && (i[10] = ft_atoi(s + *i)))
		*i += ft_nbrlen(i[10], 1) - 1;
	else if (s[*i] == '.' && !(i[11] = 0) && (*i += 1))
	{
		if (s[*i] == '*' && (flbax(s, ar2, i)))
			i[11] = va_arg(*ar2, int);
		else if (s[*i] > 47 && s[*i] < 58)
			i[11] = ft_atoi(s + *i);
		else
			*i -= 1;
		while (s[*i] > 47 && s[*i] < 58 && s[*i + 1] > 47 && s[*i + 1] < 58)
			*i += 1;
	}
}

static	void	flg_fir(char *s, va_list *ar, int *i, va_list *ar2)
{
	while (FLSIZ(s[*i]) || FL2(s[*i]))
	{
		if (s[*i] == ' ' && !i[2])
			i[2] = 1;
		else if (s[*i] == '+')
			i[2] = 2;
		else if (s[*i] == '-')
			i[3] = 2;
		else if (s[*i] == '0' && !i[3])
			i[3] = 1;
		else if (s[*i] == '#')
			i[4] = 1;
		else if (s[*i] == 'L')
			i[5] = 1;
		else if (s[*i] == 'z')
			i[6] = 1;
		else if (s[*i] == 'l' && s[*i + 1] != 'l')
			i[7] = 1;
		else
			flg_sec(s, i, ar2);
		*i += 1;
	}
	ft_prfoper(s, ar, i);
}

static	int		ft_sprintf(char *str, va_list varg, int *i)
{
	va_list		tmp[2];

	while (str[*i])
	{
		if (str[*i] != '%')
			i[1] += write(1, &str[*i], 1);
		else if ((*i += 1) && (i[15] = ft_atoi(&str[*i])))
		{
			va_copy(tmp[0], varg);
			va_copy(tmp[1], varg);
			*i += ft_nbrlen(i[15], 1) + 1;
			while ((i[15] -= 1))
				va_arg(tmp[0], void *);
			i[15] = 1;
			while (i[15] && (i[15] += 1))
				i[i[15]] = 0;
			i[15] = 1;
			i[11] = -1;
			flg_fir((char *)str, tmp, i, &tmp[1]);
		}
		*i += 1;
	}
	va_end(varg);
	return (i[1]);
}

int				ft_printf(const char *format, ...)
{
	int			i[19];
	va_list		varg;

	i[0] = 0;
	i[1] = 0;
	va_start(varg, format);
	if (flbax((char *)format, 0, i))
		return (ft_sprintf((char *)format, varg, i));
	while (format[i[0]])
	{
		if (format[i[0]] != '%')
			i[1] += write(1, &format[i[0]], 1);
		else if ((i[0] += 1))
		{
			i[18] = 1;
			while (i[18] && (i[18] += 1))
				i[i[18]] = 0;
			i[11] = -1;
			flg_fir((char *)format, &varg, i, &varg);
		}
		i[0] += 1;
	}
	va_end(varg);
	return (i[1]);
}
