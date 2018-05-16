/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 04:00:04 by vgladush          #+#    #+#             */
/*   Updated: 2017/11/10 04:00:05 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_degree(int a, int b)
{
	int i;

	i = a;
	while (b-- > 1)
		a *= i;
	return (a);
}

int			ft_calc(char *str)
{
	int		a;
	int		b;
	char	z;

	a = ft_atoi(str++);
	while (*str != '*' && *str != '/' && *str != ':' && *str != '+' &&
		*str != '-' && *str != '\'' && *str != '%')
		str++;
	z = *str++;
	b = ft_atoi(str);
	if (z == '*')
		return (a * b);
	else if (z == '/' || z == ':')
		return (a / b);
	else if (z == '+')
		return (a + b);
	else if (z == '-')
		return (a - b);
	else if (z == '%')
		return (a % b);
	else if (z == '\'')
		return (ft_degree(a, b));
	return (0);
}
