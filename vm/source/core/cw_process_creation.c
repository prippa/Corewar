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

t_processes	*cw_constr(unsigned char *code, int color, int process_pc)
{
	int			i;
	t_processes *new;

	i = 0;
	if (!(new = (t_processes *)malloc(sizeof(t_processes))))
		return (NULL);
	while (i < CHAMP_MAX_SIZE + 1)
	{
		new->code[i] = code[i];
		i++;
	}
	new->color = color;
	new->process_PC = process_pc;
	new->carry = 0;
	ft_bzero(new->registers, 16);
	new->next = NULL;
	return (new);
}

void	cw_init_processes(t_champ *champ_pointer, t_processes **proc_p)
{
	int			color;
	int			process_pc;
	int			map_distance;
	t_processes *tmp;

	color = 4;
	map_distance = MEM_SIZE / g_cw->pd.champs_count;
	process_PC = MEM_SIZE - (MEM_SIZE / g_cw->pd.champs_count);
	if (g_cw->pd.champs_count == 3)
		process_pc -= 1;
	while (champ_pointer)
	{
		if (!*proc_p)
			*proc_p = cw_constr(champ_pointer->code, color, process_pc);
		else
		{
			tmp = *proc_p;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = cw_constr(champ_pointer->code, color, process_pc);
		}
		color--;
		process_pc -= map_distance;
		champ_pointer = champ_pointer->next;
	}
}
