/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_alpha_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:17:52 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/30 14:17:54 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	set_alpha_mode(Uint8 alpha,
						t_ltexture *ltexture)
{
	SDL_SetTextureAlphaMod(ltexture->texture, alpha);
}
