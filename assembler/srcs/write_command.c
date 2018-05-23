/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 11:39:41 by vgladush          #+#    #+#             */
/*   Updated: 2018/05/24 00:15:27 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		write_cod5(char *s, t_asm *am, char cmd, t_label *lb)
{
	if (i != 6 && i != 7 && i != 8)
		write_cod6(s, am, i, lb);
	else
	{

	}
}

static void		write_cod4(char *s, t_asm *am, char cmd, t_label *lb)
{
	if (i != 4 && i != 5)
		write_cod5(s, am, i, lb);
	else
	{

	}
}

static void		write_cod3(char *s, t_asm *am, char cmd, t_label *lb)
{
	if (i != 3)
		write_cod4(s, am, i, lb);
	else
	{

	}
}

static void		write_cod2(char *s, t_asm *am, char cmd, t_label *lb)
{
	if (i != 2 && i != 13)
		write_cod3(s, am, i, lb);
	else
	{

	}
}

void			write_cod(char *s, t_asm *am, char cmd, t_label *lb)
{
	t_command 	*tmp;

	while (s[am->x] == ' ' || s[am->x] == '\t')
		am->x++;
	if (cmd != 1 && cmd != 9 && cmd != 12 && cmd != 15)
		write_cod2(s, am, cmd, lb);
	else
	{
		if (s[am->x++] != DIRECT_CHAR)
			bef_error(s, am, cmd, 1);
		if (!(tmp = find_lb_cmd(lb, am->hd.prog_size)))
			errors_man(am, s, 10);
		tmp->codage = 0;
		tmp->arg1.tp = T_DIR;
		tmp->arg2 = 0;
		tmp->arg3 = 0;
		crt_arg(s, am, &tmp->arg1, cmd);
		bef_error(s, am, cmd, 0);
	}
}
