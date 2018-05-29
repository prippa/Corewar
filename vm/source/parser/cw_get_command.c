/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_get_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:22:34 by vgladush          #+#    #+#             */
/*   Updated: 2018/05/29 02:59:10 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

# define WHAT_DIR(x) (x > 8 && x < 13) || x == 14 || x == 15
# define IS_CDG(x) x == 1 || x == 9 || x == 12 || x == 15

static int			arg_check(char *bn, int *j, char *tp, int bt)
{
	if (bn[*j] == '1' && bn[*j + 1] == '1')
		*tp = T_IND;
	else if (bn[*j] == '1' && bn[*j + 1] == '0')
		*tp = T_DIR;
	else if (bn[*j] == '0' && bn[*j + 1] == '1')
		*tp = T_REG;
	else
		*tp = 0;
	*j += 2;
	if (*tp == T_IND)
		return (2);
	if (*tp == T_DIR)
		return (bt);
	if (*tp == T_REG)
		return (1);
	return (0);
}

static void			tmp_arg(unsigned char *s, int rd, int *i, char *code)
{
	int				j;

	j = 0;
	while (rd-- > 0)
		s[j++] = code[(*i)++];
}

static void			write_args(t_command *cmd, int *i, int bt,
					unsigned char code[CHAMP_MAX_SIZE + 1])
{
	char			*bn;
	int				j;
	int				rd;
	unsigned char	res[5];

	ft_bzero(res, 5);
	j = 0;
	if (!(bn = ft_itoabase(cmd->codage, 2, 0)))
		exit(ft_printf("malloc error")); // переписать
	while (ft_strlen(bn) < 8)
		bn = ft_joinfree("0", bn, 2);
	rd = arg_check(bn, &j, &cmd->arg1.tp, bt);
	tmp_arg(res, rd, i, code);
	cmd->arg1.av = cw_hex_to_dec(res, rd);
	ft_bzero(res, 5);
	rd = arg_check(bn, &j, &cmd->arg2.tp, bt);
	tmp_arg(res, rd, i, code);
	cmd->arg2.av = cw_hex_to_dec(res, rd);
	ft_bzero(res, 5);
	rd = arg_check(bn, &j, &cmd->arg3.tp, bt);
	tmp_arg(res, rd, i, code);
	cmd->arg3.av = cw_hex_to_dec(res, rd);
}

static int			check_true_cdg(unsigned char cmd, int cdg)
{
	if (cmd == LD || cmd == LLD)
		return ((cdg == 0x90 || cdg == 0xd0) ? 0 : 1);
	else if (cmd == ST)
		return ((cdg == 0x50 || cdg == 0x70) ? 0 : 1);
	else if (cmd == ADD || cmd == SUB)
		return (cdg == 0x54 ? 0 : 1);
	else if (cmd == AND || cmd == OR || cmd == XOR)
		return ((cdg == 0x54 || cdg == 0x64 || cdg == 0x74 || cdg == 0x94
			|| cdg == 0xd4 || cdg == 0xa4 || cdg == 0xb4 || cdg == 0xe4
			|| cdg == 0xf4) ? 0 : 1);
	else if (cmd == LDI || cmd == LLDI)
		return ((cdg == 0x54 || cdg == 0xa4 || cdg == 0x64 || cdg == 0x94
			|| cdg == 0xd4 || cdg == 0xe4) ? 0 : 1);
	else if (cmd == STI)
		return ((cdg == 0x54 || cdg == 0x58 || cdg == 0x64 || cdg == 0x68
			|| cdg == 0x74 || cdg == 0x78) ? 0 : 1);
	else if (cmd == AFF)
		return (cdg == 0x40 ? 0 : 1);
	return (0);
}

void				cw_get_command(t_command *cmd, int *i,
					unsigned char code[CHAMP_MAX_SIZE + 1])
{
	int				bt;
	unsigned char	res[5];

	ft_bzero(res, 5);
	if (code[*i] > 16 || code[*i] < 1)
		exit(ft_printf("%d не существующая команда", *i)); // переписать
	bt = (WHAT_DIR(code[*i]) ? 2 : 4);
	cmd->cmd = code[*i];
	*i += 1;
	cmd->codage = ((IS_CDG(cmd->cmd)) ? 0 : code[*i]);
	if (IS_CDG(cmd->cmd))
	{
		tmp_arg(res, bt, i, code);
		cmd->arg1.av = cw_hex_to_dec(res, bt);
		cmd->arg1.tp = T_DIR;
		cmd->arg2.tp = 0;
		cmd->arg3.tp = 0;
		return ;
	}
	*i += 1;
	if (check_true_cdg(cmd->cmd, cmd->codage))
		exit(ft_printf("не правильный кодейдж")); // переписать;
	write_args(cmd, i, bt, code);
}
