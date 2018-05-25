/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inversion_of_decimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 17:32:51 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/25 17:32:53 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	reverse_binary_string(char *str)
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

int			bstr_to_dec(char *str)
{
	int val;

	val = 0;
	while (*str != '\0')
		val = 2 * val + (*str++ - '0');
	return (val);
}

char		*ft_to_binary(unsigned int n)
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
