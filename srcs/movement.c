/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 05:32:30 by cocheong          #+#    #+#             */
/*   Updated: 2023/09/30 00:57:22 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	col(t_prg *prg, int x, int y)
{
	if (prg->map.map[x][y] == '1')
		return (1);
	return (0);
}

int	user_input_player(int keycode, t_prg *prg)
{
	if (keycode == KEY_ESC)
		exit_success();
	else if (keycode == KEY_W && !col(prg, prg->ply.pos.x, prg->ply.pos.y - 1))
		prg->ply.pos.y--;
	else if (keycode == KEY_S && !col(prg, prg->ply.pos.x, prg->ply.pos.y + 1))
		prg->ply.pos.y++;
	else if (keycode == KEY_A && !col(prg, prg->ply.pos.x - 1, prg->ply.pos.y))
		prg->ply.pos.x--;
	else if (keycode == KEY_D && !col(prg, prg->ply.pos.x + 1, prg->ply.pos.y))
		prg->ply.pos.x++;
	else
		return (0);
	prg->ply.steps++;
	ft_printf("Movement count: %d\n", prg->ply.steps);
	return (0);
}

void	user_input_enemy(int keycode, t_prg *prg)
{
	if (keycode == KEY_W && !col(prg, prg->emy.x, prg->emy.y - 1))
		prg->emy.y--;
	else if (keycode == KEY_S && !col(prg, prg->emy.x, prg->emy.y + 1))
		prg->emy.y++;
	else if (keycode == KEY_A && !col(prg, prg->emy.x - 1, prg->emy.y))
		prg->emy.x--;
	else if (keycode == KEY_D && !col(prg, prg->emy.x + 1, prg->emy.y))
		prg->emy.x++;
}

int	user_input(int keycode, t_prg *prg)
{
	if (check_enemy(prg))
	{
		user_input_player(keycode, prg);
		user_input_enemy(keycode, prg);
		if (prg->ply.pos.y == prg->emy.y && prg->ply.pos.x == prg->emy.x)
		{
			ft_printf("Game Over\n");
			exit(0);
		}
	}
	else
		user_input_player(keycode, prg);
	return (0);
}
