/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:01:41 by dsindres          #+#    #+#             */
/*   Updated: 2025/01/06 11:26:43 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	movement_key(int key, t_cub *cub)
{
	if (key == XK_Escape)
		cub->escape = 1;
	else if (key == XK_w)
		cub->w = 1;
	else if (key == XK_s)
		cub->s = 1;
	else if (key == XK_a)
		cub->a = 1;
	else if (key == XK_d)
		cub->d = 1;
	else if (key == 65361)
		cub->left = 1;
	else if (key == 65363)
		cub->right = 1;
	return (0);
}

int	movement_key_2(int key, t_cub *cub)
{
	if (key == XK_Escape)
		cub->escape = 0;
	else if (key == XK_w)
		cub->w = 0;
	else if (key == XK_s)
		cub->s = 0;
	else if (key == XK_a)
		cub->a = 0;
	else if (key == XK_d)
		cub->d = 0;
	else if (key == 65361)
		cub->left = 0;
	else if (key == 65363)
		cub->right = 0;
	return (0);
}

void	move_up(t_cub *cub)
{
	t_player	*temp;
	temp = &cub->player;
	temp->pos.y += VITESSE * cub->player.dir.y * 1;
	temp->pos.x += VITESSE * cub->player.dir.x * 1;
	if (cub->map[(int)temp->pos.y][(int)temp->pos.x] != '0')
	{
		temp->pos.y -= VITESSE * cub->player.dir.y * 1;
		temp->pos.x -= VITESSE * cub->player.dir.x * 1;
		return ;
	}
}

void	move_down(t_cub *cub)
{
	t_player	*temp;
	temp = &cub->player;
	temp->pos.y += VITESSE * cub->player.dir.y * -1;
	temp->pos.x += VITESSE * cub->player.dir.x * -1;
	if (cub->map[(int)temp->pos.y][(int)temp->pos.x] != '0')
	{
		temp->pos.y -= VITESSE * cub->player.dir.y * -1;
		temp->pos.x -= VITESSE * cub->player.dir.x * -1;
		return ;
	}
}
