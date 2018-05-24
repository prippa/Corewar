/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 21:49:48 by vgladush          #+#    #+#             */
/*   Updated: 2018/05/24 18:41:50 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_command		*find_lb_cmd(t_label *lb, int i)
{
	t_command	*tmp;

	if (lb->cmd)
	{
		tmp = lb->cmd;
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_command *)malloc(sizeof(t_command))))
			return (0);
		tmp = tmp->next;
	}
	else
	{
		if (!(lb->cmd = (t_command *)malloc(sizeof(t_command))))
			return (0);
		tmp = lb->cmd;
	}
	tmp->bit = i;
	tmp->next = 0;
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
	ar->dn = 0;
	ar->av = str;
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
		ar->av = &i;
		ar->dn = 1;
	}
	else
		crt_arg2(s, am, ar, cmd);
	while (s[am->x] == ' ' || s[am->x] == '\t')
		am->x++;
}
