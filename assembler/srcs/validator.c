/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 23:33:49 by vgladush          #+#    #+#             */
/*   Updated: 2018/04/23 19:14:43 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
	free(cmd);
	return (0);
}

static int		check_cmd(char *s, int j, int i)
{
	int		l;
	char	*cmd;

	l = 0;
	if (!(cmd = ft_strnew(j - i + 1)))
		return (-1);
	while (i < j)
		cmd[l++] = s[i++];
	l = 0;
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
	else if (!(l = ch_cmd_sec(cmd)))
		return (0);
	free(cmd);
	return (l);
}

static t_label	*crt_label(char *s, t_asm *am, int i, int *j)
{
	t_label		*lb;

	lb = am->lb;
	while (lb->next)
		lb = lb->next;
	if (!(lb->next = (t_label *)malloc(sizeof(t_label))))
		errors_man(am, s, 10);;
	lb = lb->next;
	lb->next = 0;
	if (!(lb->name = ft_strnew(am->x - i + 1)))
		errors_man(am, s, 10);
	while (i < am->x)
		lb->name[j[0]++] = s[i++];
	i++;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (!s[i] || s[i] == ';' || s[i] == COMMENT_CHAR)
		return (0);
	am->x = i + 1;
	while (ft_strchr(LABEL_CHARS, s[i]))
		i++;
	if (!(*j = check_cmd(s, i, am->x - 1)))
		errors_man(am, s, 9);
	return (lb);
}

static void		new_label(char *s, int i, t_asm *am, int *j)
{
	t_label		*lb;

	lb = am->lb;
	if (!(lb->name = ft_strnew(am->x - i + 1)))
		errors_man(am, s, 10);
	while (i < am->x)
		lb->name[j[0]++] = s[i++];
	i++;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (!s[i] || s[i] == ';' || s[i] == COMMENT_CHAR)
	{
		*j = 0;
		return ;
	}
	am->x = i + 1;
	while (ft_strchr(LABEL_CHARS, s[i]))
		i++;
	if (!(*j = check_cmd(s, i, am->x - 1)))
		errors_man(am, s, 9);
	if (*j == -1)
		errors_man(am, s, 10);
}

void			write_cod(char *s, t_asm *am, int i)
{

}

static void		wriite_cmd(char *s, t_asm *am, int i, int j)
{
	t_label		*lab;

	lab = am->lb;
	if (!am->lb)
	{
		if (!(am->lb = (t_label *)malloc(sizeof(t_label))))
			errors_man(am, s, 10);;
		lab = am->lb;
		lab->next = 0;
		lab->bit = 0;
		lab->cmd = 0;
		lab->name = 0;
		if (!j)
			new_label(s, i, am, &j);
	}
	else if (j)
		while (lab->next)
			lab = lab->next;
	else
	{
		if(!(lab = crt_label(s, am, i, &j)))
			return ;
	}
	if (j)
		write_cod(s, am, j);
}

void			check_form(char *s, t_asm *am, int i, int j)
{
	if (!am->hd.prog_name[0] || !am->hd.comment[0])
		errors_man(am, s, 4);
	if (!ft_strchr(LABEL_CHARS, s[am->x]) && (++am->x))
		errors_man(am, s, 3);
	while (ft_strchr(LABEL_CHARS, s[am->x]))
		am->x++;
	j = 0;
	if (s[am->x] != ':' && !(j = check_cmd(s, am->x, i)))
	{
		while (s[am->x] && (s[am->x] == ' ' || s[am->x] == '\t'))
			am->x++;
		if (ft_strchr(LABEL_CHARS, s[am->x]) && (++am->x))
			errors_man(am, s, 9);
		else if (!s[am->x] || s[am->x] == COMMENT_CHAR || s[am->x] == ';')
		{
			am->x = ft_strlen(s) + 1;
			errors_man(am, s, 6);
		}
		++am->x;
		errors_man(am, s, 3);
	}
	wriite_cmd(s, am, i, j);
}
