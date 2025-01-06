/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_raycast_utils_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:10:15 by dsindres          #+#    #+#             */
/*   Updated: 2024/12/17 15:51:37 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	dist_to_wall_x(t_player *player)
{
	double	dist_to_side_x;

	if (player->ray_dir.x < 0)
	{
		dist_to_side_x = (player->pos.x - player->map_square.x) * (1 / player->ray_dir.x);
		player->map_square.x += -1;
	}
	else
	{
		dist_to_side_x = (player->map_square.x + 1 - player->pos.x) \
			* (1 / player->ray_dir.x);
		player->map_square.x += 1;
	}
	return (dist_to_side_x);
}

double	dist_to_wall_y(t_player *player)
{
	double	dist_to_side_y;

	if (player->ray_dir.y < 0)
	{
		dist_to_side_y = (player->pos.y - player->map_square.y) * (1 / player->ray_dir.y);
		player->map_square.y += -1;
	}
	else
	{
		dist_to_side_y = (player->map_square.y + 1 - player->pos.y) \
			* (1 / player->ray_dir.y);
		player->map_square.y += 1;
	}
	return (dist_to_side_y);
}

void	rotate_vector(t_vector *v, double angle)
{
	double	x;
	double	y;

	x = v->x;
	y = v->y;
	v->x = x * cos(angle) - y * sin(angle);
	v->y = x * sin(angle) + y * cos(angle);
}
