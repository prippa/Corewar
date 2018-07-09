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

static void	cw_set_arg_tp_with_codage(t_command *cmd, char label)
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
	j += 2;
	cmd->arg2.tp = cw_what_tp(bn, j, label);
	j += 2;
	cmd->arg3.tp = cw_what_tp(bn, j, label);
}

void		cw_set_arg_av(t_command *cmd, int pc)
{
	pc = MEM_X(pc);
	cmd->arg1.av = cw_get_dec_from_the_point(pc, cmd->arg1.tp);
	pc = MEM_X((pc + cmd->arg1.tp));
	cmd->arg2.av = cw_get_dec_from_the_point(pc, cmd->arg2.tp);
	pc = MEM_X((pc + cmd->arg2.tp));
	cmd->arg3.av = cw_get_dec_from_the_point(pc, cmd->arg3.tp);
}

void		cw_get_codage_and_arg_tp(t_command *cmd, t_processes *proc)
{
	cmd->codage = g_cw.map[MEM_X((proc->pc + 1))];
	cw_set_arg_tp_with_codage(cmd, g_cw.op[proc->cmd - 1].label);
}
