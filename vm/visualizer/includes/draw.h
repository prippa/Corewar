/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 17:10:45 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/24 17:10:46 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "base.h"

/*
** Rendering Corewar Arena
*/
void    draw_constants(t_arena *arena);
void    draw_fillrect(SDL_Rect rect, SDL_Color rgb, SDL_Renderer *renderer);
void	draw_arena(t_arena *arena);
void	draw_arena_cell(t_arena *arena, int i, int j, SDL_Rect rect);
void	draw_outlinerect(t_arena *arena, SDL_Rect rect);
void	draw_controls(t_arena *arena);
void	draw_background(t_arena *arena);
void	draw_infopanel(t_arena *arena);
void	draw_button_panel(t_arena *arena);
void	draw_statuses(t_arena *arena);
void	draw_framerate(t_arena *arena);
void    draw_winner(t_arena *arena);
#endif
