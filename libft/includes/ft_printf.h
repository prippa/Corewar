/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:15:55 by vgladush          #+#    #+#             */
/*   Updated: 2018/01/17 13:45:48 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>
# include <wchar.h>
# include <wctype.h>
# include <stdint.h>

# define FLSIZ(x) x == 'j' || x == 'z' || x == '#' || x == 'l' || x == 'h'
# define FL2(x) x == ' ' || (x != 44 && x != 47 && x > 41 && x < 58) || x == 'L'
# define DEVAL(x) x == 'D' || x == 'd' || x == 'x' || x == 'O' || x == 'b'
# define DEVA2(x) x == 'i' || x == 'o' || x == 'X' || x == 'u' || x == 'U'
# define OPER(x) (x < 96 || x > 103) && x != 105 && x != 120 && x != 114
# define OPE2(x) x != 115 && (x < 110 || x > 112) && x != 117  && x != 83
# define OPE3(x) (x < 65 || x > 71) && x != 85 && x != 88 && x != 79

int					ft_nbrlen(intmax_t c, int a);
int					ft_printf(const char *format, ...);
void				ft_prfoper(char *s, va_list *ar, int *i);
void				ft_prfnbr(char c, int *i, va_list *ar, char *ito);
char				*ft_itoabase(uintmax_t c, int l, int y);
size_t				ft_strlen(const char *s);
char				*unistr(wchar_t *s, int *j);
char				*unicd(wint_t c);
void				ft_prfdbl(char c, int *i, va_list *ar);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
uintmax_t			ft_basetoint(char *s, int base);
char				*ft_joinfree(char *s1, char *s2, int j);
void				ft_dblhex(long double c, int *i, int y);
size_t				ft_wcharlen(const wchar_t *s);
void				ft_precforp(char *s, int *i);
void				ft_outun(char *s, int *i, int j, int c);
char				*ft_qstr(char *s, int *i);
void				strendf(char s, int *i);
char				*ft_rotnb(char *s, int i);

#endif
