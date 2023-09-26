/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:58:08 by cocheong          #+#    #+#             */
/*   Updated: 2023/08/09 15:58:08 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_window(t_prg *prg)
{
	prg->win.win = mlx_new_window(prg->mlx, prg->map.size.x * PLY_MVSPEED,
			prg->map.size.y * PLY_MVSPEED, "so_long");
	prg->win.fps = 0;
}

int	main(int ac, char **av)
{
	t_prg	prg;

	init_game(&prg);
	check_map(&prg, ac, av);
	init_window(&prg);
	loop_game(&prg);
	return (exit_success());
}
