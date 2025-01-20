/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:51:59 by dsindres          #+#    #+#             */
/*   Updated: 2025/01/20 11:45:50 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_right(t_cub *cub)
{
	t_player	*temp_player;
	t_vector	vec;

	vec.x = cub->player.dir.x;
	vec.y = cub->player.dir.y;
	rotate_vector(&vec, PI / 2);
	temp_player = &cub->player;
	temp_player->pos.y += VITESSE * vec.y * 1;
	temp_player->pos.x += VITESSE * vec.x * 1;
	if (cub->map[(int)temp_player->pos.y][(int)temp_player->pos.x] != '0')
	{
		temp_player->pos.y -= VITESSE * vec.y * 1;
		temp_player->pos.x -= VITESSE * vec.x * 1;
		return ;
	}
}

void	move_left(t_cub *cub)
{
	t_player	*temp_player;
	t_vector	vec;

	vec.x = cub->player.dir.x;
	vec.y = cub->player.dir.y;
	rotate_vector(&vec, PI / 2);
	temp_player = &cub->player;
	temp_player->pos.y += VITESSE * vec.y * -1;
	temp_player->pos.x += VITESSE * vec.x * -1;
	if (cub->map[(int)temp_player->pos.y][(int)temp_player->pos.x] != '0')
	{
		temp_player->pos.y -= VITESSE * vec.y * -1;
		temp_player->pos.x -= VITESSE * vec.x * -1;
		return ;
	}
}

void	turn_right(t_cub *cub)
{
	double	old_dir_x;
	double	old_cam_x;

	old_dir_x = cub->player.dir.x;
	cub->player.dir.x = cub->player.dir.x * cos(SENSITIVITY) - \
	cub->player.dir.y * sin(SENSITIVITY);
	cub->player.dir.y = old_dir_x * sin(SENSITIVITY) + \
	cub->player.dir.y * cos(SENSITIVITY);
	old_cam_x = cub->player.cam.x;
	cub->player.cam.x = cub->player.cam.x * cos(SENSITIVITY) - \
	cub->player.cam.y * sin(SENSITIVITY);
	cub->player.cam.y = old_cam_x * sin(SENSITIVITY) + \
	cub->player.cam.y * cos(SENSITIVITY);
}

void	turn_left(t_cub *cub)
{
	double	old_dir_x;
	double	old_cam_x;

	old_dir_x = cub->player.dir.x;
	cub->player.dir.x = cub->player.dir.x * cos(-SENSITIVITY) - \
	cub->player.dir.y * sin(-SENSITIVITY);
	cub->player.dir.y = old_dir_x * sin(-SENSITIVITY) + \
	cub->player.dir.y * cos(-SENSITIVITY);
	old_cam_x = cub->player.cam.x;
	cub->player.cam.x = cub->player.cam.x * cos(-SENSITIVITY) - \
	cub->player.cam.y * sin(-SENSITIVITY);
	cub->player.cam.y = old_cam_x * sin(-SENSITIVITY) + \
	cub->player.cam.y * cos(-SENSITIVITY);
}
