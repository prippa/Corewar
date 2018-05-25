/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_command2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 11:43:00 by vgladush          #+#    #+#             */
/*   Updated: 2018/05/25 16:26:32 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_cod7(char *s, t_asm *am, char cmd, t_command *tmp)
{
	if (s[am->x] != 'r')
		bef_error(s, am, cmd, 1);
	am->x++;
	tmp->arg1.tp = T_REG;
	tmp->codage = 0x54;
	crt_arg(s, am, &tmp->arg1, cmd);
	bef_error(s, am, cmd, 2);
	if (s[am->x] != DIRECT_CHAR && !ft_isdigit(s[am->x]) && s[am->x] != 'r' &&
		s[am->x] != LABEL_CHAR)
		bef_error(s, am, cmd, 1);
	tmp->codage += (ft_isdigit(s[am->x]) || s[am->x] == ':' ? 0x20 : 0);
	tmp->codage += (s[am->x] == DIRECT_CHAR ? 0x10 : 0);
	tmp->arg2.tp = (s[am->x] == 'r' ? T_REG : T_DIR);
	am->x += (s[am->x] == 'r' || s[am->x] == DIRECT_CHAR ? 1 : 0);
	crt_arg(s, am, &tmp->arg2, cmd);
	bef_error(s, am, cmd, 2);
	if (s[am->x] != DIRECT_CHAR && s[am->x] != 'r')
		bef_error(s, am, cmd, 1);
	tmp->codage += (s[am->x] == DIRECT_CHAR ? 0x04 : 0);
	tmp->arg3.tp = (s[am->x] == 'r' ? T_REG : T_DIR);
	am->x++;
	crt_arg(s, am, &tmp->arg3, cmd);
}

void	write_cod6(char *s, t_asm *am, char cmd, t_command *tmp)
{
	if (s[am->x] != DIRECT_CHAR && !ft_isdigit(s[am->x]) && s[am->x] != 'r' &&
		s[am->x] != LABEL_CHAR)
		bef_error(s, am, cmd, 1);
	tmp->codage = (ft_isdigit(s[am->x]) || s[am->x] == ':' ? 0xd4 : 0x54);
	tmp->codage = (s[am->x] == DIRECT_CHAR ? 0x94 : tmp->codage);
	tmp->arg1.tp = (s[am->x] == 'r' ? T_REG : T_DIR);
	am->x += (s[am->x] == 'r' || s[am->x] == DIRECT_CHAR ? 1 : 0);
	crt_arg(s, am, &tmp->arg1, cmd);
	bef_error(s, am, cmd, 2);
	if (s[am->x] != DIRECT_CHAR && s[am->x] != 'r')
		bef_error(s, am, cmd, 1);
	tmp->codage += (s[am->x] == DIRECT_CHAR ? 0x10 : 0);
	tmp->arg2.tp = (s[am->x] == 'r' ? T_REG : T_DIR);
	am->x++;
	crt_arg(s, am, &tmp->arg2, cmd);
	bef_error(s, am, cmd, 2);
	if (s[am->x] != 'r')
		bef_error(s, am, cmd, 1);
	am->x++;
	tmp->arg3.tp = T_REG;
	crt_arg(s, am, &tmp->arg3, cmd);
}

void	write_cod5(char *s, t_asm *am, char cmd, t_command *tmp)
{
	if (s[am->x] != DIRECT_CHAR && !ft_isdigit(s[am->x]) && s[am->x] != 'r' &&
		s[am->x] != LABEL_CHAR)
		bef_error(s, am, cmd, 1);
	tmp->codage = (ft_isdigit(s[am->x]) || s[am->x] == ':' ? 0xd4 : 0x54);
	tmp->codage = (s[am->x] == DIRECT_CHAR ? 0x94 : tmp->codage);
	tmp->arg1.tp = (s[am->x] == DIRECT_CHAR ? T_IND : T_DIR);
	tmp->arg1.tp = (s[am->x] == 'r' ? T_REG : tmp->arg1.tp);
	am->x += (s[am->x] == 'r' || s[am->x] == DIRECT_CHAR ? 1 : 0);
	crt_arg(s, am, &tmp->arg1, cmd);
	bef_error(s, am, cmd, 2);
	if (s[am->x] != DIRECT_CHAR && !ft_isdigit(s[am->x]) && s[am->x] != 'r' &&
		s[am->x] != LABEL_CHAR)
		bef_error(s, am, cmd, 1);
	tmp->codage += (ft_isdigit(s[am->x]) || s[am->x] == ':' ? 0x20 : 0);
	tmp->codage += (s[am->x] == DIRECT_CHAR ? 0x10 : 0);
	tmp->arg2.tp = (s[am->x] == DIRECT_CHAR ? T_IND : T_DIR);
	tmp->arg2.tp = (s[am->x] == 'r' ? T_REG : tmp->arg2.tp);
	am->x += (s[am->x] == 'r' || s[am->x] == DIRECT_CHAR ? 1 : 0);
	crt_arg(s, am, &tmp->arg2, cmd);
	bef_error(s, am, cmd, 2);
	if (s[am->x] != 'r')
		bef_error(s, am, cmd, 1);
	am->x++;
	tmp->arg3.tp = T_REG;
	crt_arg(s, am, &tmp->arg3, cmd);
}
