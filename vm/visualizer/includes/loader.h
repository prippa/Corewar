/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 17:34:09 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/24 17:34:12 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADER_H
# define LOADER_H
# include "base.h"

/*
** Function for loading optimized surface
*/
SDL_Surface	*load_surface(const char *path,
							SDL_PixelFormat *screen_format);

/*
** Function for loading texture from optimized surface
*/
SDL_Texture	*load_texture(const char *path,
							SDL_PixelFormat *screen_format,
							SDL_Renderer **renderer);
#endif
