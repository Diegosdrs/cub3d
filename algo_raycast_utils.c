/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_raycast_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:10:55 by dsindres          #+#    #+#             */
/*   Updated: 2025/01/16 17:23:57 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	mult_vector(t_vector *vector, double n)
{
	t_vector	new;

	new.x = vector->x * n;
	new.y = vector->y * n;
	return (new);
}

t_vector	add_vector(t_vector *vector1, t_vector *vector2)
{
	t_vector	new;

	new.x = vector1->x + vector2->x;
	new.y = vector1->y + vector2->y;
	return (new);
}

double	get_distance(t_cub *cub, int zero, int x)
{
	if (x && zero)
		return ((cub->player.pos.x - cub->player.map_square.x) \
			* cub->player.delta_dist_x);
	else if (x && !zero)
		return ((cub->player.map_square.x + 1.0 - cub->player.pos.x) \
			* cub->player.delta_dist_x);
	else if (!x && zero)
		return ((cub->player.pos.y - cub->player.map_square.y) \
			* cub->player.delta_dist_y);
	else
		return ((cub->player.map_square.y + 1.0 - cub->player.pos.y) \
			* cub->player.delta_dist_y);
}

void	impact_on_wall(t_player *player)
{
	double	wall;

	if (!player->hit_side)
	{
		if (player->pos.x < player->map_square.x)
			wall = player->pos.y + player->size_ray * player->ray_dir.y;
		else
			wall = player->pos.y - player->size_ray * player->ray_dir.y;
	}
	else
	{
		if (player->pos.y > player->map_square.y)
			wall = player->pos.x - player->size_ray * player->ray_dir.x;
		else
			wall = player->pos.x + player->size_ray * player->ray_dir.x;
	}
	wall -= floor(wall);
	player->text_x = (int)(wall * (double)SIZTEXT);
	if (player->hit_side && player->pos.y < player->map_square.y)
		player->text_x = SIZTEXT - player->text_x - 1;
	if (!player->hit_side && player->pos.x > player->map_square.x)
		player->text_x = SIZTEXT - player->text_x - 1;
}

double	perpendicular_dist(t_player *player, int value, int flag)
{
	double	n;
	int		a;
	double	b;

	if (flag == 1)
	{
		a = player->map_square.y;
		b = player->pos.y;
	}
	else
	{
		a = player->map_square.x;
		b = player->pos.x;
	}
	n = fabs(a - b + ((1 - value) / 2));
	if (flag == 1)
		n /= player->ray_dir.y;
	else
		n /= player->ray_dir.x;
	return (n);
}
