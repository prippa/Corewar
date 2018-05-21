/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 23:33:49 by vgladush          #+#    #+#             */
/*   Updated: 2018/05/21 14:42:20 by vgladush         ###   ########.fr       */
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
	lb->bit = 0;
	lb->cmd = 0;
	return (lb);
}

static t_label	*crt_label(char *s, t_asm *am, int i, int *j)
{
	t_label		*lb;

	lb = am->lb;
	while (lb->next)
		lb = lb->next;
	if (!(lb = fill_struct(lb, am->x - i)))
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
	if (*j == -1)
		errors_man(am, s, 10);
	am->x = i;
	return (lb);
}

static void		new_label(char *s, int i, t_asm *am, int *j)
{
	t_label		*lb;

	lb = am->lb;
	if (!(lb->name = ft_strnew(am->x - i)))
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
	am->x = i;
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
	else if(!(lab = crt_label(s, am, i, &j)))
			return ;
	if (j)
		write_cod(s, am, j, lab);
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
