/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 06:14:05 by cocheong          #+#    #+#             */
/*   Updated: 2023/09/26 06:14:05 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_if_exist(t_prg *prg)
{
	if (prg->map.max_col == 0)
		exit_fail("No collectible in the map");
	if (prg->ply.pos.x == -1 || prg->ply.pos.y == -1)
		exit_fail("No player in the map");
	if (prg->map.exit_pos.x == -1 || prg->map.exit_pos.y == -1)
		exit_fail("No exit in the map");
}

void	check_and_set(t_vec *pos, int x, int y, char c)
{
	if (pos->x != -1 || pos->y != -1)
	{
		if (c == 'P')
			exit_fail("More than one player in the map");
		if (c == 'E')
			exit_fail("More than one exit in the map");
	}
	pos->x = x;
	pos->y = y;
}

void	get_data(t_prg *prg)
{
	int	x;
	int	y;

	y = -1;
	while (++y < prg->map.size.y)
	{
		x = -1;
		while (prg->map.map[++x][y] != '\0')
		{
			if (prg->map.map[x][y] != '0' && prg->map.map[x][y] != '1'
				&& prg->map.map[x][y] != 'C' && prg->map.map[x][y] != 'E'
				&& prg->map.map[x][y] != 'P' && prg->map.map[x][y] != 'N')
				exit_fail("Invalid character found");
			if (prg->map.map[x][y] == 'C')
				prg->map.max_col++;
			if (prg->map.map[x][y] == 'P')
				check_and_set(&prg->ply.pos, x, y, 'P');
			if (prg->map.map[x][y] == 'E')
				check_and_set(&prg->map.exit_pos, x, y, 'E');
			if (prg->map.map[x][y] == 'N')
				check_and_set(&prg->emy, x, , 'N');
		}
	}
	check_if_exist(prg);
}
