/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 04:01:01 by cocheong          #+#    #+#             */
/*   Updated: 2023/09/30 00:49:34 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(t_prg *prg)
{
	int	i;

	i = 0;
	while (prg->map.map[0][i])
	{
		if (prg->map.map[0][i] != '1' ||
			prg->map.map[prg->map.size.y - 1][i] != 0)
			error_exit("Map not properly surrounded by wall");
		i++;
	}
}

void	check_first_last(char *str)
{
	if (str[0] != '1' || str[ft_strlen(str) - 2] != '1')
		error_exit("Map not properly surrounded by wall");
}

char	*check_line(t_prg *prg, char *str, char *map_str, int fd)
{
	while (str != NULL)
	{
		map_str = ft_strjoinfree(map_str, str);
		prg->map.size.y++;
		free(str);
		str = get_next_line(fd);
		if (str != NULL)
		{
			check_first_last(str);
			if (prg->map.size.x != (int)ft_strlen(str) - 1)
				error_exit("Map is not rectangular");
		}
	}
	return (map_str);
}

void	check_each_line(t_prg *prg, char *path)
{
	char	*str;
	int		fd;
	char	*map_str;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_exit("Fail to open file");
	str = get_next_line(fd);
	if (!str)
		error_exit("Empty map");
	prg->map.size.x = ft_strlen(str) - 1;
	map_str = ft_calloc(1, sizeof(char *));
	map_str = check_line(prg, str, map_str, fd);
	prg->map.map = ft_split(map_str, '\n');
	free(map_str);
}

void	check_map(t_prg *prg, int ac, char **av)
{
	if (ac != 2)
		error_exit("No map to map");
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".ber", 4) != 0)
		error_exit("Invalid map extension");
	check_each_line(prg, av[1]);
	get_data(prg);
	check_valid_path(prg);
}
