/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 23:33:49 by vgladush          #+#    #+#             */
/*   Updated: 2018/05/23 19:58:41 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_label	*fill_struct(t_label *lb, int i)
{
	if (!(lb->next = (t_label *)malloc(sizeof(t_label))))
		return (0);
	lb = lb->next;
	if (!(lb->name = ft_strnew(i)))
		return (0);
	lb->next = 0;
	lb->bit = am->hd.prog_size;
	lb->cmd = 0;
	return (lb);
}

static t_label	*crt_label(char *s, t_asm *am, int i, int *j)
{
	t_label		*lb;
	int			l;

	l = 0;
	lb = am->lb;
	while (lb->next)
		lb = lb->next;
	if (!(lb = fill_struct(lb, i - am->x)))
		errors_man(am, s, 10);
	while (i > am->x)
		lb->name[l++] = s[am->x++];
	am->x++;
	while (s[am->x] == ' ' || s[am->x] == '\t')
		am->x++;
	if (!s[i] || s[i] == ';' || s[i] == COMMENT_CHAR)
		return (0);
	i = am->x;
	while (ft_strchr(LABEL_CHARS, s[i]))
		i++;
	if (!(*j = check_cmd(s, i, am->x, 0)))
		errors_man(am, s, 4);
	am->x = i;
	return (lb);
}

static void		new_label(char *s, int i, t_asm *am, int *j)
{
	t_label		*lb;
	int			l;

	l = 0;
	lb = am->lb;
	if (!(lb->name = ft_strnew(i - am->x)))
		errors_man(am, s, 10);
	while (i > am->x)
		lb->name[l++] = s[am->x++];
	am->x++;
	while (s[am->x] == ' ' || s[am->x] == '\t')
		am->x++;
	if (!s[am->x] || s[am->x] == ';' || s[am->x] == COMMENT_CHAR)
		return ;
	if (!ft_strchr(LABEL_CHARS, s[am->x]))
		errors_man(am, s, 9);
	i = am->x;
	while (ft_strchr(LABEL_CHARS, s[i]))
		i++;
	if (!(*j = check_cmd(s, i, am->x, 0)))
		errors_man(am, s, 4);
	am->x = i;
}

static void		wriite_cmd(char *s, t_asm *am, int i, int j)
{
	t_label		*lab;

	lab = am->lb;
	if (!am->lb)
	{
		if (!(am->lb = (t_label *)malloc(sizeof(t_label))))
			errors_man(am, s, 10);
		lab = am->lb;
		lab->next = 0;
		lab->bit = am->hd.prog_size;
		lab->cmd = 0;
		lab->name = 0;
		if (!j)
			new_label(s, i, am, &j);
	}
	else if (j)
		while (lab->next)
			lab = lab->next;
	else if(!(lab = crt_label(s, am, i, &j)))
		return ;
	if (j)
		write_cod(s, am, j, lab);
}

void			check_form(char *s, t_asm *am, int i, int j)
{
	if (!ft_strchr(LABEL_CHARS, s[am->x]))
		errors_man(am, s, 9);
	while (ft_strchr(LABEL_CHARS, s[i]))
		i++;
	if (s[i] != ':' && !(j = check_cmd(s, i, am->x, 0)))
		errors_man(am, s, 4);
	if (am->nmcm != 3)
		errors_man(am, s, 11);
	wriite_cmd(s, am, i, j);
}
