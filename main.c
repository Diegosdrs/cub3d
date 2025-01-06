/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:33:29 by dsindres          #+#    #+#             */
/*   Updated: 2025/01/06 11:21:56 by dsindres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_cub	cub;

// Init et parsing (a faire par l'autre con)
	init_all(&cub);

// Execution
	game_controler(&cub);

	return (0);
}
