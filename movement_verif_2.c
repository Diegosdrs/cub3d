/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_verif_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:19:30 by dsindres          #+#    #+#             */
/*   Updated: 2025/01/20 10:57:13 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	verif_passage_2_1(t_cub *cub, int y, int x)
{
	if (cub->map[y][x] != '0' || (cub->map[y][x] == '0'
		&& cub->map[y + 1][x] == '1' && cub->map[y][x - 1] == '1'))
		return (1);
	return (0);
}

int	verif_passage_2_2(t_cub *cub, int y, int x)
{
	if (cub->map[y][x] != '0' || (cub->map[y][x] == '0'
		&& cub->map[y - 1][x] == '1' && cub->map[y][x - 1] == '1'))
		return (1);
	return (0);
}

int	verif_passage_2_3(t_cub *cub, int y, int x)
{
	if (cub->map[y][x] != '0' || (cub->map[y][x] == '0'
		&& cub->map[y - 1][x] == '1' && cub->map[y][x + 1] == '1'))
		return (1);
	return (0);
}

int	verif_passage_2_4(t_cub *cub, int y, int x)
{
	if (cub->map[y][x] != '0' || (cub->map[y][x] == '0'
		&& cub->map[y + 1][x] == '1' && cub->map[y][x + 1] == '1'))
		return (1);
	return (0);
}
