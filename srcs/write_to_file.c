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

int reversebits(int num)
{
    int NO_OF_BITS = sizeof(num) * 8;
    int reverse_num = 0, i, temp;
 
    for (i = 0; i < NO_OF_BITS; i++)
    {
        temp = (num & (1 << i));
        if(temp)
            reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
    }
  
    return reverse_num;
}

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

unsigned int reverseBits(unsigned int num)
{
    unsigned int count = sizeof(num) * 8 - 1;
    unsigned int reverse_num = num;
     
    num >>= 1; 
    while(num)
    {
       reverse_num <<= 1;       
       reverse_num |= num & 1;
       num >>= 1;
       count--;
    }
    reverse_num <<= count;
    return reverse_num;
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

void rvereseArray(char *arr, int start, int end)
{
    while (start < end)
    {
        char temp = arr[start]; 
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    } 
}  

// int 	len(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return(i);
// }

void	ft_write_hex(char *to, char *what)
{
	int i;
	int j;

	// ft_putstr(what);
	i = 8 - ft_strlen(what);
	ft_printf("int hexadecimal strlen->%d\n", i);
	j = ft_strlen(what) -1;
	ft_printf("int buf strlen->%d\n", j);
	ft_printf("to->%s\n", to);
	ft_printf("to[i]->%c\n", to[i]);
	ft_printf("what[j]->%c\n", to[j]);

	while (to[i -1] != '\0')
	{
		to[i++] = what[j--];
	}
}

void decToHexa(unsigned int n)
{   
    int i;
    int temp;
    char hexadecimal[8];
    ft_bzero(hexadecimal, 8);

    i = 0;
    while(n!=0)
    {   
         
        temp = n % 16;
        if(temp < 10)
        {
            hexadecimal[i] = temp + 48;
            i++;
        }
        else
        {
            hexadecimal[i] = temp + 55;
            i++;
        }
        n = n/16;
    }
    char *buf = ft_strnew(8);

    size_t a = 0;

    while (a < 8)
    	buf[a++] = '0';

    // ft_printf("i->%d\n", i);

    // ft_strcpy(&buf[8 -i], hexadecimal);

    ft_printf("inverted hex->%s\n", hexadecimal);
    ft_printf("%s\n", buf);
    ft_printf("%s\n", hexadecimal);


    ft_write_hex(buf, hexadecimal);

    ft_printf("%s\n", buf);


    // rvereseArray(buf, 0, ft_strlen(buf));


   ft_printf("\n");
}

int		main(int argc, char **argv)
{
	(void)argc;	

	t_toto sample;

	// sample.str = ft_strdup("12345");

	ft_bzero(sample.str, sizeof(sample.str)); //
	ft_strcpy(sample.str, "abcde");

	sample.x = 123456; //reverse bits;

	decToHexa(sample.x);

	// unsigned int magic;
	// unsigned int prog_size;


	// ft_printf("%d\n", reversebits(sample.x));

	// ft_printf("sizeof struct in main-> %d\n", sizeof(sample));

	create_name_struct(argv[1], &sample);

	system("leaks -q asm");
}
