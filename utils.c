/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:48:26 by artberna          #+#    #+#             */
/*   Updated: 2025/01/15 15:59:17 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	is_openable(char *str, int option)
{
	int		fd;
	char	*buff;
	ssize_t	bytes_read;

	bytes_read = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (1);
	if (option == 1)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (printf("Memory allocation failed!\n"), close(fd), 1);
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (printf("Cannot read xpm, please check your file!\n"), \
			close(fd), free(buff), 1);
		buff[bytes_read] = '\0';
		if (ft_strncmp(buff, "/* XPM */", 9))
			return (printf("Invalid xpm, please check your file!\n"), \
			close(fd), free(buff), 1);
		free(buff);
	}
	return (close(fd), 0);
}

void	print_double(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

void	free_double_index(char **s, int index)
{
	if (!s)
		return ;
	while (index >= 0)
	{
		free(s[index]);
		index--;
	}
	free(s);
}

void	free_double(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*ft_strdup_mo(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	while (s[i] != ' ' && s[i])
		i++;
	dup = malloc(sizeof(char) * i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i] != ' ' && s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
