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
	int i;

	decimal = 0;
	i = 0;
	while (i < 8)
	{
		if (str[index] == '1')
			decimal += ft_pow(2, i);
		i++;
		index--;
	}
	return (decimal);
}
