/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:02:08 by vgladush          #+#    #+#             */
/*   Updated: 2018/05/25 16:06:32 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		search_lab(t_asm *am, t_label *lb, t_arg *arg, int bt)
{
	int			i;

	i = 0;
	while (lb)
	{
		if (!ft_strcmp(lb->name, (char *)arg->av))
		{
			free(arg->av);
			i = lb->bit - bt;
			arg->av = &i;
			arg->dn = 1;
			return ;
		}
		lb = lb->next;
	}
	ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] not found such a label \
\"%s\"\n", arg->y, arg->x, (char *)arg->av);
	all_clear(am, 0);
}

void			ch_to_coord(t_asm *am)
{
	t_label		*lab;
	t_command	*cm;

	lab = am->lb;
	while (lab)
	{
		cm = lab->cmd;
		while (cm)
		{
			if (cm->arg1.tp && !cm->arg1.dn)
				search_lab(am, am->lb, &cm->arg1, cm->bit);
			if (cm->arg2.tp && !cm->arg2.dn)
				search_lab(am, am->lb, &cm->arg2, cm->bit);
			if (cm->arg3.tp && !cm->arg3.dn)
				search_lab(am, am->lb, &cm->arg3, cm->bit);
			cm = cm->next;
		}
		lab = lab->next;
	}
}
