/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:47:39 by dsindres          #+#    #+#             */
/*   Updated: 2025/01/13 09:54:57 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_movement(int x, int y, t_cub *cub)
{
	static int	last_x;
	int			delta_x;
	double		rotation_angle;
	(void)y;

	if (cub->player.mouse == 0)
	{
		last_x = x;
		cub->player.mouse = 1;
		return (0);
	}
	delta_x = x - last_x;
	last_x = x;
	rotation_angle = -delta_x * mouse_sensitivity;

	double old_dir_x = cub->player.dir.x;
	cub->player.dir.x = cub->player.dir.x * cos(rotation_angle) - cub->player.dir.y * sin(rotation_angle);
	cub->player.dir.y = old_dir_x * sin(rotation_angle) + cub->player.dir.y * cos(rotation_angle);

	double old_cam_x = cub->player.cam.x;
	cub->player.cam.x = cub->player.cam.x * cos(rotation_angle) - cub->player.cam.y * sin(rotation_angle);
	cub->player.cam.y = old_cam_x * sin(rotation_angle) + cub->player.cam.y * cos(rotation_angle);

	render_image(cub);
	return (0);
}
