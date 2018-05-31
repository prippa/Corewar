/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_process_creation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 20:25:40 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/31 20:25:41 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_processes	*cw_constr(t_champ *champ, int color, int process_pc)
{
	int			i;
	t_processes *new;

	i = 0;
	if (!(new = (t_processes *)malloc(sizeof(t_processes))))
		return (NULL);
	while (i < CHAMP_MAX_SIZE + 1)
	{
		new->code[i] = champ->code[i];
		i++;
	}
	new->color = color;
	new->process_PC = process_pc;
	new->carry = 0;
	ft_bzero(new->registers, 16);
	new->champ_size = champ->head.prog_size;
	new->next = NULL;
	return (new);
}

void		cw_init_processes(t_champ *champ, t_processes **proc_p)
{
	int			color;
	int			process_pc;
	int			map_distance;
	t_processes *tmp;

	color = 4 - (4 - g_cw->pd.champs_count) ;
	map_distance = MEM_SIZE / g_cw->pd.champs_count;
	process_pc = MEM_SIZE - (MEM_SIZE / g_cw->pd.champs_count);
	if (g_cw->pd.champs_count == 3)
		process_pc -= 1;
	while (champ)
	{
		if (!*proc_p)
			*proc_p = cw_constr(champ, color, process_pc);
		else
		{
			tmp = *proc_p;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = cw_constr(champ, color, process_pc);
		}
		color--;
		process_pc -= map_distance;
		champ = champ->next;
	}
}
