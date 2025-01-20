/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:33:29 by dsindres          #+#    #+#             */
/*   Updated: 2025/01/16 17:18:11 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**extract_files(char *str)
{
	int		fd;
	char	*out;
	char	*tmp;
	char	*line;
	char	**d_tab;

	out = NULL;
	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!out)
			out = line;
		else
		{
			tmp = ft_strjoin(out, line);
			out = tmp;
			free(line);
		}
		line = get_next_line(fd);
	}
	if (!out)
		return (NULL);
	d_tab = ft_split(out, '\n');
	return (free(out), close(fd), d_tab);
}

static int	init_all(t_cub *cub, char *str)
{
	char	**to_do;

	ft_bzero(cub, sizeof(t_cub));
	to_do = extract_files(str);
	if (!to_do)
		return (printf("Empty file, please try again!\n"), 1);
	if (check_all(to_do))
		return (free_double(to_do), 1);
	if (init_graphics(cub, to_do))
		return (free_double(to_do), 1);
	if (init_map(cub, to_do))
		return (free_double(to_do), 1);
	if (is_playable(cub, to_do))
		return (free_double(to_do), 1);
	free_double(to_do);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (check_input(ac, av) == 0)
	{
		if (init_all(&cub, av[1]))
			return (1);
		game_controler(&cub);
		free(cub.nord.path);
		free(cub.sud.path);
		free(cub.est.path);
		free(cub.ouest.path);
		free_double(cub.map);
		return (0);
	}
	return (1);
}
