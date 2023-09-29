/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 05:55:27 by cocheong          #+#    #+#             */
/*   Updated: 2023/09/30 00:54:54 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **tab, t_vec size, t_vec cur)
{
	if (cur.y >= 0 && cur.y < size.y && cur.x >= 0 && cur.x < size.x
		&& (tab[cur.y][cur.x] == '0' || tab[cur.y][cur.x] == 'P'
		|| tab[cur.y][cur.x] == 'C' || tab[cur.y][cur.x] == 'E'
		|| tab[cur.y][cur.x] == 'N'))
	{
		tab[cur.y][cur.x] = 'F';
		flood_fill(tab, size, (t_vec){cur.x - 1, cur.y});
		flood_fill(tab, size, (t_vec){cur.x + 1, cur.y});
		flood_fill(tab, size, (t_vec){cur.x, cur.y - 1});
		flood_fill(tab, size, (t_vec){cur.x, cur.y + 1});
	}
}

void	check_valid_path(t_prg *prg)
{
	int		x;
	int		y;
	char	**temp_map;

	temp_map = malloc(sizeof(char *) * prg->map.size.y);
	x = -1;
	while (++x < prg->map.size.y)
		temp_map[x] = ft_strdup(prg->map.map[x]);
	flood_fill(temp_map, prg->map.size, prg->ply.pos);
	y = -1;
	while (++y < prg->map.size.y)
	{
		x = -1;
		while (++x < prg->map.size.x)
			if (ft_strchr("CEPN", temp_map[x][y]))
				error_exit("No valid path");
	}
	y = -1;
	while (++y < prg->map.size.y)
		free(temp_map[y]);
	free(temp_map);
}
