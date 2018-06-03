#include "corewar.h"

static void	cw_valid_dump(char **argv, int *i)
{
	long long int tmp;

	*i += 1;
	if (!argv[*i] || !ft_str_is_digit(argv[*i]))
		cw_exit("Argument after -dump flag is not number", INV_DUMP_FLAG);
	tmp = ft_atoi_max(argv[*i]);
	if (tmp < 0 || tmp > MAXINT)
		cw_exit("Number after -dump flag \
is bigger than MAXINT or less then 0", INV_DUMP_FLAG);
	g_cw->pd.nbr_cycles = (int)tmp;
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
