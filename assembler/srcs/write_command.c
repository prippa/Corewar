/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 11:39:41 by vgladush          #+#    #+#             */
/*   Updated: 2018/05/24 18:58:25 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// static void		write_cod5(char *s, t_asm *am, char cmd, t_label *lb)
// {
// 	if (cmd != 6 && cmd != 7 && cmd != 8)
// 		write_cod6(s, am, cmd, lb);
// 	else
// 	{

// 	}
// }

// static void		write_cod4(char *s, t_asm *am, char cmd, t_label *lb)
// {
// 	if (cmd != 4 && cmd != 5)
// 		write_cod5(s, am, cmd, lb);
// 	else
// 	{

// 	}
// }

// static void		write_cod3(char *s, t_asm *am, char cmd, t_label *lb)
// {
// 	if (cmd != 3)
// 		write_cod4(s, am, cmd, lb);
// 	else
// 	{

// 	}
// }

// static void		write_cod2(char *s, t_asm *am, char cmd, t_label *lb)
// {
// 	if (cmd != 2 && cmd != 13)
// 		write_cod3(s, am, cmd, lb);
// 	else
// 	{

// 	}
// }

void			write_cod(char *s, t_asm *am, char cmd, t_label *lb)
{
	t_command 	*tmp;

	while (s[am->x] == ' ' || s[am->x] == '\t')
		am->x++;
	if (cmd != 1 && cmd != 9 && cmd != 12 && cmd != 15)
		// write_cod2(s, am, cmd, lb);
		;
	else
	{
		if (s[am->x++] != DIRECT_CHAR)
			bef_error(s, am, cmd, 1);
		if (!(tmp = find_lb_cmd(lb, am->hd.prog_size)))
			errors_man(am, s, 10);
		tmp->codage = 0;
		tmp->arg1.tp = (cmd == 1 ? T_IND : T_DIR);
		tmp->arg2.tp = 0;
		tmp->arg3.tp = 0;
		crt_arg(s, am, &tmp->arg1, cmd);
		if (tmp->arg1.tp == 1)
			write("%d\n", *(char *)tmp->arg1.av);
		else
			printf("%s\n", (char *)tmp->arg1.av);
		bef_error(s, am, cmd, 0);
	}
}
