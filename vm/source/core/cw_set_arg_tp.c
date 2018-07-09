#include "corewar.h"

static void	cw_more_comb_tp_3(t_command *cmd, char lable)
{
	if (cmd->codage == RRD)
	{
		cmd->arg1.tp = REG;
		cmd->arg2.tp = REG;
		cmd->arg3.tp = lable;
	}
	else if (cmd->codage == RI)
	{
		cmd->arg1.tp = REG;
		cmd->arg2.tp = IDX;
	}
}

static void	cw_more_comb_tp_2(t_command *cmd, char lable)
{
	if (cmd->codage == RIR)
	{
		cmd->arg1.tp = REG;
		cmd->arg2.tp = IDX;
		cmd->arg3.tp = REG;
	}
	else if (cmd->codage == RDD)
	{
		cmd->arg1.tp = REG;
		cmd->arg2.tp = lable;
		cmd->arg3.tp = lable;
	}
	else if (cmd->codage == RID)
	{
		cmd->arg1.tp = REG;
		cmd->arg2.tp = IDX;
		cmd->arg3.tp = lable;
	}
	else if (cmd->codage == RR)
	{
		cmd->arg1.tp = REG;
		cmd->arg2.tp = REG;
	}
	else
		cw_more_comb_tp_3(cmd, lable);
}

static void	cw_more_comb_tp_1(t_command *cmd, char lable)
{
	if (cmd->codage == DDR)
	{
		cmd->arg1.tp = lable;
		cmd->arg2.tp = lable;
		cmd->arg3.tp = REG;
	}
	else if (cmd->codage == IRR)
	{
		cmd->arg1.tp = IDX;
		cmd->arg2.tp = REG;
		cmd->arg3.tp = REG;
	}
	else if (cmd->codage == IDR)
	{
		cmd->arg1.tp = IDX;
		cmd->arg2.tp = lable;
		cmd->arg3.tp = REG;
	}
	else if (cmd->codage == IR)
	{
		cmd->arg1.tp = IDX;
		cmd->arg2.tp = REG;
	}
	else
		cw_more_comb_tp_2(cmd, lable);
}

void		cw_set_arg_tp(t_command *cmd, char lable)
{
	if (cmd->codage == RRR)
	{
		cmd->arg1.tp = REG;
		cmd->arg2.tp = REG;
		cmd->arg3.tp = REG;
	}
	else if (cmd->codage == RDR)
	{
		cmd->arg1.tp = REG;
		cmd->arg2.tp = lable;
		cmd->arg3.tp = REG;
	}
	else if (cmd->codage == DRR)
	{
		cmd->arg1.tp = lable;
		cmd->arg2.tp = REG;
		cmd->arg3.tp = REG;
	}
	else if (cmd->codage == DR)
	{
		cmd->arg1.tp = lable;
		cmd->arg2.tp = REG;
	}
	else
		cw_more_comb_tp_1(cmd, lable);
}
