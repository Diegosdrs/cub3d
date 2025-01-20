/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:53:34 by dsindres          #+#    #+#             */
/*   Updated: 2025/01/16 17:23:57 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_controler(t_cub *cub)
{
	cub->mlx_co = mlx_init();
	if (cub->mlx_co == NULL)
	{
		free_map(cub);
		printf("Mlx connection failed\n");
		exit(EXIT_FAILURE);
	}
	init_textures(cub, SIZTEXT);
	display_window(cub);
	mlx_loop_hook(cub->mlx_co, render_image, cub);
	mlx_hook(cub->window, MotionNotify, PointerMotionMask, \
	mouse_movement, cub);
	mlx_hook(cub->window, 2, 1L << 0, movement_key, cub);
	mlx_hook(cub->window, 3, 1L << 1, movement_key_2, cub);
	mlx_hook(cub->window, 17, 0, close_window, cub);
	mlx_loop(cub->mlx_co);
	return (0);
}

int	display_window(t_cub *cub)
{
	cub->window = mlx_new_window(cub->mlx_co, SCREENW,
			SCREENH, "My Cub3D !");
	if (cub->window == NULL)
	{
		free_map(cub);
		printf("Mlx display window failed\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	init_textures(t_cub *cub, int s)
{
	int	sq_siz;

	sq_siz = SIZTEXT * 0.1;
	cub->nord.ptr = mlx_xpm_file_to_image(cub->mlx_co, cub->nord.path, &s, &s);
	cub->sud.ptr = mlx_xpm_file_to_image(cub->mlx_co, cub->sud.path, &s, &s);
	cub->est.ptr = mlx_xpm_file_to_image(cub->mlx_co, cub->est.path, &s, &s);
	cub->ouest.ptr = mlx_xpm_file_to_image(cub->mlx_co, \
	cub->ouest.path, &s, &s);
	cub->minimap.ptr = mlx_new_image(cub->mlx_co, cub->map_width \
	* sq_siz, cub->map_height * sq_siz);
	if (cub->nord.ptr == NULL
		|| cub->sud.ptr == NULL || cub->est.ptr == NULL
		|| cub->ouest.ptr == NULL || cub->minimap.ptr == NULL)
		free_all(cub, 0);
	cub->nord.addr = mlx_get_data_addr \
	(cub->nord.ptr, &cub->nord.bitpp, &cub->nord.len, &cub->nord.endian);
	cub->sud.addr = mlx_get_data_addr \
	(cub->sud.ptr, &cub->sud.bitpp, &cub->sud.len, &cub->sud.endian);
	cub->est.addr = mlx_get_data_addr \
	(cub->est.ptr, &cub->est.bitpp, &cub->est.len, &cub->est.endian);
	cub->ouest.addr = mlx_get_data_addr \
	(cub->ouest.ptr, &cub->ouest.bitpp, &cub->ouest.len, &cub->ouest.endian);
	cub->minimap.addr = mlx_get_data_addr \
	(cub->minimap.ptr, &cub->minimap.bitpp, \
	&cub->minimap.len, &cub->minimap.endian);
}

void	init_frame(t_cub *cub)
{
	if (cub->frame.ptr)
		mlx_destroy_image(cub->mlx_co, cub->frame.ptr);
	cub->frame.ptr = mlx_new_image(cub->mlx_co, \
	SCREENW, SCREENH);
	cub->frame.addr = mlx_get_data_addr(cub->frame.ptr, \
	&cub->frame.bitpp, &cub->frame.len, &cub->frame.endian);
}

void	render_floor_and_ceiling(t_cub *cub, int value)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (value == 0)
		y = SCREENH / 2;
	while (y < SCREENH)
	{
		x = 0;
		while (x < SCREENW)
		{
			if (value == 0)
				my_mlx_pixel_put(cub, x, y, convert_color(cub, 0));
			else
				my_mlx_pixel_put(cub, x, y, convert_color(cub, 1));
			x++;
		}
		y++;
	}
}
