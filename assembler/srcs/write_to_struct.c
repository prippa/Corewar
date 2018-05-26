/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 17:33:04 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/26 19:34:22 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_to_binary2(unsigned short n)
{
	short		i;
	int			j;
	char		*reverse;
	char		res[5];

	j = 4;
	res[4] = 0;
	while (j--)
		res[j] = '0';
	j = 0;
	reverse = ft_itoabase(n, 16, 'a');
	i = ft_strlen(reverse);
	while (i-- > 0)
	{
		if (i == 0)
			res[j + 1] = reverse[i];
		else
		{
			res[++j] = reverse[i--];
			res[j++ - 1] = reverse[i];
		}
	}
	i = ft_basetoint(res, 16);
	free(reverse);
	return (i);
}

static int		ft_to_binary(unsigned int n)
{
	int			i;
	int			j;
	char		*reverse;
	char		res[9];

	j = 8;
	res[8] = 0;
	while (j--)
		res[j] = '0';
	j = 0;
	reverse = ft_itoabase(n, 16, 'a');
	i = ft_strlen(reverse);
	while (i-- > 0)
	{
		if (i == 0)
			res[j + 1] = reverse[i];
		else
		{
			res[++j] = reverse[i--];
			res[j++ - 1] = reverse[i];
		}
	}
	i = ft_basetoint(res, 16);
	free(reverse);
	return (i);
}

void			initial(char *argv_name, t_asm *am)
{
	int			fd;
	char		*file_name;

	file_name = generate_file_name(argv_name);
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	am->hd.magic = ft_to_binary(COREWAR_EXEC_MAGIC);
	am->hd.prog_size = ft_to_binary(am->hd.prog_size);
	ft_printf("Writing output program to %s\n", file_name);
	write(fd, &am->hd, sizeof(am->hd));
	command_write(am->lb, fd);
	close(fd);
	free(file_name);
}

void			print_arg_according_to_type(t_arg *arg, int fd)
{
	char		c;
	short		tmp_1;
	int			tmp_2;

	if (arg->tp == 1)
	{
		c = arg->av;
		write(fd, &c, sizeof(c));
	}
	else if (arg->tp == 2)
	{
		tmp_1 = ft_to_binary2(arg->av);
		write(fd, &tmp_1, sizeof(tmp_1));
	}
	else if (arg->tp == 4)
	{
		tmp_2 = ft_to_binary(arg->av);
		write(fd, &tmp_2, sizeof(tmp_2));
	}
}

void			command_write(t_label *label, int fd)
{
	t_command	*command;

	while (label)
	{
		command = label->cmd;
		while (command)
		{
			write(fd, &command->cmd, sizeof(command->cmd));
			if (command->codage)
				write(fd, &command->codage, 1);
			print_arg_according_to_type(&command->arg1, fd);
			print_arg_according_to_type(&command->arg2, fd);
			print_arg_according_to_type(&command->arg3, fd);
			command = command->next;
		}
		label = label->next;
	}
}
