/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:24:47 by dsindres          #+#    #+#             */
/*   Updated: 2025/01/06 11:25:48 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

unsigned int rgb_to_hex(int r, int g, int b)
{
	return (r << 16) | (g << 8) | b;
}

void	render_minimap(t_cub *cub)
{
	int	map_x;
	int	map_y;
	int	square_size;
	int	color;

	square_size = sizetext * 0.1;
	map_y = 0;
	while(map_y < cub->map_height)
	{
		map_x = 0;
		while(map_x < cub->map_width)
		{
			if (cub->map[map_y][map_x] == '1')
				color = 0xFFFFFF;
			else if (cub->map[map_y][map_x] == '0')
				color = 0x000000;
			draw_square(cub, map_x * square_size, map_y * square_size, square_size, color);
			map_x++;
		}
		map_y++;
	}
	draw_square(cub, cub->player.pos.x * square_size, cub->player.pos.y * square_size, square_size, color);
}

void	draw_square(t_cub *cub, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			mlx_pixel_put(cub->mlx_connection, cub->window, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
