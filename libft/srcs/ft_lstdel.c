/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:31:57 by vgladush          #+#    #+#             */
/*   Updated: 2017/11/07 09:31:59 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *nextlst;
	t_list *tmp;

	if (alst && del)
	{
		tmp = *alst;
		while (tmp)
		{
			nextlst = tmp->next;
			del(tmp->content, tmp->content_size);
			free(tmp);
			tmp = nextlst;
		}
		*alst = NULL;
	}
}
