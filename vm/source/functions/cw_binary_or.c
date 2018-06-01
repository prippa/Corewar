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

#include "corewar.h"

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
	while (i < 32)
	{
		if (var_1[i] == '1' || var_2[i] == '1')
			var_res[i] = '1';
		else
			var_res[i] = '0';
		i++;
	}
}

int			cw_binary_or(int var_x, int var_y)
{
	char *x;
	char *y;
	char x_stack[33];
	char y_stack[33];
	char res_of_comparison[33];

	x = ft_itoa_base(var_x, 2, 0);
	y = ft_itoa_base(var_y, 2, 0);

	x_stack[32] = '\0';
	y_stack[32] = '\0';
	res_of_comparison[32] = '\0';
	ft_zero_it(x_stack);
	ft_zero_it(y_stack);
	ft_zero_it(res_of_comparison);
	ft_strncpy(&x_stack[32 - (int)ft_strlen(x)], x, (int)ft_strlen(x));
	ft_strncpy(&y_stack[32 - (int)ft_strlen(y)], y, (int)ft_strlen(y));
	binary_or_comparison(x_stack, y_stack, res_of_comparison);
	free(x);
	free(y);
	return (ft_atoi_base(res_of_comparison, 2));
}
