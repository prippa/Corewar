/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prfnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 19:23:04 by vgladush          #+#    #+#             */
/*   Updated: 2018/01/12 18:34:37 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*checkshar(char *ito, int *i, char c)
{
	char		*res;

	res = ito;
	if (c == 'o' || c == 'O')
	{
		i[10] -= 1;
		if (*ito != '0')
			res = ft_joinfree("0", ito, 2);
	}
	else if (!*ito || (*ito == '0' && !ito[1]))
		return (ito);
	else if (i[3] != 1 && (c == 'X' || c == 'x'))
	{
		i[10] -= 2;
		if (!(res = (char *)malloc(sizeof(char) * ft_strlen(ito) + 3)))
			return (0);
		res[0] = '0';
		res[1] = c;
		res[2] = '\0';
		res = ft_joinfree(res, ito, 3);
	}
	else if ((c == 'X' || c == 'x') && (i[10] -= 2))
		i[1] += ft_printf("0%c", c);
	return (res);
}

static	char	*tochsize(char *ito, int *i, int *r)
{
	char		*s;
	char		*res;
	char		*fr;

	if (!(s = (char *)malloc(sizeof(char) * (*r + i[11] + 2))))
		return (0);
	res = s;
	fr = ito;
	if (*ito == '0' && !ito[1] && !i[11])
		ito++;
	else if (i[2] == 2 && *ito != '-')
		*s++ = '+';
	else if (i[2] == 1 && *ito != '-')
		*s++ = ' ';
	else if (*ito == '-' && *ito++ && (i[11] += 1))
		*s++ = '-';
	while (((i[11] -= 1) - *r) > -1)
		*s++ = '0';
	while (!(i[2] = 0) && *ito)
		*s++ = *ito++;
	*s = '\0';
	if ((*r = ft_strlen(res)) && i[3] == 1)
		i[3] = 0;
	free(fr);
	return (res);
}

static	char	*endprf(char *s, int *i, int r, char c)
{
	if (i[11] > -1)
		s = tochsize(s, i, &r);
	if (i[4] && (c == 'X' || c == 'x' || c == 'o' || c == 'O'))
		s = checkshar(s, i, c);
	if (*s != '-' && (i[2] == 2 || (i[2] == 1 && (i[1] += write(1, " ", 1)))))
		i[10] -= 1;
	else if (*s == '-' && i[3] == 1 && (i[14] = 1))
		i[1] += write(1, "-", 1);
	if (i[3] == 2 && i[2] == 2 && *s != '-' && (i[1] += write(1, "+", 1)))
		i[1] += write(1, &s[i[14]], ft_strlen(&s[i[14]]));
	else if (i[3] == 2)
		i[1] += write(1, &s[i[14]], ft_strlen(&s[i[14]]));
	while (i[3] != 1 && ((i[10] -= 1) - r > -1))
		i[1] += write(1, " ", 1);
	if (i[2] == 2 && *s != '-' && i[3] != 2)
		i[1] += write(1, "+", 1);
	while (i[3] == 1 && (i[10] -= 1) - r > -1)
		i[1] += write(1, "0", 1);
	if (i[3] != 2)
		i[1] += write(1, &s[i[14]], ft_strlen(&s[i[14]]));
	return (s);
}

static	void	prfsec(char c, int *i, va_list *ar, char *ito)
{
	if (c == 'o' || c == 'O')
		i[13] = 8;
	else if (c == 'b')
		i[13] = 2;
	else if (c == 'X' || c == 'x')
		i[13] = 16;
	if (i[6] || i[8] == 3)
		ito = ft_itoabase(va_arg(*ar, uintmax_t), i[13], c);
	else if (i[7] || c == 79 || c == 85)
		ito = ft_itoabase(va_arg(*ar, unsigned long), i[13], c);
	else if (!i[8])
		ito = ft_itoabase(va_arg(*ar, unsigned int), i[13], c);
	else if (i[8] == 2)
		ito = ft_itoabase((unsigned short)va_arg(*ar, int), i[13], c);
	else if (i[8] == 1)
		ito = ft_itoabase((unsigned char)va_arg(*ar, int), i[13], c);
	if (i[10] > (int)ft_strlen(ito) || i[11] > -1 || i[4])
		ito = endprf(ito, i, ft_strlen(ito), c);
	else if (i[2] == 2 && (i[1] += write(1, "+", 1)))
		i[1] += write(1, ito, ft_strlen(ito));
	else if (i[2] == 1 && (i[1] += write(1, " ", 1)))
		i[1] += write(1, ito, ft_strlen(ito));
	else
		i[1] += write(1, ito, ft_strlen(ito));
	free(ito);
}

void			ft_prfnbr(char c, int *i, va_list *ar, char *ito)
{
	if ((c == 'd' || c == 'i' || c == 'D') && (i[13] = 1))
	{
		if (i[6] || i[8] == 3)
			ito = ft_itoabase(va_arg(*ar, intmax_t), i[13], c);
		else if (i[7] || c == 'D')
			ito = ft_itoabase(va_arg(*ar, long), i[13], c);
		else if (!i[8])
			ito = ft_itoabase(va_arg(*ar, int), i[13], c);
		else if (i[8] == 2)
			ito = ft_itoabase((short)va_arg(*ar, int), i[13], c);
		else if (i[8] == 1)
			ito = ft_itoabase((signed char)va_arg(*ar, int), i[13], c);
		if (i[10] > (int)ft_strlen(ito) || i[11] > -1)
			ito = endprf(ito, i, ft_strlen(ito), c);
		else if (i[2] == 2 && *ito != '-' && (i[1] += write(1, "+", 1)))
			i[1] += write(1, ito, ft_strlen(ito));
		else if (i[2] == 1 && *ito != '-' && (i[1] += write(1, " ", 1)))
			i[1] += write(1, ito, ft_strlen(ito));
		else
			i[1] += write(1, ito, ft_strlen(ito));
		free(ito);
	}
	else if (!(i[2] = 0))
		prfsec(c, i, ar, ito);
}
