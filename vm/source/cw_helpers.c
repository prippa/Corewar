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

static char	*cw_get_string_for_conversion(int nbr)
{
	int i;
	char *str;
	char *check;
	
	i = 0;
	if (!(str = ft_itoa_base(nbr, 2, 87)))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
	if (!(check = ft_strnew(32)))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
	while (i < 32)
	{
		check[i] = '0';
		i++;
	}
	if (nbr < 0)
		ft_strncpy(&check[0], &str[32], ft_strlen(str) - 32);
	else
		ft_strncpy(&check[32 - ft_strlen(str)], &str[0], ft_strlen(str));
	free(str);
	return (check);
}

void		cw_write_bytes_to_buf(unsigned char *buf, int nbr)
{
	char *check;
	int i;
	int k;

	// ft_printf("nbr -> %d\n", nbr);

	i = 0;
	check = cw_get_string_for_conversion(nbr); // o.k. +++

	// ft_printf("check -> %s\n", check);
	k = 7;
	while (i < 4)
	{
		buf[i] = ft_bin_to_int(check, k);
		k += 8;
		i++;
	}
	free(check);
}

void		cw_write_to_map(t_stack *map, t_processes *proc, unsigned char *buf,
			int position_on_the_map)
{
	unsigned short i;

	i = 0;
	// buf[0] = 0x00;
	// buf[1] = 0x30;
	// buf[2] = 0x00;
	// buf[3] = 0x00;
	while (i < 4) // 2 || 4; // always take 4 bytes to the map;
	{
		if (position_on_the_map == MEM_SIZE)
			position_on_the_map = 0;

		// ft_printf("map[i] -> %d", buf[i]);

		map->stack[position_on_the_map] = buf[i];


		if (map->stack_color[position_on_the_map] != proc->proc_process_PC_color) // maybe here for 4894;
		{ ////////////////////////////////////////////// costello for not overwriting; // ? fork;
		// ft_printf ("proc->proc_color_write_to_map -> %d\n", proc->proc_color_write_to_map);
		map->stack_color[position_on_the_map] = proc->proc_color_write_to_map;
		}





		map->write_to_the_map_stack[position_on_the_map] = proc->proc_color_write_to_map + 50; // -> 59;
		map->cycle_stack[position_on_the_map] = 50; // -> 0 -> execute;



		i++;
		position_on_the_map++;
//		map->stack_process_id[position_on_the_map++] = proc->id;
	}
}

int			cw_get_dec_from_the_point(unsigned char *str, int position)
{
	int res;
	int i;
	int j;

	res = 0;
	i = 0;
	j = MEM_CORRECTION(position);
	j = (j < 0) ? MEM_SIZE + j : j;

	// ft_printf("quantity -> %d\n", quantity);
	// ft_printf("position -> %d\n", position);

	// ft_printf("mod -> %d\n", (0 + (16777216 - 1) % IDX_MOD) % IDX_MOD);

	// int k = 0;
	// while (k < 4096)
	// {
	// 	ft_printf("d->%d\n", str[k]);
	// 	k++;
	// }

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

int			cw_hex_to_dec(unsigned char *buf, int i)
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
