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
	// ft_printf("i -> %d", i);
	return (i);
}

void	ft_write_hex(char *to, char *what)
{
	int i;
	int j;

	if (ft_strlen(what) == 8)
		i = 0;
	else
		i = 8 - ft_strlen(what);
	j = ft_strlen(what) - 1;
	while (to[i] != '\0')
		to[i++] = what[j--];
}

void	init(char *str)
{
	int a;

	a = 0;
	while (a < 8)
		str[a++] = '0';
}

void	ft_reverse(char *str)
{
	char buf[3];

	ft_bzero(buf, 3);
	ft_strncpy(buf, &str[0], 2);
	ft_strncpy(&str[0], &str[6], 2);
	ft_strncpy(&str[6], buf, 2);
	ft_strncpy(buf, &str[2], 2);
	ft_strncpy(&str[2], &str[4], 2);
	ft_strncpy(&str[4], buf, 2);
}

char	*dec_to_hexa(unsigned int n)
{
	int		i;
	int		temp;
	char	hexadecimal[100];
	char	*buf;
	size_t	a;

	ft_bzero(hexadecimal, 100);
	i = 0;
	a = 0;
	while (n)
	{
		temp = n % 16;
		if (temp < 10)
			hexadecimal[i++] = temp + 48;
		else
			hexadecimal[i++] = temp + 55;
		n = n / 16;
	}
	buf = ft_strnew(8);
	init(buf);
	ft_write_hex(buf, hexadecimal);
	// ft_printf("buf before reverse -> %s\n", buf);
	ft_reverse(buf);
	// ft_printf("buf after  reverse -> %s\n", buf);
	return (buf);
}

unsigned int		hexadecimal_to_decimal(char *hexval)
{
	unsigned int	base;
	unsigned int	dec_val;
	int				i;
	char			*str;

	base = 1;
	dec_val = 0;
	i = 7;
	str = hexval;
	while (i >= 0)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			dec_val += (str[i--] - 48) * base;
			base = base * 16;
		}
		else if (str[i] >= 'A' && str[i] <= 'F')
		{
			dec_val += (str[i--] - 55) * base;
			base = base * 16;
		}
	}
	free(str);
	return (dec_val);
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
	// ft_printf("i -> %d\n", i);
	// ft_printf("len -> %d\n", ft_string_size(str));
	if (ft_string_size(str) == i)
		return (0);
	return (i + 1);
}

void	write_to_struct(char *file_name, t_toto *sample)
{
	int		len;
	int		fd;
	int		copy_start;
	char	*tmp;
	char	*res;
	void	*ar;
	unsigned int 	asd;


	asd = 1792; // inverted value = 1792;

	// asd = hexadecimal_to_decimal(dec_to_hexa(asd));
	// ft_printf("%u\n", asd);
	// short buf = asd;
	ar = &asd;

	// short x = *(short *)ar;

	// ft_printf("%u\n",x);


	// int -> short | char'

	len = ft_string_size(file_name);
	copy_start = ft_strlen(file_name) - len;
	// ft_printf("copy_start -> %d\n", copy_start);
	tmp = ft_strnew(len - len_to_copy(file_name));
	// ft_printf("%s\n", "Check");
	ft_strncpy(tmp, &file_name[copy_start], len - len_to_copy(file_name));
	res = ft_strjoin(tmp, ".cor");
	free(tmp);
	fd = open(res, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	sample->magic = hexadecimal_to_decimal(dec_to_hexa(sample->magic));
	sample->prog_size = hexadecimal_to_decimal(dec_to_hexa(sample->prog_size));
	ft_putnbr(sample->prog_size);
	// ft_printf("unsigned int ->%u\n", sample->magic);
	// ft_printf("str size -> %d\n", sizeof(sample->prog_name));
	// ft_printf("unsigned int size -> %d\n", sizeof(sample->magic));
	write(fd, sample, sizeof(sample->magic) + sizeof(sample->prog_name)
			+ sizeof(sample->prog_size) + sizeof(sample->comment));

	write(fd, (short*)ar, 2);

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
	sample.magic = 15369203;
	sample.prog_size = 23;
	write_to_struct(argv[1], &sample);
	// system("leaks -q asm");
}
