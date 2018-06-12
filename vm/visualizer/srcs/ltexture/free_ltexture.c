/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ltexture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:55:35 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/29 12:55:37 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	free_ltexture(t_ltexture *ltexture)
{
	if (ltexture != NULL)
	{
		SDL_DestroyTexture(ltexture->texture);
		bzero(ltexture, sizeof(t_ltexture));
	}
}
