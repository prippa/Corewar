/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:25:29 by prippa            #+#    #+#             */
/*   Updated: 2018/06/05 13:25:30 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	cw_valid_dump(char **argv, int *i)
{
	long long int tmp;

	*i += 1;
	if (!argv[*i] || !ft_str_is_digit(argv[*i]))
		cw_exit("ERROR: Argument after -dump flag is not number", INV_DUMP_FLAG);
	tmp = ft_atoi_max(argv[*i]);
	if (tmp < 0 || tmp > MAXINT)
		cw_exit("ERROR: Number after -dump flag \
is bigger than MAXINT or less then 0", INV_DUMP_FLAG);
	g_cw->pd.dump_stop = (unsigned int)tmp;
	g_cw->pd.flags[DUMP] = '1';
}

int			cw_parse_flags(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "-dump") && !g_cw->pd.flags[DUMP])
			cw_valid_dump(argv, &i);
		else if (!ft_strcmp(argv[i], "-visu") && !g_cw->pd.flags[VISU])
			g_cw->pd.flags[VISU] = '1';
		else
			return (i);
		i++;
	}
	return (i);
}
