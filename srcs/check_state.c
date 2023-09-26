/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 06:06:26 by cocheong          #+#    #+#             */
/*   Updated: 2023/09/26 06:06:26 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_state(t_prg *prg)
{
	if (prg->map.map[prg->ply.pos.y][prg->ply.pos.x] == 'C')
	{
		prg->map.map[prg->ply.pos.y][prg->ply.pos.x] = 'F';
		prg->ply.col++;
	}
	if (prg->map.map[prg->ply.pos.y][prg->ply.pos.x] == 'E')
	{
		if (prg->ply.col == prg->map.max_col)
			victory();
	}
}