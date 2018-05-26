/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 21:49:48 by vgladush          #+#    #+#             */
/*   Updated: 2018/05/26 13:53:43 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		fill_cmd_arg(t_command *cmd)
{
	cmd->codage = 0;
	cmd->next = 0;
	cmd->arg1.tp = 0;
	cmd->arg1.dn = 0;
	cmd->arg1.av = 0;
	cmd->arg1.lb = 0;
	cmd->arg1.x = 0;
	cmd->arg1.y = 0;
	cmd->arg2.tp = 0;
	cmd->arg2.dn = 0;
	cmd->arg2.av = 0;
	cmd->arg2.lb = 0;
	cmd->arg2.x = 0;
	cmd->arg2.y = 0;
	cmd->arg3.tp = 0;
	cmd->arg3.dn = 0;
	cmd->arg3.av = 0;
	cmd->arg3.lb = 0;
	cmd->arg3.x = 0;
	cmd->arg3.y = 0;
}

t_command		*find_lb_cmd(t_label *lb, char *s, t_asm *am, int cmd)
{
	t_command	*tmp;

	if (lb->cmd)
	{
		tmp = lb->cmd;
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_command *)malloc(sizeof(t_command))))
			errors_man(am, s, 10);
		tmp = tmp->next;
	}
	else
	{
		if (!(lb->cmd = (t_command *)malloc(sizeof(t_command))))
			errors_man(am, s, 10);
		tmp = lb->cmd;
	}
	tmp->bit = am->hd.prog_size;
	tmp->cmd = cmd;
	fill_cmd_arg(tmp);
	return (tmp);
}

static void		crt_arg2(char *s, t_asm *am, t_arg *ar, char cmd)
{
	int			i;
	int			j;
	char		*str;

	str = 0;
	j = 0;
	i = 0;
	if (ar->tp == T_REG || s[am->x] != LABEL_CHAR ||
		!ft_strchr(LABEL_CHARS, s[am->x + 1]))
		errors_man(am, s, 20 + cmd);
	i = ++am->x;
	ar->x = am->x;
	ar->y = am->y;
	while (s[i] && ft_strchr(LABEL_CHARS, s[i]))
		i++;
	if (!(str = ft_strnew(i - am->x)))
		errors_man(am, s, 10);
	while (am->x < i)
		str[j++] = s[am->x++];
	ar->lb = str;
}

void			crt_arg(char *s, t_asm *am, t_arg *ar, char cmd)
{
	int			i;

	if (ft_isdigit(s[am->x]))
	{
		ar->x = am->x;
		ar->y = am->y;
		i = ft_atoi(s + am->x);
		while (ft_isdigit(s[am->x]))
			am->x++;
		if (ar->tp == T_REG && ((short)i > REG_NUMBER || (short)i < 1))
			errors_man(am, s, 12);
		ar->av = i;
		ar->dn = 1;
	}
	else
		crt_arg2(s, am, ar, cmd);
	while (s[am->x] == ' ' || s[am->x] == '\t')
		am->x++;
}
