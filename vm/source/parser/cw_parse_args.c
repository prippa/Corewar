/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:55:27 by prippa            #+#    #+#             */
/*   Updated: 2018/06/05 13:25:23 by prippa           ###   ########.fr       */
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
	g_cw->pd.champs->champ_number = (int)g_cw->pd.tmp;
	if (g_cw->pd.tmp == MININT)
		g_cw->pd.tmp = MAXINT;
	else
		g_cw->pd.tmp--;
}

static void	cw_valid_champ_number(char **argv, int *i)
{
	*i += 1;
	if (!argv[*i] || !ft_str_is_digit(argv[*i]))
		cw_exit("Argument after -n flag is not number", INV_N_FLAG);
	g_cw->pd.tmp = ft_atoi_max(argv[*i]);
	if (g_cw->pd.tmp < MININT || g_cw->pd.tmp > MAXINT)
		cw_exit("Number after -n flag is bigger than int", INV_N_FLAG);
	*i += 1;
	if (!argv[*i])
		cw_exit("No champion after -n flag", INV_N_FLAG);
	cw_valid_champ(argv[*i]);
}

static void	cw_parse_arg(char **argv, int *i)
{
	if (!ft_strcmp(argv[*i], "-n"))
		cw_valid_champ_number(argv, i);
	else
		cw_valid_champ(argv[*i]);
}

void		cw_parse_args(int argc, char **argv)
{
	int i;

	if (argc < 2)
		cw_exit(CW_USAGE, USAGE);
	i = cw_parse_flags(argv);
	while (argv[i])
	{
		cw_parse_arg(argv, &i);
		i++;
	}
	if (!g_cw->pd.champs)
		cw_exit("No champions", NO_CHAMPS);
	t_champ_rev(&g_cw->pd.champs);
}
