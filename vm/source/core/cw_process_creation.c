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
	t_processes *new_object;

	i = 0;
	if (!(new_object = (t_processes *)malloc(sizeof(t_processes))))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
	while (i < CHAMP_MAX_SIZE + 1)
	{
		new_object->code[i] = champ->code[i];
		i++;
	}
	new_object->color = color;
	new_object->process_PC = process_pc;
	new_object->carry = 0;
	ft_bzero(new_object->registers, 16);
	new_object->champ_size = champ->head.prog_size;
	new_object->next = NULL;
	return (new_object);
}

void		cw_init_processes(t_champ *champ, t_processes **proc_p)
{
	int			color;
	int			process_pc;
	int			map_distance;
	t_processes *tmp;

	color = 1;
	map_distance = MEM_SIZE / g_cw->pd.champs_count;
	process_pc = 0;
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
		color++;
		process_pc += map_distance;
		champ = champ->next;
	}
}
