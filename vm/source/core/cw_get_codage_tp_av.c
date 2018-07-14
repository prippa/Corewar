#include "corewar.h"

static int	cw_what_tp(char *bn, int j, char label)
{
	if (bn[j] == '1' && bn[j + 1] == '1')
		return (IND);
	else if (bn[j] == '1' && bn[j + 1] == '0')
		return (label);
	else if (bn[j] == '0' && bn[j + 1] == '1')
		return (REG);
	else
		return (0);
}

void		cw_set_arg_tp_with_codage(t_command *cmd, char label, char comb)
{
	char	*bn;
	int		j;

	j = 0;
	if (!(bn = ft_itoabase(cmd->codage, 2, 0)))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
	while (ft_strlen(bn) < 8)
		if (!(bn = ft_joinfree("0", bn, 2)))
			cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
	cmd->arg1.tp = cw_what_tp(bn, j, label);
	if (comb >= DOUBLE_COMB)
	{
		j += 2;
		cmd->arg2.tp = cw_what_tp(bn, j, label);
	}
	if (comb == TRIPLE_COMB)
	{
		j += 2;
		cmd->arg3.tp = cw_what_tp(bn, j, label);
	}
	free(bn);
}

void		cw_set_arg_av(t_command *cmd, int pc, char comb)
{
	pc = MEM_X(pc);
	cmd->arg1.av = cw_get_dec_from_the_point(pc, cmd->arg1.tp);
	if (comb >= DOUBLE_COMB)
	{
		pc = MEM_X((pc + cmd->arg1.tp));
		cmd->arg2.av = cw_get_dec_from_the_point(pc, cmd->arg2.tp);
	}
	if (comb == TRIPLE_COMB)
	{
		pc = MEM_X((pc + cmd->arg2.tp));
		cmd->arg3.av = cw_get_dec_from_the_point(pc, cmd->arg3.tp);
	}
}
