/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_raycast_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:10:55 by dsindres          #+#    #+#             */
/*   Updated: 2024/12/16 14:14:31 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->frame.addr + (y * cub->frame.len + x \
		* (cub->frame.bitpp / 8));
	*(unsigned int *)dst = color;
}

static int	obtain_color_pixel(t_text *img, int point_x, int point_y)
{
	return (*(int *)(img->addr + (point_y * img->len + point_x * \
					(img->bitpp / 8))));
}

int	obtain_color(t_cub *cub)
{
	int	x;
	int	y;

	x = cub->player.text_x;
	y = cub->player.text_y;
	if (cub->player.hit_side)
	{
		if (cub->player.pos.y > cub->player.map_square.y)
			return (obtain_color_pixel(&cub->nord, x, y));
		else
			return (obtain_color_pixel(&cub->sud, x, y));
	}
	else
	{
		if (cub->player.pos.x < cub->player.map_square.x)
			return (obtain_color_pixel(&cub->est, x, y));
		else
			return (obtain_color_pixel(&cub->ouest, x, y));
	}
}
