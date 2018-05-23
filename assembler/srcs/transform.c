/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 11:45:18 by vgladush          #+#    #+#             */
/*   Updated: 2018/05/23 21:03:25 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*tran_str2(char i)
{
	char		*s;

	s = 0;
	if (i == 9)
		s = ft_strdup("zjmp");
	if (i == 10)
		s = ft_strdup("ldi");
	else if (i == 11)
		s = ft_strdup("sti");
	else if (i == 12)
		s = ft_strdup("fork");
	else if (i == 13)
		s = ft_strdup("lld");
	else if (i == 14)
		s = ft_strdup("lldi");
	else if (i == 15)
		s = ft_strdup("lfork");
	else if (i == 16)
		s = ft_strdup("aff");
	return (s);
}

char			*tran_str(char i)
{
	char		*s;

	s = 0;
	if (i > 8)
		s = tran_str2(i);
	else if (i == 1)
		s = ft_strdup("live");
	else if (i == 2)
		s = ft_strdup("ld");
	else if (i == 3)
		s = ft_strdup("st");
	else if (i == 4)
		s = ft_strdup("add");
	else if (i == 5)
		s = ft_strdup("sub");
	else if (i == 6)
		s = ft_strdup("and");
	else if (i == 7)
		s = ft_strdup("or");
	else if (i == 8)
		s = ft_strdup("xor");
	return (s);
}

static int		ch_cmd_sec(char *cmd)
{
	if (!ft_strcmp(cmd, "or"))
		return (7);
	if (!ft_strcmp(cmd, "xor"))
		return (8);
	if (!ft_strcmp(cmd, "zjmp"))
		return (9);
	if (!ft_strcmp(cmd, "ldi"))
		return (10);
	if (!ft_strcmp(cmd, "sti"))
		return (11);
	if (!ft_strcmp(cmd, "fork"))
		return (12);
	if (!ft_strcmp(cmd, "lld"))
		return (13);
	if (!ft_strcmp(cmd, "lldi"))
		return (14);
	if (!ft_strcmp(cmd, "lfork"))
		return (15);
	if (!ft_strcmp(cmd, "aff"))
		return (16);
	return (0);
}

int			check_cmd(char *s, int j, int i, int l)
{
	char	cmd[6];

	ft_bzero(cmd, 6);
	if (j - i > 5)
		return (0);
	while (i < j)
		cmd[l++] = s[i++];
	if (!ft_strcmp(cmd, "live"))
		l = 1;
	else if (!ft_strcmp(cmd, "ld"))
		l = 2;
	else if (!ft_strcmp(cmd, "st"))
		l = 3;
	else if (!ft_strcmp(cmd, "add"))
		l = 4;
	else if (!ft_strcmp(cmd, "sub"))
		l = 5;
	else if (!ft_strcmp(cmd, "and"))
		l = 6;
	else
		return (ch_cmd_sec(cmd));
	return (l);
}
