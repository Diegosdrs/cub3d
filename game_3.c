/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:24:47 by dsindres          #+#    #+#             */
/*   Updated: 2025/01/16 17:23:57 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

unsigned int	rgb_to_hex(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	render_minimap(t_cub *cub)
{
	int	map_x;
	int	map_y;
	int	color;

	map_y = 0;
	while (map_y < cub->map_height)
	{
		map_x = 0;
		while (map_x < cub->map_width)
		{
			if (cub->map[map_y][map_x] == '1')
				color = 0x000000;
			else if (cub->map[map_y][map_x] == '0')
				color = 0xFFFFFF;
			draw_square(cub, map_x, map_y, color);
			map_x++;
		}
		map_y++;
	}
	draw_square(cub, cub->player.pos.x, cub->player.pos.y, 0xFF00FF);
}

void	draw_square(t_cub *cub, int x, int y, int color)
{
	int	square_size;
	int	i;
	int	j;

	i = 0;
	square_size = SIZTEXT * 0.1;
	while (i < square_size)
	{
		j = 0;
		while (j < square_size)
		{
			mlx_pixel_put(cub->mlx_co, cub->window, \
				(square_size * x) + j, (square_size * y) + i, color);
			j++;
		}
		i++;
	}
}
