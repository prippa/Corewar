/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_asm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:01:11 by vgladush          #+#    #+#             */
/*   Updated: 2018/06/09 23:35:41 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	free_cmd(t_command *cmd)
{
	if (cmd->next)
		free_cmd(cmd->next);
	if (cmd->arg1.tp && !cmd->arg1.dn)
		free(cmd->arg1.lb);
	free(cmd);
}

static void	free_lab(t_label *lb)
{
	if (lb->next)
		free_lab(lb->next);
	if (lb->name)
		free(lb->name);
	if (lb->cmd)
		free_cmd(lb->cmd);
	free(lb);
}

void		all_clear(t_asm *am, char *s)
{
	if (s)
		free(s);
	if (am->lb)
		free_lab(am->lb);
	close(am->fd);
}
