/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:26:15 by dsindres          #+#    #+#             */
/*   Updated: 2025/01/15 13:28:45 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_cub *cub)
{
	free_all(cub, 1);
	printf ("Goodbye !\n");
	return (0);
}

void	free_all(t_cub *cub, int success)
{
	free_map(cub);
	if (cub->nord.ptr != NULL)
		mlx_destroy_image(cub->mlx_co, cub->nord.ptr);
	if (cub->sud.ptr != NULL)
		mlx_destroy_image(cub->mlx_co, cub->sud.ptr);
	if (cub->est.ptr != NULL)
		mlx_destroy_image(cub->mlx_co, cub->est.ptr);
	if (cub->ouest.ptr != NULL)
		mlx_destroy_image(cub->mlx_co, cub->ouest.ptr);
	if (cub->frame.ptr != NULL)
		mlx_destroy_image(cub->mlx_co, cub->frame.ptr);
	if (cub->minimap.ptr != NULL)
		mlx_destroy_image(cub->mlx_co, cub->minimap.ptr);
	mlx_destroy_window(cub->mlx_co, cub->window);
	mlx_destroy_display(cub->mlx_co);
	free(cub->mlx_co);
	if (success)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}

void	free_map(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->map_height)
	{
		free(cub->map[i]);
		i++;
	}
	free(cub->map);
}
