/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:33:29 by dsindres          #+#    #+#             */
/*   Updated: 2025/01/16 10:36:24 by artberna         ###   ########.fr       */
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

void	init_all(t_cub *cub, char *str)
{
	char	**to_do;

	cub->nord.ptr = NULL;
	cub->sud.ptr = NULL;
	cub->est.ptr = NULL;
	cub->ouest.ptr = NULL;
	cub->frame.ptr = NULL;
	cub->minimap.ptr = NULL;
	cub->window = NULL;
	cub->pixel = 0;
	cub->player.mouse = 0;
	cub->escape = 0;
	cub->w = 0;
	cub->a = 0;
	cub->s = 0;
	cub->d = 0;
	cub->left = 0;
	cub->right = 0;
	ft_bzero(cub, sizeof(t_cub));
	to_do = extract_files(str);
	if (check_all(to_do))
		return (free_double(to_do));
	if (init_graphics(cub, to_do))
		return (free_double(to_do));
	if (init_map(cub, to_do))
		return (free_double(to_do));
	if (is_playable(cub, to_do))
		return (free_double(to_do));
	free_double(to_do);
	printf("INFO : Path NO = %s\n", cub->nord.path); //debug
	printf("INFO : Path SO = %s\n", cub->sud.path); //debug
	printf("INFO : Path EA = %s\n", cub->est.path); //debug
	printf("INFO : Path WE = %s\n", cub->ouest.path); //debug
	printf("INFO : C color = %d, %d ,%d\n", cub->ceiling.r, cub->ceiling.g, cub->ceiling.b); //debug
	printf("INFO : F color = %d, %d ,%d\n", cub->floor.r, cub->floor.g, cub->floor.b); //debug
	printf("INFO : player orientation is %c\n", cub->orientation); // debug
	printf("INFO : CUB MAP = \n");
	print_double(cub->map);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (check_input(ac, av) == 0)
	{
		init_all(&cub, av[1]);
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
