/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:55:45 by prippa            #+#    #+#             */
/*   Updated: 2018/05/29 02:20:35 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	cw_parse_file(t_champ *champ)
{
	cw_check_magic(champ);
	cw_get_prog_name(champ);
	cw_get_prog_size(champ);
	cw_get_comment(champ);
	cw_get_prog_code(champ);
	cw_get_code_data(champ);

	// TEST
	ft_printf("last command : cmd = (%d) | cdg = (%d) | tp arg1 = (%d) | val \
arg1 = (%d) | tp arg2 = (%d) | val arg2 = (%d) | tp arg3 = (%d) | val arg3 = (%d)\n",
champ->cmd->cmd, champ->cmd->codage, champ->cmd->arg1.tp, champ->cmd->arg1.av,
champ->cmd->arg2.tp, champ->cmd->arg2.av, champ->cmd->arg3.tp, champ->cmd->arg3.av);

	while (champ->cmd->next)
		champ->cmd = champ->cmd->next;
	ft_printf("first command : cmd = (%d) | cdg = (%d) | tp arg1 = (%d) | val arg1 = (%d) |\
tp arg2 = (%d) | val arg2 = (%d) | tp arg3 = (%d) | val arg3 = (%d)\n",
champ->cmd->cmd, champ->cmd->codage, champ->cmd->arg1.tp, champ->cmd->arg1.av,
champ->cmd->arg2.tp, champ->cmd->arg2.av, champ->cmd->arg3.tp, champ->cmd->arg3.av);

	//TEST END

	ft_printf("magic = (%u) | prog name = (%s) | prog size = (%u) | comment = (%s)\n",
	champ->head.magic, champ->head.prog_name, champ->head.prog_size, champ->head.comment);
}

void		cw_parser(void)
{
	t_champ *champs;

	champs = g_cw->pd.champs;
	while (champs)
	{
		cw_parse_file(champs);
		champs = champs->next;
	}
}
