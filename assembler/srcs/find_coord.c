/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:02:08 by vgladush          #+#    #+#             */
/*   Updated: 2018/05/26 23:36:44 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		search_lab(t_asm *am, t_label *lb, t_arg *arg, int bt)
{
	int			i;

	i = 0;
	while (lb)
	{
		if (lb->name && !ft_strcmp(lb->name, arg->lb))
		{
			free(arg->lb);
			arg->lb = 0;
			i = lb->bit - bt;
			arg->av = i;
			arg->dn = 1;
			return ;
		}
		lb = lb->next;
	}
	ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] not found such a label \
\"%s\"\n", arg->y, arg->x, arg->lb);
	all_clear(am, 0);
}

void			ch_to_coord(t_asm *am)
{
	t_label		*lab;
	t_command	*cm;
	int			i;

	i = 0;
	lab = am->lb;
	while (lab)
	{
		cm = lab->cmd;
		while (cm)
		{
			if (cm->arg1.tp && !cm->arg1.dn)
				search_lab(am, am->lb, &cm->arg1, cm->bit + i);
			if (cm->arg2.tp && !cm->arg2.dn)
				search_lab(am, am->lb, &cm->arg2, cm->bit + i);
			if (cm->arg3.tp && !cm->arg3.dn)
				search_lab(am, am->lb, &cm->arg3, cm->bit + i);
			cm = cm->next;
		}
		lab = lab->next;
	}
}
