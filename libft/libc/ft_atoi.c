/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:58:36 by prippa            #+#    #+#             */
/*   Updated: 2017/11/20 18:01:57 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	char	sign;
	int		res;

	sign = 0;
	res = 0;
	while (ft_isspace(*str))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = 1;
		++str;
	}
	while (ft_isdigit(*str))
		res = (res * 10) + (*str++ - '0');
	return (sign ? -res : res);
}

long long int	ft_atoi_max(char *str)
{
	char			sign;
	long long int	res;

	sign = 0;
	res = 0;
	while (ft_isspace(*str))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = 1;
		++str;
	}
	while (ft_isdigit(*str))
		res = (res * 10) + (*str++ - '0');
	return (sign ? -res : res);
}
