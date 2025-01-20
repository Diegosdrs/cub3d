/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:04:58 by artberna          #+#    #+#             */
/*   Updated: 2025/01/20 13:12:05 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	check_graphics(t_cub *cub)
{
	int	l;

	if (!cub->nord.path || !cub->sud.path
		|| !cub->est.path || !cub->ouest.path)
	{
		printf("Texture is missing, please check your file!\n");
		return (1);
	}
	l = ft_strlen(cub->nord.path);
	if (ft_strncmp(cub->nord.path + l - 4, ".xpm", 5) != 0 && l > 4)
		return (printf("Sprite path must finish with : \".xpm\"!\n"), 1);
	l = ft_strlen(cub->sud.path);
	if (ft_strncmp(cub->sud.path + l - 4, ".xpm", 5) != 0 && l > 4)
		return (printf("Sprite path must finish with : \".xpm\"!\n"), 1);
	l = ft_strlen(cub->est.path);
	if (ft_strncmp(cub->est.path + l - 4, ".xpm", 5) != 0 && l > 4)
		return (printf("Sprite path must finish with : \".xpm\"!\n"), 1);
	l = ft_strlen(cub->ouest.path);
	if (ft_strncmp(cub->ouest.path + l - 4, ".xpm", 5) != 0 && l > 4)
		return (printf("Sprite path must finish with : \".xpm\"!\n"), 1);
	if (is_openable(cub->nord.path, 1) || is_openable(cub->sud.path, 1)
		|| is_openable(cub->est.path, 1) || is_openable(cub->ouest.path, 1))
		return (1);
	return (0);
}

static int	get_color(char *str, t_color *color, int i)
{
	while (str[i] == ' ')
		i++;
	if (!str[i] || str[i] == ',')
		return (printf("RGB Color empty!\n"), 1);
	color->r = ft_atoi(&str[i]);
	while (str[i] != ',' && str[i])
		i++;
	if (str[i] == ',')
		i++;
	if (!str[i] || str[i] == ',')
		return (printf("RGB Color empty!\n"), 1);
	color->g = ft_atoi(&str[i]);
	while (str[i] != ',' && str[i])
		i++;
	if (str[i] == ',')
		i++;
	if (!str[i] || str[i] == ',')
		return (printf("RGB Color empty!\n"), 1);
	color->b = ft_atoi(&str[i]);
	if (color->r > 255 || color->g > 255 || color->b > 255
		|| color->r < 0 || color->b < 0 || color->b < 0)
		return (printf("RGB Color not in range!\n"), 1);
	return (0);
}

static int	init_color(char *str, t_cub *cub)
{
	if (!ft_strncmp(str, "F", 1))
	{
		if (get_color(str, &cub->floor, 1))
			return (1);
	}
	if (!ft_strncmp(str, "C", 1))
	{
		if (get_color(str, &cub->ceiling, 1))
			return (1);
	}
	return (0);
}

static char	*get_path(char *str)
{
	int		i;
	int		j;
	char	*to_ret;

	to_ret = NULL;
	i = 2;
	j = 0;
	while (str[i] == ' ')
		i++;
	to_ret = ft_strdup_mo(str + i);
	return (to_ret);
}

int	init_graphics(t_cub *cub, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!ft_strncmp(tab[i], "NO", 2) && !cub->nord.path)
			cub->nord.path = get_path(tab[i]);
		else if (!ft_strncmp(tab[i], "SO", 2) && !cub->sud.path)
			cub->sud.path = get_path(tab[i]);
		else if (!ft_strncmp(tab[i], "EA", 2) && !cub->est.path)
			cub->est.path = get_path(tab[i]);
		else if (!ft_strncmp(tab[i], "WE", 2) && !cub->ouest.path)
			cub->ouest.path = get_path(tab[i]);
		else if (!ft_strncmp(tab[i], "F", 1) || !ft_strncmp(tab[i], "C", 1))
		{
			if (init_color(tab[i], cub))
				return (1);
		}
		i++;
	}
	if (check_graphics(cub))
		return (1);
	return (0);
}
