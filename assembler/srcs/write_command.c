/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 11:39:41 by vgladush          #+#    #+#             */
/*   Updated: 2018/05/17 16:50:44 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		write_cod5(char *s, t_asm *am, char *cmd, t_label *lb)
{
	if (i != 6 && i != 7 && i != 8)
		write_cod6(s, am, i, lb);
	else
	{

	}
}

static void		write_cod4(char *s, t_asm *am, char *cmd, t_label *lb)
{
	if (i != 4 && i != 5)
		write_cod5(s, am, i, lb);
	else
	{

	}
}

static void		write_cod3(char *s, t_asm *am, char *cmd, t_label *lb)
{
	if (i != 3)
		write_cod4(s, am, i, lb);
	else
	{

	}
}

static void		write_cod2(char *s, t_asm *am, char *cmd, t_label *lb)
{
	if (i != 2 && i != 13)
		write_cod3(s, am, i, lb);
	else
	{

	}
}

void			write_cod(char *s, t_asm *am, char *cmd, t_label *lb)
{
	while (s[am->x] == ' ' || s[am->x] == '\t')
		am->x++;
	if (i != 1 && i != 9 && i != 12 && i != 15)
		write_cod2(s, am, i, lb);
	else
	{
		if (s[am->x] == ':' || (s[am->x] > 47 && s[am->x] < 58) || s[am->x] == 'r')
			errors_mans(am, s, 1, tran_str(i));
		if ((s[am->x] == ';' || s[am->x] == '#' || !s[am->x]) && (am->x = ft_strlen(s)))
			errors_man(am, s, 5);
		if (ft_strchr(LABEL_CHARS, s[am->x]))
			errors_man(am, s, 9);
		if (s[am->x] != '%' || s[am->x + 1] < 47 || s[am->x + 1] > 58)
			errors_man(am, s, 3);
		am->x++;
		i = ft_atoi(s + am->x);
		while (s[am->x] > 47 && s[am->x] < 58)
			am->x++;
		while (s[am->x] == ' ' || s[am->x] == '\t')
			am->x++;
		if ()
	}
}
