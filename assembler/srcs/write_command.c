/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 11:39:41 by vgladush          #+#    #+#             */
/*   Updated: 2018/05/22 19:01:05 by vgladush         ###   ########.fr       */
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

void			t_check(char *s, t_asm *am, t_label *lb)
{
	
}

t_label			find_label(t_label *lb)
{
	t_command	*tmp;

	if (lb->cmd)
	{
		tmp = lb->cmd;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_command *)malloc(sizeof(t_command));
		tmp = tmp->next;
	}
	else
	{
		lb->cmd = (t_command *)malloc(sizeof(t_command));
		tmp = lb->cmd;
	}
	tmp->next = 0;
	return (tmp);
}

void			write_cod(char *s, t_asm *am, char cmd, t_label *lb)
{
	t_label 	*tmp;

	while (s[am->x] == ' ' || s[am->x] == '\t')
		am->x++;
	if (cmd != 1 && cmd != 9 && cmd != 12 && cmd != 15)
		write_cod2(s, am, cmd, lb);
	else
	{
		if ((s[am->x] == ';' || s[am->x] == '#' || !s[am->x]) && (am->x = ft_strlen(s)))
			errors_man(am, s, 5); // конец строки не достаточно аргументов
		if (s[am->x] != '%')
			errors_man(am, s, 1, tran_str(cmd)); //// не правильный аргумент
		am->x++;
		tmp = find_label(lb);

		if (s[am->x] == ':')

		else


		while (s[am->x] == ' ' || s[am->x] == '\t')
			am->x++;
		if ()
	}
}
