/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 11:16:19 by vgladush          #+#    #+#             */
/*   Updated: 2017/11/03 11:16:20 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_neg(int n)
{
	int			i;
	int			a;
	char		*str;

	a = n;
	i = 1;
	while (i++ < 11 && a < -9)
		a /= 10;
	if ((str = (char *)malloc(i + 1)) == NULL)
		return (NULL);
	str[0] = '-';
	str[i] = '\0';
	while (i-- > 1)
	{
		str[i] = -(n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			i;
	int			a;

	a = n;
	if (n < 0)
		return (ft_neg(a));
	i = 0;
	while (i++ < 10 && a > 9)
		a /= 10;
	if ((str = (char *)malloc(i + 1)) == NULL)
		return (NULL);
	str[i] = '\0';
	while (i-- > 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
