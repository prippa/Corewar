/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:06:25 by vgladush          #+#    #+#             */
/*   Updated: 2018/04/23 19:13:21 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// static void	name_cor(char *nm, char *s)
// {
// 	char	*name;
// 	int		i;

// 	i = ft_strlen(nm) - 1;
// 	while (--i && (nm[i] != '.' || nm[i] != '/'))
// 		;
// 	name = ft_strnew(i);
// 	while (i--)
// 		name[i] = nm[i];
// 	name = ft_joinfree(name, ".cor", 1);
// 	ft_printf("Writing output program to %s\n", name);
// 	name = ft_joinfree(s, name, 3);
// 	system(name);
// 	free(name);
// }


static void	crt_nm_cmt(t_asm *am, char *s, int i)
{
	int		j;

	j = 0;
	if (i == 1)
		while (s[am->x] != '\"')
			am->hd.prog_name[j++] = s[am->x++];
	else
		while (s[am->x] != '\"')
			am->hd.comment[j++] = s[am->x++];

}

static int	ch_comment(char *s, t_asm *am, char *cmt, int i)
{
	while (*cmt)
		if (*cmt++ != s[i++])
			return (0);
	if (am->hd.comment[0])
		errors_man(am, s, 2);
	am->x = i;
	while (s[am->x] == ' ' || s[am->x] == '\t')
		am->x++;
	if (!s[am->x] || s[am->x] == COMMENT_CHAR || s[am->x] == ';')
		errors_man(am, s, 5);
	if (s[am->x++] != '\"')
		errors_man(am, s, 9);
	i = am->x;
	while (s[i] && s[i] != '\"')
		i++;
	if (!s[i++])
		errors_man(am, s, 6);
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] != COMMENT_CHAR && s[i] != ';' && s[i] && (am->x = i + 1))
		errors_man(am, s, 9);
	if (i - am->x > 2048)
		errors_man(am, s, 8);
	crt_nm_cmt(am, s, 2);
	return (1);
}

static int	ch_name(char *s, t_asm *am, char *nm, int i)
{
	while (*nm)
		if (*nm++ != s[i++])
			return (0);
	if (am->hd.prog_name[0])
		errors_man(am, s, 1);
	am->x = i;
	while (s[am->x] == ' ' || s[am->x] == '\t')
		am->x++;
	if (!s[am->x] || s[am->x] == COMMENT_CHAR || s[am->x] == ';')
		errors_man(am, s, 5);
	if (s[am->x++] != '\"')
		errors_man(am, s, 9);
	i = am->x;
	while (s[i] && s[i] != '\"')
		i++;
	if (!s[i++])
		errors_man(am, s, 6);
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] != COMMENT_CHAR && s[i] != ';' && s[i] && (am->x = i + 1))
		errors_man(am, s, 9);
	if (i - am->x > 128)
		errors_man(am, s, 7);
	crt_nm_cmt(am, s, 1);
	return (1);
}

static void	valid_bit(int fd, t_asm *am, char *s)
{
	while (get_next_line(fd, &s) && (++am->y))
	{
		am->x = 0;
		while (s[am->x] && (s[am->x] == ' ' || s[am->x] == '\t'))
			am->x++;
		if (!s[am->x] || s[am->x] == COMMENT_CHAR || s[am->x] == ';')
			am->x = ft_strlen(s) + 1;
		else if (s[am->x] == '.')
		{
			if (!ch_name(s, am, NAME_CMD_STRING, am->x) &&
				!ch_comment(s, am, COMMENT_CMD_STRING, am->x))
				errors_man(am, s, 3);
		}
		else
			check_form(s, am, am->x, 0);
		free(s);
	}
	if (!am->lb)
		errors_man(am, 0, 6);
}

int			main(int ac, char **av)
{
	int		op;
	char	*line;
	t_asm	am;

	if (ac < 2)
	{
		errors_man(0, 0, 0);
		return (0);
	}
	line = 0;
	op = open(av[ac - 1], O_RDONLY);
	if (read(op, 0, 0) < 0)
		exit(ft_printf("Can't read source %s\n", av[ac - 1]));
	am.hd.magic = COREWAR_EXEC_MAGIC;
	am.x = 0;
	am.y = 0;
	am.lb = 0;
	ft_bzero(am.hd.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(am.hd.comment, COMMENT_LENGTH + 1);
	valid_bit(op, &am, line);
	// name_cor(av[ac - 1], am.bn);
	printf("%s\n%s\n", am.hd.prog_name, am.hd.comment);
	return (0);
}
