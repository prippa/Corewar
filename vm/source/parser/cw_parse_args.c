/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:55:27 by prippa            #+#    #+#             */
/*   Updated: 2018/05/26 13:55:28 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	cw_valid_champ(char *file_name)
{
	int			fd;

	if (g_cw->pd.champs_count == MAX_PLAYERS)
		cw_exit("Too many champions", MANY_CHAMPS);
	if ((fd = open(file_name, O_RDONLY)) == -1 || read(fd, NULL, 0) == -1)
		cw_perror_exit(file_name, OPEN_FILE);
	t_champ_add(&g_cw->pd.champs);
	g_cw->pd.champs->fd = fd;
	ft_strcpy(g_cw->pd.champs->file_name, file_name);
	g_cw->pd.champs_count++;
}

static void	cw_parse_arg(char *arg)
{
	if (ft_strstr(arg, ".cor"))
		cw_valid_champ(arg);
	else
		cw_exit(CW_USAGE, INVALID_INPUT);
}

void		cw_parse_args(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc < 2)
		cw_exit(CW_USAGE, INVALID_INPUT);
	while (argv[i])
	{
		cw_parse_arg(argv[i]);
		i++;
	}
	if (!g_cw->pd.champs)
		cw_exit(CW_USAGE, INVALID_INPUT);
}
