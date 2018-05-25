/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:06:25 by vgladush          #+#    #+#             */
/*   Updated: 2018/05/25 14:42:17 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	crt_nm_cmt(t_asm *am, char *s, int i)
{
	int		j;

	j = 0;
	am->x++;
	if (i == 1)
	{
		if (am->nmcm == 1 || am->nmcm == 3)
			errors_man(am, s, 1);
		while (s[am->x] != '\"')
			am->hd.prog_name[j++] = s[am->x++];
		am->nmcm += 1;
	}
	else
	{
		if (am->nmcm == 2 || am->nmcm == 3)
			errors_man(am, s, 2);
		while (s[am->x] != '\"')
			am->hd.comment[j++] = s[am->x++];
		am->nmcm += 2;
	}
}

static int	ch_comment(char *s, t_asm *am, char *cmt, int i)
{
	while (*cmt)
		if (*cmt++ != s[i++])
			return (0);
	am->x = i;
	while (s[am->x] == ' ' || s[am->x] == '\t')
		am->x++;
	if (!s[am->x] || s[am->x] == COMMENT_CHAR || s[am->x] == ';')
		errors_man(am, s, 3);
	if (s[am->x] != '\"')
		errors_man(am, s, 4);
	i = am->x + 1;
	while (s[i] && s[i] != '\"')
		i++;
	if (!s[i++])
		errors_man(am, s, 5);
	if (i - am->x - 2 > COMMENT_LENGTH)
		errors_man(am, s, 7);
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] != COMMENT_CHAR && s[i] != ';' && s[i] && (am->x = i))
		errors_man(am, s, 3);
	crt_nm_cmt(am, s, 2);
	return (1);
}

static int	ch_name(char *s, t_asm *am, char *nm, int i)
{
	while (*nm)
		if (*nm++ != s[i++])
			return (0);
	am->x = i;
	while (s[am->x] == ' ' || s[am->x] == '\t')
		am->x++;
	if (!s[am->x] || s[am->x] == COMMENT_CHAR || s[am->x] == ';')
		errors_man(am, s, 3);
	if (s[am->x] != '\"')
		errors_man(am, s, 4);
	i = am->x + 1;
	while (s[i] && s[i] != '\"')
		i++;
	if (!s[i++])
		errors_man(am, s, 5);
	if (i - am->x - 2 > PROG_NAME_LENGTH)
		errors_man(am, s, 6);
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] && s[i] != COMMENT_CHAR && s[i] != ';' && (am->x = i + 1))
		errors_man(am, s, 3);
	crt_nm_cmt(am, s, 1);
	return (1);
}

static void	valid_bit(int fd, t_asm *am, char *s)
{
	while (get_next_line(fd, &s))
	{
		++am->y;
		am->x = 0;
		while (s[am->x] && (s[am->x] == ' ' || s[am->x] == '\t'))
			am->x++;
		if (!s[am->x] || s[am->x] == COMMENT_CHAR || s[am->x] == ';')
			am->x = ft_strlen(s) + 1;
		else if (s[am->x] == '.')
		{
			if (!ch_name(s, am, NAME_CMD_STRING, am->x) &&
				!ch_comment(s, am, COMMENT_CMD_STRING, am->x))
				errors_man(am, s, 0);
		}
		else
			check_form(s, am, am->x, 0);
		free(s);
	}
	// if (!am->lb)
	// 	errors_man(am, 0, 8);
	ch_to_coord(am);
}

void	reverse_binary_string(char *str)
{
	char buf[9];

	ft_bzero(buf, 9);
	buf[8] = '\0';
	ft_strncpy(buf, &str[0], 8);
	ft_strncpy(&str[0], &str[24], 8);
	ft_strncpy(&str[24], buf, 8);
	ft_strncpy(buf, &str[8], 8);
	ft_strncpy(&str[8], &str[16], 8);
	ft_strncpy(&str[16], buf, 8);
}

int		bstr_to_dec(char *str)
{
	int val;

	val = 0;
	while (*str != '\0')
		val = 2 * val + (*str++ - '0');
	return (val);
}

char	*ft_to_binary(unsigned int n)
{
	int		i;
	int		c;
	int		k;
	char	str[33];
	char	*reverse;

	i = 0;
	c = 31;
	reverse = ft_strnew(32);
	ft_bzero(reverse, 32);
	str[32] = '\0';
	while (c >= 0)
	{
		k = n >> c;
		if (k & 1)
			str[i++] = '1';
		else
			str[i++] = '0';
		c--;
	}
	reverse_binary_string(str);
	ft_strcpy(reverse, str);
	return (reverse);
}

int		ft_string_size(char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str) - 1;
	while (str[len] && str[len] != '/')
	{
		i++;
		len--;
	}
	return (i);
}

int		len_to_copy(char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str) - 1;
	while (str[len] && str[len] != '.' && str[len] != '/')
	{
		i++;
		len--;
	}
	if (ft_string_size(str) == i)
		return (0);
	return (i + 1);
}


char	*generate_file_name(char *file_string)
{

	int		len;
	int		copy_start;
	char	*tmp;
	char	*res;

	len = ft_string_size(file_string);
	copy_start = ft_strlen(file_string) - len;
	tmp = ft_strnew(len - len_to_copy(file_string));
	ft_strncpy(tmp, &file_string[copy_start], len - len_to_copy(file_string));
	res = ft_strjoin(tmp, ".cor");
	free(tmp);
	return (res);
}

void	write_to_struct(char *argv_name, t_asm *am)
{
	int		fd;
	char 	*file_name;
	char *test;

	file_name = generate_file_name(argv_name);
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0600); // append to file;

	test = ft_to_binary(am->hd.prog_size);
	am->hd.prog_size = bstr_to_dec(test);
	free(test);

	test = ft_to_binary(15369203);
	am->hd.magic = bstr_to_dec(test);
	free(test);

	write(fd, am, sizeof(am->hd.magic) + sizeof(am->hd.prog_name)
			+ sizeof(am->hd.prog_size) + sizeof(am->hd.comment));
	close(fd);
	free(file_name);
}

int			main(int ac, char **av)
{
	int		op;
	char	*line;
	t_asm	am;

	if (ac < 2)
		exit(ft_printf("need flags"));
	line = 0;
	op = open(av[ac - 1], O_RDONLY);
	if (read(op, 0, 0) < 0)
		exit(ft_printf("Can't read source %s\n", av[ac - 1]));
	am.hd.magic = COREWAR_EXEC_MAGIC;
	ft_bzero(am.hd.prog_name, PROG_NAME_LENGTH + 1);
	am.hd.prog_size = 0;
	ft_bzero(am.hd.comment, COMMENT_LENGTH + 1);
	am.lb = 0;
	am.nmcm = 0;
	am.x = 0;
	am.y = 0;
	valid_bit(op, &am, line);
	// name_cor(av[ac - 1], am);
	write_to_struct(av[1], &am);
	printf("%s\n%s\n", am.hd.prog_name, am.hd.comment);
	return (0);
}
