/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 17:33:04 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/25 17:33:05 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	initial(char *argv_name, t_asm *am)
{
	int		fd;
	char	*file_name;
	char	*test;

	// ft_printf("argv -> %s\n", argv_name);  write a file to a specific directory;
	// https://stackoverflow.com/questions/22949500/create-file-inside-a-directory-c;

	file_name = generate_file_name(argv_name);
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	test = ft_to_binary(am->hd.prog_size);
	am->hd.prog_size = bstr_to_dec(test);
	free(test);
	test = ft_to_binary(15369203);
	am->hd.magic = bstr_to_dec(test);
	free(test);
	ft_printf("%s\n", "Writing output program to ");
	write(fd, am, sizeof(am->hd.magic) + sizeof(am->hd.prog_name)
			+ sizeof(am->hd.prog_size) + sizeof(am->hd.comment));
	command_write(am->lb, fd);
	close(fd);
	free(file_name);
}

int		check_not_1_9_12_15(int codage)
{
	if (codage == 1)
		return (0);
	else if (codage == 9)
		return (0);
	else if (codage == 12)
		return (0);
	else if (codage == 15)
		return (0);
	return (1);
}

void	print_arg_according_to_type(t_arg	*arg, int fd)
{
	char c;
	short tmp_1;
	int tmp_2;
	char *buf;

	if (arg)
	{
		if (arg->tp == 1)
		{
			ft_printf("correct of type 1-> %c\n", *(char *)arg->av);
			c = *(char *)arg->av;
			ft_printf("sizeof char-> %d\n", sizeof(c));
			write(fd, &c, sizeof(c));
		}
		else if (arg->tp == 2)
		{
			ft_printf("correct of type 2-> %d\n", *(short *)arg->av);
			buf = ft_to_binary(*(short int *)arg->av);
			tmp_1 = bstr_to_dec(buf);
			ft_printf("sizeof short-> %d\n", sizeof(tmp_1));
			ft_printf("after transformation -> %d\n", tmp_1);
			free(buf);
			write(fd, &tmp_1, sizeof(tmp_1));
		}
		else if (arg->tp == 4)
		{
			ft_printf("correct of type 4-> %d\n", *(int *)arg->av);
			buf = ft_to_binary(*(int *)arg->av);
			tmp_2 = bstr_to_dec(buf);
			ft_printf("sizeof int-> %d\n", sizeof(tmp_2));

			ft_printf("after transformation -> %d\n", tmp_2);
			free(buf);
			write(fd, &tmp_2, sizeof(tmp_2));
		}
	}
}

void	command_write(t_label	*label, int fd)
{
	t_command	*command;

	while (label)
	{
		ft_printf("-----------------------------------------------------------------------------------------\n");

		ft_printf("label -> %s\n", label->name);
		
		ft_printf("-----------------------------------------------------------------------------------------\n");

		command = label->cmd;

		while (command)
		{

			ft_printf("cmd -> %d\n", command->cmd);
			write(fd, &command->cmd, sizeof(command->cmd));

			(check_not_1_9_12_15(command->codage)) ? ft_printf("codage -> %d\n", command->codage) : ft_printf("will not write codage -> %d\n", command->codage);
			(check_not_1_9_12_15(command->codage)) ? write(fd, &command->codage, sizeof(command->codage)) : 0;			

			ft_printf("type of cmd 1 -> %d\n", command->arg1.tp);
			ft_printf("type of cmd 2 -> %d\n", command->arg2.tp);
			ft_printf("type of cmd 3 -> %d\n", command->arg3.tp);

			print_arg_according_to_type(&command->arg1, fd);
			print_arg_according_to_type(&command->arg2, fd);
			print_arg_according_to_type(&command->arg3, fd);

			ft_printf("\n");

			command = command->next;
		}
			ft_printf("\n");
		label = label->next;
	}
}