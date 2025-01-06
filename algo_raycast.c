/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:18:58 by dsindres          #+#    #+#             */
/*   Updated: 2024/12/16 15:57:04 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	algo_raycast(t_cub *cub)
{
	while (cub->pixel < screenWidth)
	{
		map_position(&cub->player);
		calculate_current_ray(cub);
		calculate_delta(cub);
		dda(cub);
		calculate_distance(cub);
		height_wall(cub);
		render_collumn_pixel(cub);
		cub->pixel++;
	}
	cub->pixel = 0;
	mlx_clear_window(cub->mlx_connection, cub->window);
	mlx_put_image_to_window(cub->mlx_connection, cub->window, cub->frame.ptr, 0, 0);
}

void	map_position(t_player *player)
{
	player->map_square.x = floor(player->pos.x);
	player->map_square.y = floor(player->pos.y);
}

void	calculate_current_ray(t_cub *cub)
{
	double		ray;
	t_vector	ray_ray;

	ray = 2 * ((double)cub->pixel / (screenWidth - 1)) - 1;
	ray_ray = mult_vector(&cub->player.cam, ray);
	cub->player.ray_dir = add_vector(&cub->player.dir, &ray_ray);
}

void	calculate_delta(t_cub *cub)
{
	cub->player.delta_dist_x = fabs(1 / cub->player.ray_dir.x);
	cub->player.delta_dist_y = fabs(1 / cub->player.ray_dir.y);
	if (cub->player.ray_dir.x < 0)
	{
		cub->player.dist_to_side_x = get_distance(cub, 1, 1);
		cub->player.step_x = -1;
	}
	else
	{
		cub->player.dist_to_side_x = get_distance(cub, 0, 1);
		cub->player.step_x = 1;
	}
	if (cub->player.ray_dir.y < 0)
	{
		cub->player.dist_to_side_y = get_distance(cub, 1, 0);
		cub->player.step_y = -1;
	}
	else
	{
		cub->player.dist_to_side_y = get_distance(cub, 0, 0);
		cub->player.step_y = 1;
	}
}

void	dda(t_cub *cub)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (cub->player.dist_to_side_x < cub->player.dist_to_side_y)
		{
			cub->player.dist_to_side_x += cub->player.delta_dist_x;
			cub->player.map_square.x += cub->player.step_x;
			cub->player.hit_side = 0;
		}
		else
		{
			cub->player.dist_to_side_y += cub->player.delta_dist_y;
			cub->player.map_square.y += cub->player.step_y;
			cub->player.hit_side = 1;
		}
		if (cub->map[cub->player.map_square.y][cub->player.map_square.x] == '1')
			hit = 1;
	}
}
