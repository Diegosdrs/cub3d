/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:47:39 by dsindres          #+#    #+#             */
/*   Updated: 2025/01/16 17:24:20 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_movement(int x, int y, t_cub *cub)
{
	static int	last_x;
	int			delta_x;
	double		rotation_angle;
	double		old_dir_x;

	(void)y;
	if (cub->player.mouse == 0)
	{
		last_x = x;
		cub->player.mouse = 1;
		return (0);
	}
	delta_x = x - last_x;
	last_x = x;
	rotation_angle = -delta_x * MOUSESENSE;
	old_dir_x = cub->player.dir.x;
	mouse_movement_2(cub, rotation_angle, old_dir_x);
	return (0);
}

int	mouse_movement_2(t_cub *cub, double rotation_angle, double old_dir_x)
{
	double		old_cam_x;

	cub->player.dir.x = cub->player.dir.x * cos(rotation_angle) - \
		cub->player.dir.y * sin(rotation_angle);
	cub->player.dir.y = old_dir_x * sin(rotation_angle) + \
		cub->player.dir.y * cos(rotation_angle);
	old_cam_x = cub->player.cam.x;
	cub->player.cam.x = cub->player.cam.x * cos(rotation_angle) - \
		cub->player.cam.y * sin(rotation_angle);
	cub->player.cam.y = old_cam_x * sin(rotation_angle) + \
		cub->player.cam.y * cos(rotation_angle);
	render_image(cub);
	return (0);
}
