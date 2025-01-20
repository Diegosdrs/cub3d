/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_verif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:16:12 by dsindres          #+#    #+#             */
/*   Updated: 2025/01/20 10:27:50 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	verif_passage_nord(t_cub *cub, int y, int x)
{
	if (cub->player.dir.y < 0 && cub->player.dir.x > 0)
		return (verif_passage_2_1(cub, y, x));
	else if (cub->player.dir.y > 0 && cub->player.dir.x > 0)
		return (verif_passage_2_2(cub, y, x));
	else if (cub->player.dir.y > 0 && cub->player.dir.x < 0)
		return (verif_passage_2_3(cub, y, x));
	else if (cub->player.dir.y < 0 && cub->player.dir.x < 0)
		return (verif_passage_2_4(cub, y, x));
	else
	{
		if (cub->map[y][x] != '0')
			return (1);
		return (0);
	}
}

int	verif_passage_sud(t_cub *cub, int y, int x)
{
	if (cub->player.dir.y < 0 && cub->player.dir.x > 0)
		return (verif_passage_2_3(cub, y, x));
	else if (cub->player.dir.y > 0 && cub->player.dir.x > 0)
		return (verif_passage_2_4(cub, y, x));
	else if (cub->player.dir.y > 0 && cub->player.dir.x < 0)
		return (verif_passage_2_1(cub, y, x));
	else if (cub->player.dir.y < 0 && cub->player.dir.x < 0)
		return (verif_passage_2_2(cub, y, x));
	else
	{
		if (cub->map[y][x] != '0')
			return (1);
		return (0);
	}
}

int	verif_passage_est(t_cub *cub, int y, int x)
{
	if (cub->player.dir.y < 0 && cub->player.dir.x > 0)
		return (verif_passage_2_4(cub, y, x));
	else if (cub->player.dir.y > 0 && cub->player.dir.x > 0)
		return (verif_passage_2_1(cub, y, x));
	else if (cub->player.dir.y > 0 && cub->player.dir.x < 0)
		return (verif_passage_2_2(cub, y, x));
	else if (cub->player.dir.y < 0 && cub->player.dir.x < 0)
		return (verif_passage_2_3(cub, y, x));
	else
	{
		if (cub->map[y][x] != '0')
			return (1);
		return (0);
	}
}

int	verif_passage_ouest(t_cub *cub, int y, int x)
{
	if (cub->player.dir.y < 0 && cub->player.dir.x > 0)
		return (verif_passage_2_2(cub, y, x));
	else if (cub->player.dir.y > 0 && cub->player.dir.x > 0)
		return (verif_passage_2_3(cub, y, x));
	else if (cub->player.dir.y > 0 && cub->player.dir.x < 0)
		return (verif_passage_2_4(cub, y, x));
	else if (cub->player.dir.y < 0 && cub->player.dir.x < 0)
		return (verif_passage_2_1(cub, y, x));
	else
	{
		if (cub->map[y][x] != '0')
			return (1);
		return (0);
	}
}
