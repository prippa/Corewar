/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_command2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 11:43:00 by vgladush          #+#    #+#             */
/*   Updated: 2018/05/27 00:09:57 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_cod7(char *s, t_asm *am, char cmd, t_command *tm)
{
	if (s[am->x] != 'r')
		bef_error(s, am, cmd, 1);
	am->x++;
	tm->arg1.tp = T_REG;
	tm->codage = 0x54;
	crt_arg(s, am, &tm->arg1, cmd);
	bef_error(s, am, cmd, 2);
	if (T_DNR(s[am->x]) && !ft_isdigit(s[am->x]))
		bef_error(s, am, cmd, 1);
	tm->codage += (T_DTR(s[am->x]) ? 0x20 : 0);
	tm->codage += (s[am->x] == DIRECT_CHAR ? 0x10 : 0);
	tm->arg2.tp = (s[am->x] == 'r' ? T_REG : T_DIR);
	am->x += (s[am->x] == 'r' || s[am->x] == DIRECT_CHAR ? 1 : 0);
	crt_arg(s, am, &tm->arg2, cmd);
	bef_error(s, am, cmd, 2);
	if (s[am->x] != DIRECT_CHAR && s[am->x] != 'r')
		bef_error(s, am, cmd, 1);
	tm->codage += (s[am->x] == DIRECT_CHAR ? 0x04 : 0);
	tm->arg3.tp = (s[am->x] == 'r' ? T_REG : T_DIR);
	am->x++;
	crt_arg(s, am, &tm->arg3, cmd);
}

void	write_cod6(char *s, t_asm *am, char cmd, t_command *tm)
{
	if (T_DNR(s[am->x]) && !ft_isdigit(s[am->x]))
		bef_error(s, am, cmd, 1);
	tm->codage = (T_DTR(s[am->x]) ? 0xd4 : 0x54);
	tm->codage = (s[am->x] == DIRECT_CHAR ? 0x94 : tm->codage);
	tm->arg1.tp = (s[am->x] == 'r' ? T_REG : T_DIR);
	am->x += (s[am->x] == 'r' || s[am->x] == DIRECT_CHAR ? 1 : 0);
	crt_arg(s, am, &tm->arg1, cmd);
	bef_error(s, am, cmd, 2);
	if (s[am->x] != DIRECT_CHAR && s[am->x] != 'r')
		bef_error(s, am, cmd, 1);
	tm->codage += (s[am->x] == DIRECT_CHAR ? 0x10 : 0);
	tm->arg2.tp = (s[am->x] == 'r' ? T_REG : T_DIR);
	am->x++;
	crt_arg(s, am, &tm->arg2, cmd);
	bef_error(s, am, cmd, 2);
	if (s[am->x] != 'r')
		bef_error(s, am, cmd, 1);
	am->x++;
	tm->arg3.tp = T_REG;
	crt_arg(s, am, &tm->arg3, cmd);
}

void	write_cod5(char *s, t_asm *am, char cmd, t_command *tm)
{
	if (T_DNR(s[am->x]) && !ft_isdigit(s[am->x]))
		bef_error(s, am, cmd, 1);
	tm->codage = (T_DTR(s[am->x]) ? 0xd4 : 0x54);
	tm->codage = (s[am->x] == DIRECT_CHAR ? 0x94 : tm->codage);
	tm->arg1.tp = (s[am->x] == 'r' ? T_REG : T_DIR);
	am->x += (s[am->x] == 'r' || s[am->x] == DIRECT_CHAR ? 1 : 0);
	crt_arg(s, am, &tm->arg1, cmd);
	bef_error(s, am, cmd, 2);
	if (T_DNR(s[am->x]) && !ft_isdigit(s[am->x]))
		bef_error(s, am, cmd, 1);
	tm->codage += (T_DTR(s[am->x]) ? 0x20 : 0);
	tm->codage += (s[am->x] == DIRECT_CHAR ? 0x10 : 0);
	tm->arg2.tp = (s[am->x] == 'r' ? T_REG : T_DIR);
	am->x += (s[am->x] == 'r' || s[am->x] == DIRECT_CHAR ? 1 : 0);
	crt_arg(s, am, &tm->arg2, cmd);
	bef_error(s, am, cmd, 2);
	if (s[am->x] != 'r')
		bef_error(s, am, cmd, 1);
	am->x++;
	tm->arg3.tp = T_REG;
	crt_arg(s, am, &tm->arg3, cmd);
}
