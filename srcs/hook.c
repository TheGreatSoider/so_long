/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 05:25:12 by cocheong          #+#    #+#             */
/*   Updated: 2023/09/26 05:25:12 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	user_update(t_prg *prg)
{
	prg->win.fps++;
	mlx_clear_window(prg->mlx, prg->win.win);
	display_image(prg);
	if (prg->win.fps > FPS)
		prg->win.fps = 0;
	check_status(prg);
}

int	windowexit(void)
{
	ft_printf("Thanks for playing\n");
	exit(0);
	return (0);
}

void	loop_game(t_prg *prg)
{
	mlx_hook(prg->win.win, EXIT_PRESS, EXIT_MASK, &windowexit, prg);
	mlx_hook(prg->win.win, MLX_PRESS, MLX_MASK, &user_input, prg);
	mlx_loop_hook(prg->mlx, &user_update, prg);
	mlx_loop(prg->mlx);
}
