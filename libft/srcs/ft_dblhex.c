/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblhex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:50:22 by vgladush          #+#    #+#             */
/*   Updated: 2018/01/15 16:22:39 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	hexlast(char **s, int *i)
{
	if (i[18] == 1)
		s[0] = ft_joinfree("-", s[0], 2);
	else if (i[2] == 2)
		s[0] = ft_joinfree("+", s[0], 2);
	else if (i[2] == 1)
		s[0] = ft_joinfree(" ", s[0], 2);
	while (i[3] == 1 && ft_strlen(s[0]) + ft_strlen(s[1]) < (size_t)i[10])
		s[0] = ft_joinfree(s[0], "0", 1);
	while (!i[3] && ft_strlen(s[0]) + ft_strlen(s[1]) < (size_t)i[10])
		s[0] = ft_joinfree(" ", s[0], 2);
	while (i[3] == 2 && ft_strlen(s[0]) + ft_strlen(s[1]) < (size_t)i[10])
		s[1] = ft_joinfree(s[1], " ", 1);
	s[0] = ft_joinfree(s[0], s[1], 2);
	i[1] += write(1, s[0], ft_strlen(s[0]));
	free(s[0]);
	free(s);
}

static	void	hexsec(uintmax_t z, char **s, int *i, int y)
{
	int			j;

	j = 12;
	if (i[11] && z != 0)
		s[1] = ft_itoabase(z, 16, y);
	else
		s[1] = ft_strdup("");
	while ((int)ft_strlen(s[1]) < i[11])
		s[1] = ft_joinfree("0", s[1], 2);
	if (ft_strlen(s[1]) == 13)
		while (s[1][j] == '0')
			s[1][j--] = '\0';
	s[0] = ft_itoabase(i[16], 1, 0);
	if (s[0][0] != '-')
		s[0] = ft_joinfree("+", s[0], 2);
	s[0] = ft_joinfree(" ", s[0], 2);
	s[0][0] = y + 15;
	s[1] = ft_joinfree(s[1], s[0], 3);
	if (i[11] && s[1][0] != 'p' && s[1][0] != 'P')
		s[1] = ft_joinfree(".", s[1], 2);
	s[1] = ft_joinfree(" ", s[1], 2);
	s[1][0] = i[17] + 48;
	s[0] = ft_strdup("0 ");
	s[0][1] = y + 23;
	hexlast(s, i);
}

void			ft_dblhex(long double c, int *i, int y)
{
	char		**s;

	if (!(s = (char **)malloc(sizeof(char *) * 3)))
		return ;
	s[2] = 0;
	if (c < 0 && (i[18] = 1))
		c = -c;
	while (c >= 2 && (i[16] += 1))
		c /= 2;
	while (c != 0 && c < 1 && (i[16] -= 1))
		c *= 2;
	if (c != 0)
		c -= 1;
	i[17] = (i[11] > -1 ? i[11] : 13);
	while (c != 0 && (i[17] -= 1) > -1)
		c *= 16;
	if (c == 0)
		i[17] = 0;
	else if (!i[11] && c + 0.5 >= 1)
		i[17] = 2;
	else
		i[17] = 1;
	hexsec(c + 0.5, s, i, y);
}
