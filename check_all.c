/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:26:37 by artberna          #+#    #+#             */
/*   Updated: 2025/01/16 17:08:16 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_order(char **tab)
{
	int	i;
	int	count;
	int	in;

	i = 0;
	count = 6;
	in = 0;
	while (tab[i])
	{
		if (!ft_strncmp(tab[i], "0", 1) || !ft_strncmp(tab[i], "1", 1)
			|| !ft_strncmp(tab[i], " ", 1))
			in = 1;
		if (!in && (!ft_strncmp(tab[i], "NO", 2) || !ft_strncmp(tab[i], "SO", 2)
				|| !ft_strncmp(tab[i], "EA", 2) || !ft_strncmp(tab[i], "WE", 2)
				|| !ft_strncmp(tab[i], "C", 1) || !ft_strncmp(tab[i], "F", 1)))
			count--;
		i++;
	}
	if (count)
		return (1);
	return (0);
}

static int	check_six(char **tab)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (!ft_strncmp(tab[i], "NO", 2) || !ft_strncmp(tab[i], "SO", 2)
			|| !ft_strncmp(tab[i], "EA", 2) || !ft_strncmp(tab[i], "WE", 2)
			|| !ft_strncmp(tab[i], "C", 1) || !ft_strncmp(tab[i], "F", 1))
			count++;
		i++;
	}
	if (count == 6)
		return (0);
	return (1);
}

static int	check_begin(char **tab)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (ft_strncmp(tab[i], "NO", 2) && ft_strncmp(tab[i], "SO", 2)
			&& ft_strncmp(tab[i], "EA", 2) && ft_strncmp(tab[i], "WE", 2)
			&& ft_strncmp(tab[i], "C", 1) && ft_strncmp(tab[i], "F", 1)
			&& tab[i][0] != ' ' && tab[i][0] != '1' && tab[i][0] != '0')
			return (1);
		i++;
	}
	return (0);
}

int	check_all(char **tab)
{
	if (check_six(tab))
		return (printf("Number of texture is wrong, please check your file!\n") \
		, 1);
	if (check_order(tab))
		return (printf("Texture not in order, please check your file!\n"), 1);
	if (check_begin(tab))
		return (printf("Error with the format, please check your file!\n"), 1);
	return (0);
}

int	check_input(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (printf("Input must be : \".exe .cub\"!\n"), 1);
	i = ft_strlen(av[1]);
	if (ft_strncmp(av[1] + (i - 4), ".cub", 5) != 0
		&& ft_strlen(av[1]) > 4)
		return (printf("Second argument must finish with : \".cub\"!\n"), 1);
	if (is_openable(av[1], 0))
		return (printf("File cannot be opened!\n"), 1);
	else
		return (0);
}
