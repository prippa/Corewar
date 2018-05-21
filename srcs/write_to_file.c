/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:50:31 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/21 14:50:33 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_printf.h"
#include <fcntl.h>

typedef struct s_toto
{
	char *str;
}				t_toto;

int		ft_string_size(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	return (i);
}

void	create_name_string(char *file_name_to_open, char *data_to_be_written)
{
	int len; 	// len till '.';
	int fd; 	// file descriptor;
	char *tmp; 	// buf;
	char *res; 	// string after join;

	len = ft_string_size(file_name_to_open);
	tmp = ft_strnew(len);
	ft_strncpy(tmp, file_name_to_open, len);
	res = ft_strjoin(tmp, ".cor");
	free(tmp);

	fd = open(res, O_WRONLY | O_CREAT, 0777);

	write(fd, data_to_be_written, ft_strlen(data_to_be_written)); // can be int value;

	close(fd);
	free(res);
}

void	create_name_struct(char *file_name_to_open, t_toto sample)
{
	int len; 	// len till '.';
	int fd; 	// file descriptor;
	char *tmp; 	// buf;
	char *res; 	// string after join;

	len = ft_string_size(file_name_to_open);
	tmp = ft_strnew(len);
	ft_strncpy(tmp, file_name_to_open, len);
	res = ft_strjoin(tmp, ".cor");
	free(tmp);

	fd = open(res, O_WRONLY | O_CREAT, 0777);

	write(fd, &sample, 5); // can be int value;

	close(fd);
	free(res);
}


int		main(int argc, char **argv)
{
	(void)argc;	

	t_toto sample;

	sample.str = ft_strdup("12345");

	create_name_struct(argv[1], sample);

	system("leaks -q corewar");
}
