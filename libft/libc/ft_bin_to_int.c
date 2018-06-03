/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 20:53:48 by otimofie          #+#    #+#             */
/*   Updated: 2018/06/03 20:53:52 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_bin_to_int(char *str, int index)
{
	int decimal;
	int	len;
	int i;

	decimal = 0;
	len = 7;
	i = 0;
	while (len >= 0)
	{
		if (str[index] == '1')
			decimal += ft_pow(2, i);
		i++;
		index--;
		len--;
	}
	return (decimal);
}
