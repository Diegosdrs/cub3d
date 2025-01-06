/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:26:15 by dsindres          #+#    #+#             */
/*   Updated: 2024/12/17 15:32:26 by dsindres         ###   ########.fr       */
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
		mlx_destroy_image(cub->mlx_connection, cub->nord.ptr);
	if (cub->sud.ptr != NULL)
		mlx_destroy_image(cub->mlx_connection, cub->sud.ptr);
	if (cub->est.ptr != NULL)
		mlx_destroy_image(cub->mlx_connection, cub->est.ptr);
	if (cub->ouest.ptr != NULL)
		mlx_destroy_image(cub->mlx_connection, cub->ouest.ptr);
	if (cub->frame.ptr != NULL)
		mlx_destroy_image(cub->mlx_connection, cub->frame.ptr);
	if (cub->minimap.ptr != NULL)
		mlx_destroy_image(cub->mlx_connection, cub->minimap.ptr);
	mlx_destroy_window(cub->mlx_connection, cub->window);
	mlx_destroy_display(cub->mlx_connection);
	free(cub->mlx_connection);
	if(success)
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
