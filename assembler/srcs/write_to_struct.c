/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 17:33:04 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/26 13:18:26 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	initial(char *argv_name, t_asm *am)
{
	int		fd;
	char	*file_name;
	char	*test;

	file_name = generate_file_name(argv_name);
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	test = ft_to_binary(am->hd.prog_size);
	am->hd.prog_size = bstr_to_dec(test, &test);
	test = ft_to_binary(COREWAR_EXEC_MAGIC);
	am->hd.magic = bstr_to_dec(test, &test);
	ft_printf("Writing output program to %s\n", file_name);
	write(fd, &am->hd, sizeof(am->hd));
	command_write(am->lb, fd);
	close(fd);
	free(file_name);
}

void	print_arg_according_to_type(t_arg *arg, int fd)
{
	char	c;
	short	tmp_1;
	int		tmp_2;
	char	*buf;

	if (arg->tp == 1)
	{
		c = arg->av;
		write(fd, &c, sizeof(c));
	}
	else if (arg->tp == 2)
	{
		tmp_1 = arg->av;
		buf = ft_to_binary(tmp_1);
		tmp_1 = bstr_to_dec(buf, &buf);
		write(fd, &tmp_1, sizeof(tmp_1));
	}
	else if (arg->tp == 4)
	{
		tmp_2 = arg->av;
		buf = ft_to_binary(tmp_2);
		tmp_2 = bstr_to_dec(buf, &buf);
		write(fd, &tmp_2, sizeof(tmp_2));
	}
}

void	command_write(t_label *label, int fd)
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
