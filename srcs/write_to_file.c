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

int		ft_string_size(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	return (i);
}

char	*create_name_string(char *str)
{
	int len;
	char *tmp = NULL;
	char *cor = ".cor";
	char *res = NULL;

	// ft_string size to one func;
	len = ft_string_size(str);
	ft_printf("len->%d\n", len);

	// allocate memory for the name and .cor (4 symbols);
	tmp = ft_strnew(len);
	// copy to string till '.'
	ft_strncpy(tmp, str, len);
	// join string a .cor;
	res = ft_strjoin(tmp, cor);

	free(tmp);

	return (res);
}


int		main(int argc, char **argv)
{
	(void)argc;
	char *name = create_name_string(argv[1]);

	ft_printf("name for the file->%s\n", name);

	system("leaks -q corewar");
}
