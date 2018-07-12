/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:06:25 by vgladush          #+#    #+#             */
/*   Updated: 2018/06/10 01:10:48 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	ch_comment(char **s, t_asm *am, int i)
{
	if (am->nmcm == 2 || am->nmcm == 3)
		errors_man(am, *s, 2);
	am->nmcm += 2;
	while (s[0][am->x] != '\"')
	{
		if (i + 1 > COMMENT_LENGTH)
			errors_man(am, *s, 7);
		if (!s[0][am->x])
		{
			am->x = 0;
			am->y++;
			am->hd.comment[i++] = '\n';
			free(*s);
			if (!get_next_line(am->fd, s))
				errors_man(am, *s, 5);
		}
		else
			am->hd.comment[i++] = s[0][am->x++];
	}
	am->x++;
	while (s[0][am->x] == ' ' || s[0][am->x] == '\t')
		am->x++;
	if (s[0][am->x] && s[0][am->x] != COMMENT_CHAR && s[0][am->x] != ';')
		errors_man(am, *s, 3);
}

static void	ch_name(char **s, t_asm *am, int i)
{
	if (am->nmcm == 1 || am->nmcm == 3)
		errors_man(am, *s, 1);
	am->nmcm += 1;
	while (s[0][am->x] != '\"')
	{
		if (i + 1 > PROG_NAME_LENGTH)
			errors_man(am, *s, 6);
		if (!s[0][am->x])
		{
			am->x = 0;
			am->y++;
			am->hd.prog_name[i++] = '\n';
			free(*s);
			if (!get_next_line(am->fd, s))
				errors_man(am, *s, 5);
		}
		else
			am->hd.prog_name[i++] = s[0][am->x++];
	}
	am->x++;
	while (s[0][am->x] == ' ' || s[0][am->x] == '\t')
		am->x++;
	if (s[0][am->x] && s[0][am->x] != COMMENT_CHAR && s[0][am->x] != ';')
		errors_man(am, *s, 3);
}

static void	check_command(char **s, t_asm *am, int o, int j)
{
	while (NAME_CMD_STRING[++o])
		if (NAME_CMD_STRING[o] != s[0][am->x + o])
			break ;
	if (!NAME_CMD_STRING[o])
		j = 1;
	else if ((o = -1))
	{
		while (COMMENT_CMD_STRING[++o])
			if (COMMENT_CMD_STRING[o] != s[0][am->x + o])
				errors_man(am, *s, 0);
	}
	am->x += o;
	while (s[0][am->x] == ' ' || s[0][am->x] == '\t')
		am->x++;
	if (!s[0][am->x] || s[0][am->x] == COMMENT_CHAR || s[0][am->x] == ';')
		errors_man(am, *s, 3);
	if (s[0][am->x] != '\"')
		errors_man(am, *s, 4);
	am->x++;
	if (j)
		ch_name(s, am, 0);
	else
		ch_comment(s, am, 0);
}

static void	valid_bit(t_asm *am, char *s)
{
	while (get_next_line(am->fd, &s))
	{
		++am->y;
		am->x = 0;
		while (s[am->x] && (s[am->x] == ' ' || s[am->x] == '\t'))
			am->x++;
		if (!s[am->x] || s[am->x] == COMMENT_CHAR || s[am->x] == ';')
			am->x = ft_strlen(s) + 1;
		else if (s[am->x] == '.')
			check_command(&s, am, -1, 0);
		else
			check_form(s, am, am->x, 0);
		free(s);
	}
	if (!am->lb)
		errors_man(am, 0, 5);
	ch_to_coord(am);
}

int			main(int ac, char **av)
{
	char	*line;
	t_asm	am;

	if (ac != 2)
		exit(ft_printf("Wrong number of arguments\n"));
	line = 0;
	am.fd = open(av[1], O_RDONLY);
	if (read(am.fd, 0, 0) < 0)
		exit(ft_printf("Can't read source %s\n", av[1]));
	am.hd.magic = COREWAR_EXEC_MAGIC;
	ft_bzero(am.hd.prog_name, PROG_NAME_LENGTH + 1);
	am.hd.prog_size = 0;
	ft_bzero(am.hd.comment, COMMENT_LENGTH + 1);
	am.lb = 0;
	am.nmcm = 0;
	am.x = 0;
	am.y = 0;
	valid_bit(&am, line);
	initial(av[1], &am);
	all_clear(&am, 0);
	return (0);
}
