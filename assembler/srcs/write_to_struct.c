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
	close(fd);
	free(file_name);
}
