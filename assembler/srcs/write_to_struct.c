/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 17:33:04 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/25 20:28:34 by vgladush         ###   ########.fr       */
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

	if (!(file_name = generate_file_name(argv_name)))
		errors_man(am, 0, 10);
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	test = ft_to_binary(am->hd.prog_size);
	am->hd.prog_size = bstr_to_dec(test);
	free(test);
	test = ft_to_binary(15369203);
	am->hd.magic = bstr_to_dec(test);
	free(test);
	ft_printf("Writing output program to %s\n", file_name);
	write(1, &am->hd, sizeof(am->hd));
	write(fd, &am->hd, sizeof(am->hd));
	close(fd);
	free(file_name);
}

// void	command_write()
// {
	
// }
