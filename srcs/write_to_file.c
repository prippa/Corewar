// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   write_to_file.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2018/05/21 14:50:31 by otimofie          #+#    #+#             */
// /*   Updated: 2018/05/21 14:50:33 by otimofie         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../libft/ft_printf.h"

typedef struct			s_arg
{
	t_arg_type			tp; // nope -> ype id for tp == ? 1 ->ch 2 4; char to be printed without conversion;
	char				dn; // nope;
	void				*av; // only this to cast;
	int					x; // nope
	int					y; // nope
}						t_arg;

typedef struct			s_command
{
	int					bit; // nope
	char				cmd; // always as char
	int					codage; // only if our command is not 1, 9, 12, 15;
	t_arg				arg1; // if type not null -> print as type indicates;
	t_arg				arg2; // if type not null -> print as type indicates;
	t_arg				arg3; // if type not null -> print as type indicates;
	struct s_command	*next;
}						t_command;

typedef struct			s_label
{
	char				*name; //nope
	t_command			*cmd;
	int					bit; // nope
	struct s_label		*next; // nope
}						t_label;

typedef struct			s_asm
{
	header_t			hd;
	t_label				*lb;
	int					nmcm;
	int					x;
	int					y;
}						t_asm;

typedef struct		s_toto
{
	unsigned int	magic;
	char			prog_name[128 + 1];
	unsigned int	prog_size;
	// size of the commands of program itself (not the whole file);
	char			comment[2048 + 1];
}					t_toto;

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

void	init(char *str)
{
	int a;

	a = 0;
	while (a < 8)
		str[a++] = '0';
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

void	write_to_struct(char *file_name, t_toto *sample)
{
	int		len;
	int		fd;
	int		copy_start;
	char	*tmp;
	char	*res;

	len = ft_string_size(file_name);
	copy_start = ft_strlen(file_name) - len;
	tmp = ft_strnew(len - len_to_copy(file_name));
	ft_strncpy(tmp, &file_name[copy_start], len - len_to_copy(file_name));
	res = ft_strjoin(tmp, ".cor");
	free(tmp);
	fd = open(res, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	sample->prog_size = bstr_to_dec(ft_to_binary(23));
	sample->magic = bstr_to_dec(ft_to_binary(15369203));
	write(fd, sample, sizeof(sample->magic) + sizeof(sample->prog_name)
			+ sizeof(sample->prog_size) + sizeof(sample->comment));
	close(fd);
	free(res);
}

int		main(int argc, char **argv)
{
	t_toto	sample;

	(void)argc;
	ft_bzero(sample.prog_name, sizeof(sample.prog_name));
	ft_strcpy(sample.prog_name, "zork");
	ft_bzero(sample.comment, sizeof(sample.comment));
	ft_strcpy(sample.comment, "just a basic living prog");
	write_to_struct(argv[1], &sample);
}
