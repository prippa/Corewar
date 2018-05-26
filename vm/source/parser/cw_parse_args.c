/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:55:27 by prippa            #+#    #+#             */
/*   Updated: 2018/05/26 13:55:28 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <fcntl.h>

static void	cw_valid_champ(char *file_name)
{
	int fd;

	if ((fd = open(file_name, O_RDONLY)) == -1 || read(fd, NULL, 0) == -1)
		cw_perror_exit(file_name, OPEN_FILE);
	t_champ_add(&g_cw->pd.champs);
	g_cw->pd.champs->fd = fd;
	ft_strcpy(g_cw->pd.champs->file_name, file_name);
}

void		cw_parse_args(int argc, char **argv)
{
	int i;

	i = 0;
	argc += 0;
	while (argv[i])
	{
		if (ft_strstr(argv[i], ".cor"))
			cw_valid_champ(argv[i]);
		i++;
	}
}
