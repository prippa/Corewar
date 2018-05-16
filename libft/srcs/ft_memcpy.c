/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 04:27:58 by vgladush          #+#    #+#             */
/*   Updated: 2017/10/26 04:27:59 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *str1;
	char *str2;

	str1 = (char *)dst;
	str2 = (char *)src;
	while (n-- > 0)
		*str1++ = *str2++;
	return (dst);
}
