/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:01:41 by dsindres          #+#    #+#             */
/*   Updated: 2025/01/20 10:59:17 by dsindres         ###   ########.fr       */
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

void	move_down(t_cub *cub)
{
	t_player	*temp;
	t_player	temp_2;
	t_vector	pos_before_move;

	temp = &cub->player;
	temp_2 = cub->player;
	pos_before_move = cub->player.pos;
	temp->pos.y += VITESSE * cub->player.dir.y * -1;
	temp->pos.x += VITESSE * cub->player.dir.x * -1;
	temp_2.pos.y += VITESSE * cub->player.dir.y * -1.1;
	temp_2.pos.x += VITESSE * cub->player.dir.x * -1.1;
	if ((int)pos_before_move.x == (int)temp_2.pos.x
		&& (int)pos_before_move.y == (int)temp_2.pos.y)
		return ;
	if (passage(cub, temp_2.pos.y, temp_2.pos.x, 2) == 1)
	{
		temp->pos.y -= VITESSE * cub->player.dir.y * -1;
		temp->pos.x -= VITESSE * cub->player.dir.x * -1;
		return ;
	}
}

void	move_up(t_cub *cub)
{
	t_player	*temp;
	t_player	temp_2;
	t_vector	pos_before_move;

	temp = &cub->player;
	temp_2 = cub->player;
	pos_before_move = cub->player.pos;
	temp->pos.y += VITESSE * cub->player.dir.y * 1;
	temp->pos.x += VITESSE * cub->player.dir.x * 1;
	temp_2.pos.y += VITESSE * cub->player.dir.y * 1.1;
	temp_2.pos.x += VITESSE * cub->player.dir.x * 1.1;
	if ((int)pos_before_move.x == (int)temp_2.pos.x
		&& (int)pos_before_move.y == (int)temp_2.pos.y)
		return ;
	if (passage(cub, temp_2.pos.y, temp_2.pos.x, 1) == 1)
	{
		temp->pos.y -= VITESSE * cub->player.dir.y * 1;
		temp->pos.x -= VITESSE * cub->player.dir.x * 1;
		return ;
	}
}

int	passage(t_cub *cub, double a, double b, int dir)
{
	int	y;
	int	x;

	y = (int)a;
	x = (int)b;
	if (dir == NORD)
		return (verif_passage_nord(cub, y, x));
	else if (dir == SUD)
		return (verif_passage_sud(cub, y, x));
	else if (dir == EST)
		return (verif_passage_est(cub, y, x));
	else
		return (verif_passage_ouest(cub, y, x));
}
