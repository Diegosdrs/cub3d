/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:31:41 by dsindres          #+#    #+#             */
/*   Updated: 2025/01/16 11:55:10 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_image(t_cub *cub)
{
	init_frame(cub);
	move_player(cub);
	render_floor_and_ceiling(cub, 1);
	render_floor_and_ceiling(cub, 0);
	algo_raycast(cub);
	render_minimap(cub);
	return (0);
}

int	move_player(t_cub *cub)
{
	if (cub->escape == 1)
	{
		printf ("Goodbye !\n");
		free_all(cub, 1);
	}
	else if (cub->w == 1)
		move_up(cub);
	else if (cub->s == 1)
		move_down(cub);
	else if (cub->a == 1)
		move_left(cub);
	else if (cub->d == 1)
		move_right(cub);
	else if (cub->left == 1)
		turn_left(cub);
	else if (cub->right == 1)
		turn_right(cub);
	return (0);
}

int	convert_color(t_cub *cub, int flag)
{
	int	r;
	int	g;
	int	b;

	if (flag == 1)
	{
		r = cub->ceiling.r;
		g = cub->ceiling.g;
		b = cub->ceiling.b;
	}
	else
	{
		r = cub->floor.r;
		g = cub->floor.g;
		b = cub->floor.b;
	}
	return (rgb_to_hex(r, g, b));
}
