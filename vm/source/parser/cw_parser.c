/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:55:45 by prippa            #+#    #+#             */
/*   Updated: 2018/05/26 13:55:50 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	cw_get_code_data(t_champ *champ)
{
	int				catch_error;
	unsigned int	i;
	
	i = 0;
	while (i < champ->head.prog_size)
	{
		t_command_add(&champ->cmd);
		catch_error = cw_get_command(champ->cmd, &i, champ->code);
		if (catch_error)
			cw_exit(champ->file_name, catch_error);
	}
	t_command_rev(&champ->cmd);
}

static void	cw_parse_file(t_champ *champ)
{
	cw_check_magic(champ);
	cw_get_prog_name(champ);
	cw_get_prog_size(champ);
	cw_get_comment(champ);
	cw_get_prog_code(champ);
	cw_get_code_data(champ);

	// TEST HEAD
	ft_printf("magic = (%u) | prog name = (%s) | prog size = (%u) | comment = (%s)\n",
	champ->head.magic, champ->head.prog_name, champ->head.prog_size, champ->head.comment);
	// TEST END
	// TEST CODE
	t_command *tmp;

	tmp = champ->cmd;
	ft_printf("first command  = (%d) | cdg = (%d) | tp arg1 = (%d) | val arg1 = (%d) | \
tp arg2 = (%d) | val arg2 = (%d) | tp arg3 = (%d) | val arg3 = (%d)\n",
	tmp->cmd, tmp->codage, tmp->arg1.tp, tmp->arg1.av,
	tmp->arg2.tp, tmp->arg2.av, tmp->arg3.tp, tmp->arg3.av);
	while (tmp->next)
		tmp = tmp->next;
	ft_printf("last command = (%d) | cdg = (%d) | tp arg1 = (%d) | val \
arg1 = (%d) | tp arg2 = (%d) | val arg2 = (%d) | tp arg3 = (%d) | val arg3 = (%d)\n",
	tmp->cmd, tmp->codage, tmp->arg1.tp, tmp->arg1.av,
	tmp->arg2.tp, tmp->arg2.av, tmp->arg3.tp, tmp->arg3.av);
	// TEST END
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
