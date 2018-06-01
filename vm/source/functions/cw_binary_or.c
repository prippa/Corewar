/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_binary_or.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 14:32:17 by otimofie          #+#    #+#             */
/*   Updated: 2018/06/01 14:32:18 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_pow(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

static char	*ft_itoa_base(int value, int base)
{
	int		i;
	char	*nbr;
	int		neg;

	i = 1;
	neg = 0;
	if (value < 0)
	{
		if (base == 10)
			neg = 1;
		value *= -1;
	}
	while (ft_pow(base, i) - 1 < value)
		i++;
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		nbr[i + neg] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value = value / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}

static int		test_base(const char c)
{
	int		nb;

	if (c >= '0' && c <= '9')
		nb = c - '0';
	else if (c >= 'a' && c <= 'z')
		nb = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		nb = c - 'A' + 10;
	else
		nb = -1;
	return (nb);
}

static int		ft_atoi_base(const char *str, int str_base)
{
	int		neg;
	int		nb;
	int		current;

	nb = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\f' || *str == '\r' || *str == '\v')
		str++;
	neg = (*str == '-' ? 1 : 0);
	if (*str == '-' || *str == '+')
		str++;
	current = test_base(*str);
	while (current >= 0 && current < str_base)
	{
		nb = nb * str_base + current;
		str++;
		current = test_base(*str);
	}
	return (neg ? -nb : nb);
}

static void	ft_zero_it(char *str)
{
	int i = 0;
	while (i < 32)
		str[i++] = '0';
}

static void		binary_or_comparison(char *var_1, char *var_2, char *var_res)
{
	int i;

	i = 0;

	// ft_printf("var_1 -> %s\n", var_1);
	// ft_printf("var_2 -> %s\n", var_2);

	while (i < 32)
	{
		if (var_1[i] == '1' || var_2[i] == '1')
			var_res[i] = '1';
		else
			var_res[i] = '0';
		i++;
	}
}

int			binary_or(int var_x, int var_y)
{
	char *x;
	char *y;
	char x_stack[33]; // when we have memory on stack we do not have a '\0';
	char y_stack[33];
	char res_of_comparison[33];

	x = ft_itoa_base(var_x, 2);
	y = ft_itoa_base(var_y, 2);
	// ft_bzero(x_stack, 33); 
	// ft_bzero(y_stack, 33);
	x_stack[32] = '\0'; // last element <=> 33 = '\0'
	y_stack[32] = '\0'; // last element <=> 33 = '\0
	res_of_comparison[32] = '\0'; // last element <=> 33 = '\0
	ft_zero_it(x_stack);
	ft_zero_it(y_stack);
	ft_zero_it(res_of_comparison);
	// ft_printf("x_stack -> %s, len -> %d\n", x_stack, (int)ft_strlen(x_stack));
	ft_strncpy(&x_stack[32 - (int)ft_strlen(x)], x, (int)ft_strlen(x));
	ft_strncpy(&y_stack[32 - (int)ft_strlen(y)], y, (int)ft_strlen(y));
	// ft_printf("x_stack -> %s\n", x_stack);
	// ft_printf("y_stack -> %s\n", y_stack);
	binary_or_comparison(x_stack, y_stack, res_of_comparison);
	// ft_printf("res     -> %s\n", res_of_comparison);
	free(x);
	free(y);
	return (ft_atoi_base(res_of_comparison, 2));
}
