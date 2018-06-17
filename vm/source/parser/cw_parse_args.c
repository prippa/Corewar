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

static void	cw_set_champ_number_and_order(t_champ *champs)
{
	int		i;
	int		order;
	int		number;
	t_champ	*head;

	head = champs;
	order = g_cw->pd.champs_count;
	number = -1;
	i = 0;
	while (champs)
	{
		champs->champ_number = number;
		if (!g_cw->pd.flag_champ_number[i])
		{
			while (t_champ_check_double_champ_number(head, order))
				order--;
			champs->order = order;
		}
		champs = champs->next;
		number--;
		i++;
	}
}

static void	cw_valid_champ(char *file_name)
{
	int			fd;

	if (g_cw->pd.champs_count == MAX_PLAYERS)
		cw_exit("ERROR: Too many champions", MANY_CHAMPS);
	if (g_cw->pd.tmp != 0 &&
		t_champ_check_double_champ_number(g_cw->pd.champs, (int)g_cw->pd.tmp))
		cw_exit("ERROR: Double champ number", INV_N_FLAG);
	if ((fd = open(file_name, O_RDONLY)) == -1 || read(fd, NULL, 0) == -1)
		cw_perror_exit(file_name, OPEN_FILE);
	t_champ_add(&g_cw->pd.champs);
	g_cw->pd.champs->fd = fd;
	ft_strcpy(g_cw->pd.champs->file_name, file_name);
	if (g_cw->pd.tmp != 0)
		g_cw->pd.flag_champ_number[g_cw->pd.champs_count] = '1';
	g_cw->pd.champs_count++;
	g_cw->pd.champs->order = (int)g_cw->pd.tmp;
	g_cw->pd.tmp = 0;
}

static void	cw_valid_champ_number(char **argv, int *i)
{
	*i += 1;
	if (!argv[*i] || !ft_str_is_digit(argv[*i]))
		cw_exit("ERROR: Argument after -n flag is not number", INV_N_FLAG);
	g_cw->pd.tmp = ft_atoi_max(argv[*i]);
	if (g_cw->pd.tmp < 1 || g_cw->pd.tmp > MAX_PLAYERS)
		cw_exit("ERROR: Number after -n flag is not in valid case", INV_N_FLAG);
	*i += 1;
	if (!argv[*i])
		cw_exit("ERROR: No champion after -n flag", INV_N_FLAG);
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
		cw_exit("ERROR: No champions", NO_CHAMPS);
	t_champ_rev(&g_cw->pd.champs);
	cw_set_champ_number_and_order(g_cw->pd.champs);
}
