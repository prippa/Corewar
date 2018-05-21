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

int		ft_string_size(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	return (i);
}

void	create_name_string(char *str)
{
	int len;
	char *tmp;
	char *cor;
	char *res;

	cor = ".cor";
	len = ft_string_size(str);
	tmp = ft_strnew(len);
	ft_strncpy(tmp, str, len);
	res = ft_strjoin(tmp, cor);
	free(tmp);

	char *data="123456";

	int fd = open(res, O_WRONLY | O_CREAT | O_EXCL, 0777);
	write(fd, data, ft_strlen(data));
	close(fd);
	free(res);
}


int		main(int argc, char **argv)
{
	(void)argc;	

	create_name_string(argv[1]);

	system("leaks -q corewar");
}
