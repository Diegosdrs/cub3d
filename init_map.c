/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:04:48 by artberna          #+#    #+#             */
/*   Updated: 2025/01/15 13:00:57 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	set_position(t_cub *cub, char **tab)
{
	int	i;
	int	j;

	i = 6;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'N')
				return (cub->orientation = 'N', init_player(cub, i, j), 0);
			if (tab[i][j] == 'S')
				return (cub->orientation = 'S', init_player(cub, i, j), 0);
			if (tab[i][j] == 'E')
				return (cub->orientation = 'E', init_player(cub, i, j), 0);
			if (tab[i][j] == 'W')
				return (cub->orientation = 'W', init_player(cub, i, j), 0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_position(t_cub *cub, char **tab)
{
	int	i;
	int	j;
	int	count;

	i = 6;
	count = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'N' || tab[i][j] == 'S'
				|| tab[i][j] == 'E' || tab[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count == 1)
		return (set_position(cub, tab), 0);
	if (count == 0)
		printf("Missing player position, please check your file!\n");
	if (count > 1)
		printf("Too many player position, please check your file!\n");
	return (1);
}

static int	check_carac(t_cub *cub, char **tab)
{
	int	i;
	int	j;
	int	length;

	i = 6;
	length = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!ft_strchr(IS_MAP, tab[i][j]))
				return (1);
			j++;
		}
		if (j > length)
			length = j;
		i++;
	}
	cub->map_height = i - 6;
	cub->map_width = length;
	return (0);
}

int	init_map(t_cub *cub, char **tab)
{
	if (check_carac(cub, tab))
		return (printf("Caracters not allowed, please check your map!\n"), 1);
	if (check_position(cub, tab))
		return (1);
	return (0);
}
