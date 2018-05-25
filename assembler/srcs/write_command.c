/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 11:39:41 by vgladush          #+#    #+#             */
/*   Updated: 2018/05/25 16:08:50 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		write_cod4(char *s, t_asm *am, char cmd, t_command *tmp)
{
	if (s[am->x] != 'r')
		bef_error(s, am, cmd, 1);
	am->x++;
	tmp->codage = 0x54;
	tmp->arg1.tp = T_REG;
	crt_arg(s, am, &tmp->arg1, cmd);
	bef_error(s, am, cmd, 2);
	if (s[am->x] != 'r')
		bef_error(s, am, cmd, 1);
	am->x++;
	tmp->arg2.tp = T_REG;
	crt_arg(s, am, &tmp->arg2, cmd);
	bef_error(s, am, cmd, 2);
	if (s[am->x] != 'r')
		bef_error(s, am, cmd, 1);
	am->x++;
	tmp->arg3.tp = T_REG;
	crt_arg(s, am, &tmp->arg3, cmd);
}

static void		write_cod3(char *s, t_asm *am, char cmd, t_command *tmp)
{
	if (s[am->x] != 'r')
		bef_error(s, am, cmd, 1);
	am->x++;
	tmp->arg1.tp = T_REG;
	crt_arg(s, am, &tmp->arg1, cmd);
	bef_error(s, am, cmd, 2);
	if (s[am->x] != 'r' && !ft_isdigit(s[am->x]) && s[am->x] != LABEL_CHAR)
		bef_error(s, am, cmd, 1);
	tmp->arg2.tp = (s[am->x] != 'r' ? T_REG : T_DIR);
	tmp->codage = (s[am->x] != 'r' && (++am->x) ? 0x50 : 0x70);
	crt_arg(s, am, &tmp->arg2, cmd);
}

static void		write_cod2(char *s, t_asm *am, char cmd, t_command *tmp)
{
	if (s[am->x] != DIRECT_CHAR && !ft_isdigit(s[am->x] && s[am->x] != ':'))
		bef_error(s, am, cmd, 1);
	tmp->codage = (s[am->x] == DIRECT_CHAR ? 0x90 : 0xd0);
	tmp->arg1.tp = (s[am->x] == DIRECT_CHAR && (++am->x) ? T_IND : T_DIR);
	crt_arg(s, am, &tmp->arg1, cmd);
	bef_error(s, am, cmd, 2);
	if (s[am->x] != 'r')
		bef_error(s, am, cmd, 1);
	tmp->arg2.tp = T_REG;
	am->x++;
	crt_arg(s, am, &tmp->arg2, cmd);
}

void			write_cod1(char *s, t_asm *am, char cmd, t_command *tmp)
{
	if (cmd == 16)
	{
		if (s[am->x] != 'r')
			bef_error(s, am, cmd, 1);
		am->x++;
		tmp->codage = 0x40;
		tmp->arg1.tp = T_REG;
		crt_arg(s, am, &tmp->arg1, cmd);
	}
	else
	{
		if (s[am->x] != DIRECT_CHAR)
			bef_error(s, am, cmd, 1);
		am->x++;
		tmp->arg1.tp = (cmd == 1 ? T_IND : T_DIR);
		crt_arg(s, am, &tmp->arg1, cmd);
	}
}

void			write_cod(char *s, t_asm *am, char cmd, t_label *lb)
{
	t_command 	*tmp;

	tmp = find_lb_cmd(lb, s, am, cmd);
	while (s[am->x] == ' ' || s[am->x] == '\t')
		am->x++;
	if (cmd == 1 || cmd == 9 || cmd == 12 || cmd == 15 || cmd == 16)
		write_cod1(s, am, cmd, tmp);
	else if (cmd == 2 || cmd == 13)
		write_cod2(s, am, cmd, tmp);
	else if (cmd == 3)
		write_cod3(s, am, cmd, tmp);
	else if (cmd == 4 || cmd == 5)
		write_cod4(s, am, cmd, tmp);
	else if (cmd == 6 || cmd == 7 || cmd == 8)
		write_cod5(s, am, cmd, tmp);
	else if (cmd == 10 || cmd == 14)
		write_cod6(s, am, cmd, tmp);
	else
		write_cod7(s, am, cmd, tmp);
	am->hd.prog_size += (tmp->codage ? 2 : 1);
	am->hd.prog_size += tmp->arg1.tp + tmp->arg2.tp + tmp->arg3.tp;
	bef_error(s, am, cmd, 0);
}
