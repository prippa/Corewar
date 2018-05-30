/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:58:49 by prippa            #+#    #+#             */
/*   Updated: 2018/05/26 13:58:50 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memrev(void *dst, size_t n)
{
	size_t			i;
	char			c;
	unsigned char	*dst_buf;

	if (!n)
		return ;
	dst_buf = (unsigned char *)dst;
	i = 0;
	while (n - 1 > i)
	{
		c = dst_buf[i];
		dst_buf[i] = dst_buf[n - 1];
		dst_buf[n - 1] = c;
		n--;
		i++;
	}
}
