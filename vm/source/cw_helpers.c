/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:25:00 by prippa            #+#    #+#             */
/*   Updated: 2018/06/06 12:25:01 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cw_get_dec_from_the_point(unsigned char *str,
						int quantity, int position)
{
	int res;
	int i;
	int j;

	res = 0;
	i = 0;
	j = position;

	// ft_printf("quantity -> %d\n", quantity);
	// ft_printf("position -> %d\n", position);

	// ft_printf("mod -> %d\n", (0 + (16777216 - 1) % IDX_MOD) % IDX_MOD);

	// int k = 0;
	// while (k < 4096)
	// {
	// 	ft_printf("d->%d\n", str[k]);
	// 	k++;
	// }
	CIRCLE_OF_LIFE(j);

	unsigned char buf [4];

	while (i < 4)
	{
		// ft_printf("d->%d\n", str[j] - '0');
		// ft_printf("c->%c\n", str[j]);
		if (str[j] == 48)
			buf[i] = 0;
		else
			buf[i] = str[j];
		i++;
		j++;
	}
	// i = 0;

	// while (i < 4)
	// {
	// 	ft_printf("%.u", buf[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	res = cw_hex_to_dec(buf, 4);
	// ft_printf("res --> %d\n", res);
	return (res);
}

int		cw_hex_to_dec(unsigned char *buf, int i)
{
	int res;

	res = 0;
	if (!i)
		return (0);
	if (i == 4)
	{
		res += buf[0] * 16777216;
		res += buf[1] * 65536;
		res += buf[2] * 256;
		res += buf[3];
	}
	else if (i == 2)
	{
		res += buf[0] * 256;
		res += buf[1];
		res = (short)res;
	}
	else
	{
		res += buf[0];
		res = (short)res;
	}
	return (res);
}
