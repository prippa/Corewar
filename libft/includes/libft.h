/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:30:01 by prippa            #+#    #+#             */
/*   Updated: 2018/05/29 01:21:42 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ft_printf.h"

# define BUFF_SIZE 80
# define ABS(x) (((x) < 0) ? -(x) : (x))
# define MAXINT 2147483647
# define MININT -2147483648

typedef	struct		s_gnl
{
	char			*s;
	size_t			i;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_atoi(const char *str);
int					ft_isspace(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);

char				*ft_strnew(size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putchar(char c);
void				ft_putstr(char const *s);

int					ft_str_is_digit(const char *str);
int					get_next_line(const int fd, char **line);
char				*ft_itoa_base(unsigned long long int num,
					int base, int letter);
char				*ft_itoa_max(long long int n);
long long int		ft_atoi_max(char *str);

char				*ft_itoabase(uintmax_t c, int sys, int rg);
uintmax_t			ft_basetoint(char *s, int base);
int					ft_numlen(intmax_t c, int a);
char				*ft_joinfree(char *s1, char *s2, int j);
int					ft_pow(int base, int level);
int					ft_bin_to_int(char *str, int index);
char				*ft_strjoin_free(char **dst, const char *src,
						size_t dstsize, size_t srcsize);

#endif
