/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:42:16 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/13 18:04:31 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_ulllen(unsigned long long int n)
{
	int		len;

	len = 2;
	while (n /= 10)
		len++;
	return (len);
}

char		*ft_ulltoa(unsigned long long int n)
{
	int		len;
	char	*res;

	len = ft_ulllen(n);
	if ((res = (char *)malloc(len)) == NULL)
		return (NULL);
	res[--len] = '\0';
	res[--len] = n % 10 + 48;
	while (n /= 10)
		res[--len] = n % 10 + 48;
	return (res);
}
