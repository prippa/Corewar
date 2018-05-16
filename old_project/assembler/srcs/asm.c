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

static int	ch_comment(char *s, t_asm *am, char *cmt, int i)
{
	am->x = -1;
	while (cmt[++am->x])
		if (cmt[am->x] != s[am->x])
			return (0);
	if (am->comment)
		errors_man(am, s, 2);
	while (s[am->x] == ' ' || s[am->x] == '\t')
		am->x++;
	if (!s[am->x] || s[am->x] == '#' || s[am->x] == ';')
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
	if (s[i] != '#' && s[i] && (am->x = i + 1))
		errors_man(am, s, 9);
	if (i - am->x > 2048)
		errors_man(am, s, 8);
	conver_bn(am, s, 2, 0);
	return (1);
}

static int	ch_name(char *s, t_asm *am, char *nm, int i)
{
	am->x = -1;
	while (nm[++am->x])
		if (nm[am->x] != s[am->x])
			return (0);
	if (am->name)
		errors_man(am, s, 1);
	while (s[am->x] == ' ' || s[am->x] == '\t')
		am->x++;
	if (!s[am->x] || s[am->x] == '#' || s[am->x] == ';')
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
	if (s[i] != '#' && s[i] != ';' && s[i] && (am->x = i + 1))
		errors_man(am, s, 9);
	if (i - am->x > 128)
		errors_man(am, s, 7);
	conver_bn(am, s, 1, 0);
	return (1);
}

static void	valid_bit(int fd, t_asm *am, char *s, int i)
{
	while (get_next_line(fd, &s))
	{
		am->y++;
		if (*s)
		{
			if (*s == '.')
			{
				if (!ch_name(s, am, ".name", 0) &&
					!ch_comment(s, am, ".comment", 0))
					errors_man(am, s, 3);
			}
			else
				check_form(s, am, 0);
		}
		free(s);
	}
	am->bn = ft_strdup("00ea 83f3 ");
	am->bn = ft_joinfree(am->bn, am->name, 3);
	am->bn = ft_joinfree(am->bn, " 0000 0000 0000 0125 ", 1);			///hz !!!
	am->bn = ft_joinfree(am->bn, am->comment, 3);
	// am->bn = ft_joinfree(am->bn, am->cmd, 3);
	while (am->bn[++i])
		if (!((i + 1) % 40))
			am->bn[i] = '\n';
}

int			main(int ac, char **av)
{
	int		op;
	char	*line;
	t_asm	am;

	if (ac < 2)
		exit(ft_printf("hzhzhzhzh"));			///hz
	line = 0;
	op = open(av[ac - 1], O_RDONLY);
	if (read(op, 0, 0) < 0)
		exit(ft_printf("Can't read source %s\n", av[ac - 1]));
	am.name = 0;
	am.cmd = 0;
	am.comment = 0;
	am.bn = 0;
	am.x = 0;
	am.y = 0;
	valid_bit(op, &am, line, 0);
	// name_cor(av[ac - 1], am.bn);
	return (0);
}
