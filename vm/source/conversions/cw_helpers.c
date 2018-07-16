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

void			cw_write_bytes_to_buf(unsigned char *buf, int nbr)
{
	int tmp;

	tmp = nbr;
	tmp = tmp >> 24;
	buf[0] = tmp;
	tmp = nbr;
	tmp = tmp << 8;
	tmp = tmp >> 24;
	buf[1] = tmp;
	tmp = nbr;
	tmp = tmp << 16;
	tmp = tmp >> 24;
	buf[2] = tmp;
	tmp = nbr;
	tmp = tmp << 24;
	tmp = tmp >> 24;
	buf[3] = tmp;
}

void			cw_write_to_map(unsigned char *buf, int pc)
{
	int	i;

	i = 0;
	if ((pc = MEM_X(pc)) < 0)
		pc += MEM_SIZE;
	while (i < 4)
	{
		g_cw.map[pc] = buf[i];
		i++;
		pc = MEM_X((pc + 1));
	}
}

int				cw_get_dec_from_the_point(int pc, const int label)
{
	unsigned char	buf[label];
	int				res;
	int				i;

	if (label == 0)
		return (0);
	res = 0;
	i = 0;
	if ((pc = MEM_X(pc)) < 0)
		pc += MEM_SIZE;
	while (i < label)
	{
		buf[i] = g_cw.map[pc];
		pc = MEM_X((pc + 1));
		i++;
	}
	res = cw_hex_to_dec(buf, label);
	return (res);
}

int				cw_hex_to_dec(unsigned char *buf, int i)
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
