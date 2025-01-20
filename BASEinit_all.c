/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BASEinit_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:16:29 by dsindres          #+#    #+#             */
/*   Updated: 2025/01/16 10:29:22 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_all(t_cub *cub)
{
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

    // A coder par Arthur
    // init_map(cub);
	// init_img(cub);
	// init_player(cub);
	// init_color(cub);
}

// void	init_player(t_cub *cub)
// {
// 	// A Arthur d'init tous ca, il y a deja les
// 	// valeurs a rentrer suivant l'orientation du player

// 	char	face;
// 	face = 'N';

// 	// position du joueur
// 	cub->player.pos.x = 3;
// 	cub->player.pos.y = 3;

// 	// orientation
// 	if (face == 'N')
// 	{
// 		cub->player.dir.x = 0;
// 		cub->player.dir.y = -1;
// 		cub->player.cam.x = 0.66;
// 		cub->player.cam.y = 0;
// 	}
// 	else if (face == 'S')
// 	{
// 		cub->player.dir.x = 0;
// 		cub->player.dir.y = 1;
// 		cub->player.cam.x = -0.66;
// 		cub->player.cam.y = 0;
// 	}
// 	else if (face == 'E')
// 	{
// 		cub->player.dir.x = 1;
// 		cub->player.dir.y = 0;
// 		cub->player.cam.x = 0;
// 		cub->player.cam.y = 0.66;
// 	}
// 	else if (face == 'O')
// 	{
// 		cub->player.dir.x = -1;
// 		cub->player.dir.y = 0;
// 		cub->player.cam.x = 0;
// 		cub->player.cam.y = -0.66;
// 	}
// }

void	init_img(t_cub *cub)
{
	cub->nord.path = "./img/nord.xpm";
	cub->sud.path = "./img/sud.xpm";
	cub->est.path = "./img/est.xpm";
	cub->ouest.path = "./img/ouest.xpm";
	cub->nord.ptr = NULL;
	cub->sud.ptr = NULL;
	cub->est.ptr = NULL;
	cub->ouest.ptr = NULL;
	cub->frame.ptr = NULL;
	cub->minimap.ptr = NULL;
}

// void	init_map(t_cub *cub)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	cub->map_height = 14;
// 	cub->map_width = 25;
// 	cub->map = malloc(sizeof(char *) * (cub->map_height + 1));
//     char* worldMap[] = {
//         "1111111111111111111111111",
//         "1111111100000001111111111",
//         "1000011100000001111111111",
//         "1000011110000000111111111",
//         "1110011111110000000000001",
//         "1000011100000001000000001",
//         "1000011100000011000111111",
//         "1000011100000001000000001",
//         "1000011100000011000000001",
//         "1000011100000000000001001",
//         "1000011111100000000111001",
//         "1000011100110000000101111",
//         "1000000000000000000101111",
//         "1111111111111111111111111"
//     };
// 	while (i < cub->map_height)
// 	{
// 		cub->map[i] = malloc(sizeof(char) * (cub->map_width + 1));
// 		while (j < cub->map_width)
// 		{
// 			cub->map[i][j] = worldMap[i][j];
// 			j++;
// 		}
// 		cub->map[i][j] = '\0';
// 		j = 0;
// 		i++;
// 	}
// 	cub->map[i] = NULL;
// }

// void	init_color(t_cub *cub)
// {
// 	// suivant ce que tu trouveras dans le fichier a parser
// 	cub->ceiling.r = 28;
// 	cub->ceiling.g = 15;
// 	cub->ceiling.b = 10;

// 	cub->floor.r = 0;
// 	cub->floor.g = 0;
// 	cub->floor.b = 26;
// }

// void	print_double(char **tab)
// {
// 	int i;

// 	i = 0;
// 	while(tab[i])
// 	{
// 		printf("%s", tab[i]);
// 		printf("\n");
// 		i++;
// 	}
// }
