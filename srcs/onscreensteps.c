/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onscreensteps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:51:54 by cocheong          #+#    #+#             */
/*   Updated: 2023/09/30 00:53:34 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_prg *prg)
{
	prg->win.win = mlx_new_window(prg->mlx, prg->map.size.x * PLY_MVSPEED,
			prg->map.size.y * PLY_MVSPEED, "so_long");
	prg->win.fps = 0;
}

void	onscreensteps(t_prg *prg)
{
	char	*steps;
	char	*str;

	steps = ft_itoa(prg->ply.steps);
	str = ft_strjoin("Movement count: ", steps);
	mlx_string_put(prg->mlx, prg->win.win, 10, 15, WHITE, str);
	free(steps);
	free(str);
}
