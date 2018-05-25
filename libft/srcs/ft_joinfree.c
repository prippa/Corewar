/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:43:59 by vgladush          #+#    #+#             */
/*   Updated: 2018/01/05 15:03:25 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinfree(char *s1, char *s2, int j)
{
	size_t	i;
	char	*res;
	int		z;

	z = -1;
	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = (char *)malloc(i + 1)))
		return (0);
	res[i] = '\0';
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	while (s2[++z])
		res[i + z] = s2[z];
	if (j == 3 || j == 1)
		free(s1);
	if (j == 3 || j == 2)
		free(s2);
	return (res);
}
