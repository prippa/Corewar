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
	unsigned int x;
	char str[5];
}				t_toto;

int		ft_string_size(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '.') // / / / / /.s
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

void	create_name_struct(char *file_name_to_open, t_toto *sample)
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

	fd = open(res, O_WRONLY | O_CREAT | O_TRUNC, 0777); //current position of the |;



	// hex = reverseBits(sample->x);
	
// 
	write(fd, sample, sizeof(sample->str) + sizeof(sample->x));
	// sample = NULL;
	// int x = 7;
	// write(fd, "12345", 3);/
	// write(fd, &x, 6);


	// ft_printf("sizeof struct in func -> %d\n", sizeof(sample->str) + sizeof(sample->x));
	close(fd);
	free(res);
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
void init(char *str)
{
	int a = 0;
	while (a < 8)
    	str[a++] = '0';
}

void	ft_reverse(char *str)
{
	char buf[3];
	ft_bzero(buf, 3);
	// buf[2] = '\0';

	ft_strncpy(buf, &str[0], 2);
	ft_strncpy(&str[0], &str[6], 2);
	ft_strncpy(&str[6], buf, 2);


	ft_strncpy(buf, &str[2], 2);
	ft_strncpy(&str[2], &str[4], 2);
	ft_strncpy(&str[4], buf, 2);
}

char *decToHexa(unsigned int n)
{   
    int i;
    int temp;
    char hexadecimal[100];
    char *buf;
    size_t a;

    ft_bzero(hexadecimal, 100);
    i = 0;
    a = 0;
    while(n)
    {   
        temp = n % 16;
        if(temp < 10)
            hexadecimal[i++] = temp + 48;
        else
            hexadecimal[i++] = temp + 55;
        n = n/16;
    }
    buf = ft_strnew(8);
	init(buf);

    ft_write_hex(buf, hexadecimal);
    ft_reverse(buf);
    //reverse; here
    return (buf);
}

int hexadecimalToDecimal(char hexVal[])
{   
    int len = 8;
     
    // Initializing base value to 1, i.e 16^0
    int base = 1;
     
    int dec_val = 0;
     
    // Extracting characters as digits from last character
    for (int i=len-1; i>=0; i--)
    {   
        // if character lies in '0'-'9', converting 
        // it to integral 0-9 by subtracting 48 from
        // ASCII value.
        if (hexVal[i]>='0' && hexVal[i]<='9')
        {
            dec_val += (hexVal[i] - 48)*base;
                 
            // incrementing base by power
            base = base * 16;
        }
 
        // if character lies in 'A'-'F' , converting 
        // it to integral 10 - 15 by subtracting 55 
        // from ASCII value
        else if (hexVal[i]>='A' && hexVal[i]<='F')
        {
            dec_val += (hexVal[i] - 55)*base;
         
            // incrementing base by power
            base = base*16;
        }
    }
     
    return dec_val;
}

int		main(int argc, char **argv)
{
	(void)argc;	

	t_toto sample;

	ft_bzero(sample.str, sizeof(sample.str));
	ft_strcpy(sample.str, "abcde");
	


	sample.x = 654;

	char *test = decToHexa(sample.x);

	sample.x = hexadecimalToDecimal(test);

	create_name_struct(argv[1], &sample);

	system("leaks -q asm");
}
