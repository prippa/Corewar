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

#define WHAT_DIR(x) (x > 8 && x < 13) || x == 14 || x == 15
#define IS_CDG(x) x == 1 || x == 9 || x == 12 || x == 15
#define	T_IND_TRUE 2
#define T_DIR_GENERAL 7
// #define	T_DIR_TRUE_OPT_1 2
// #define	T_DIR_TRUE_OPT_2 4

static int	arg_check(char *bn, int *j, char *tp, int bt)
{
	if (bn[*j] == '1' && bn[*j + 1] == '1')
		*tp = T_IND_TRUE;
	else if (bn[*j] == '1' && bn[*j + 1] == '0') // set it correctly 2 or 4;
		*tp = bt; /// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	else if (bn[*j] == '0' && bn[*j + 1] == '1')
		*tp = T_REG; // o.k.
	else
		*tp = 0;
	*j += 2; // move the cursor for analysis why 2 ? -> according tothetype returns how many bytes to read;
	if (*tp == T_IND_TRUE)
		return (2);
	if (*tp == bt) // here;
	{
		ft_putstr("here\n");
		ft_printf("tp -> %d\n", *tp);
		ft_printf("bt -> %d\n", bt);
		return (bt);
	}
	if (*tp == T_REG) //o.k.
		return (1);
	return (0);
}

static void	tmp_arg(unsigned char *s, int rd,
					unsigned int *i, unsigned char *map)  // write to string for conversion;
{
	int				j;

	j = 0;
	while (rd-- > 0)
	{
		s[j] = map[*i];
		j++;
		*i = MEM_CORRECTION((*i + 1));
	}
}

static void	write_args(t_command *cmd, unsigned int *i, int bt,
			unsigned char *map)
{
	char			*bn;
	int				j;
	int				rd;
	unsigned char	res[5];

	ft_bzero(res, 5);
	j = 0;
	if (!(bn = ft_itoabase(cmd->codage, 2, 0)))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
	while (ft_strlen(bn) < 8)
		if (!(bn = ft_joinfree("0", bn, 2)))
			cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);

	// ft_printf("%s\n", bn);

	rd = arg_check(bn, &j, &cmd->arg1.tp, bt);
	tmp_arg(res, rd, i, map);
	cmd->arg1.av = cw_hex_to_dec(res, rd);

	ft_bzero(res, 5);
	rd = arg_check(bn, &j, &cmd->arg2.tp, bt);
	// ft_printf("bt->%d\n", &cmd->arg2.tp);
	tmp_arg(res, rd, i, map);
	cmd->arg2.av = cw_hex_to_dec(res, rd);

	ft_bzero(res, 5);
	rd = arg_check(bn, &j, &cmd->arg3.tp, bt);
	tmp_arg(res, rd, i, map);
	cmd->arg3.av = cw_hex_to_dec(res, rd);

	ft_str_free(&bn);
}

static int	check_true_cdg(unsigned char cmd, int cdg)
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

int			cw_get_command(t_command *cmd, unsigned int i,
			unsigned char *map)
{
	int				bt; // byte 
	unsigned char	res[5]; // max is 4 bytes;
	


	ft_bzero(res, 5); // +;
	if (map[i] > 16 || map[i] < 1) // check if we have a correct command;
	{
		// ft_putstr("rrrrrrrrrrrrrrrrrrrrrr -> 1\n");

		return (NOT_EXIST_CODE);
	}
	bt = 1; // byte as default = 1, reghas 1 byte;
	bt = (WHAT_DIR(map[i]) ? 2 : 4); // detect syze in bytes of the DIR;
	cmd->cmd = map[i]; // set the command value from the first position on the map;
	i = MEM_CORRECTION((i + 1)); // move the map pointer to the next byte;
	// ft_printf("in cmd i -> %d\n",g_cw->i);
	cmd->codage = ((IS_CDG(cmd->cmd)) ? 0 : map[i]); // set the command codage from the second position on the map;
	if (IS_CDG(cmd->cmd)) // if commands: 1, 9, 2, 15;
	{
		tmp_arg(res, bt, &i, map); // get the data from the map for conversion;
		cmd->arg1.av = cw_hex_to_dec(res, bt); // res - buf, bt == byte;
		cmd->arg1.tp = (cmd->cmd == 1) ? 4 : T_DIR;
		cmd->arg2.tp = 0;
		cmd->arg3.tp = 0;
		return (0);
	}
	i = MEM_CORRECTION((i + 1)); // go to other commands;
	if (check_true_cdg(cmd->cmd, cmd->codage)) // check if a specific cmd has the correct codage;
	{
				// ft_putstr("rrrrrrrrrrrrrrrrrrrrrr -> 2\n");
		return (NOT_CORRECT_CODAGE); // check if a specific cmd has the correct codage;
	}

	write_args(cmd, &i, bt, map);
	// ft_printf("in cmd i -> %d\n",g_cw->i);
	
	return (0);
}

int			cw_get_command_2(t_command *cmd, unsigned int i,
			unsigned char *map, int proc_current_command)
{
	int				bt; // byte 
	unsigned char	res[5]; // max is 4 bytes;
	


	ft_bzero(res, 5); // +;
	if (proc_current_command > 16 || proc_current_command < 1) // check if we have a correct command;
	{
		// ft_putstr("asdfasdfasdfasdfasdfasfasdfasdfasdf\n");
		return (NOT_EXIST_CODE);
	}
	bt = 1; // byte as default = 1, reghas 1 byte;
	bt = (WHAT_DIR(proc_current_command) ? 2 : 4); // detect syze in bytes of the DIR;
	cmd->cmd = proc_current_command; // set the command value from the first position on the map;
	i = MEM_CORRECTION((i + 1)); // move the map pointer to the next byte;
	// ft_printf("in cmd i -> %d\n",g_cw->i);
	cmd->codage = ((IS_CDG(cmd->cmd)) ? 0 : map[i]); // set the command codage from the second position on the map;
	if (IS_CDG(cmd->cmd)) // if commands: 1, 9, 2, 15;
	{
		tmp_arg(res, bt, &i, map); // get the data from the map for conversion;
		cmd->arg1.av = cw_hex_to_dec(res, bt); // res - buf, bt == byte;
		cmd->arg1.tp = (cmd->cmd == 1) ? 4 : T_DIR;
		cmd->arg2.tp = 0;
		cmd->arg3.tp = 0;
		return (0);
	}
	i = MEM_CORRECTION((i + 1)); // go to other commands;
	if (check_true_cdg(cmd->cmd, cmd->codage)) // check if a specific cmd has the correct codage;
	{
		// ft_putstr("****************************************a\n");
		return (NOT_CORRECT_CODAGE); // check if a specific cmd has the correct codage;
	}

	write_args(cmd, &i, bt, map);
	// ft_printf("in cmd i -> %d\n",g_cw->i);
	
	return (0);
}