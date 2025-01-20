/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_raycast_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:54:53 by dsindres          #+#    #+#             */
/*   Updated: 2025/01/16 17:23:57 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_distance(t_cub *cub)
{
	t_player	*player;

	player = &cub->player;
	if (player->hit_side == 0)
		player->size_ray = perpendicular_dist(player, player->step_x, 0);
	else
		player->size_ray = perpendicular_dist(player, player->step_y, 1);
}

void	height_wall(t_cub *cub)
{
	t_player	*player;

	player = &cub->player;
	player->tall_of_wall = fabs(((double)SCREENH / player->size_ray));
	player->begin_wall = (SCREENH / 2.00) - (player->tall_of_wall / 2.00);
	player->end_wall = (SCREENH / 2.00) + (player->tall_of_wall / 2.00);
	if (player->begin_wall < 0)
		player->begin_wall = 0;
	if (player->end_wall > SCREENH)
		player->end_wall = SCREENH - 1;
	impact_on_wall(player);
}

void	render_collumn_pixel(t_cub *cub)
{
	int		x;
	int		y;
	double	step_y;
	double	pos;

	step_y = fabs((double)SIZTEXT / cub->player.tall_of_wall);
	pos = (cub->player.begin_wall - (SCREENH / 2) \
		+ (cub->player.tall_of_wall / 2)) * step_y;
	y = cub->player.begin_wall;
	x = cub->pixel;
	while (y < cub->player.end_wall && y < SCREENH)
	{
		cub->player.text_y = (int)pos & (SIZTEXT - 1);
		pos += step_y;
		my_mlx_pixel_put(cub, x, y, obtain_color(cub));
		y++;
	}
}
