/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readlayout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:58:00 by cocheong          #+#    #+#             */
/*   Updated: 2023/08/09 15:58:00 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display(t_prg *prg)
{
	int	x;
	int	y;

	y = 0;
	while (y < prg->map.size.y)
	{
		x = 0;
		while (x < prg->map.size.y)
		{
			mlx_put_image_to_window(prg->mlx, prg->win.win, prg->map.f_img.img,
				(x * PLY_MVSPEED), (y * PLY_MVSPEED));
			if (prg->map.map[x][y] == '1')
				mlx_put_image_to_window(prg->mlx, prg->win.win,
					prg->map.w_img.img, (x * PLY_MVSPEED), (y * PLY_MVSPEED));
			if (prg->map.map[x][y] == 'E')
				mlx_put_image_to_window(prg->mlx, prg->win.win,
					prg->map.d_img.img, (x * PLY_MVSPEED), (y * PLY_MVSPEED));
			if (prg->map.map[x][y] == 'C')
				mlx_put_image_to_window(prg->mlx, prg->win.win,
					prg->map.c_img.img, (x * PLY_MVSPEED), (y * PLY_MVSPEED));
		}
	}
}

void	player_ani(t_prg *prg)
{
	if (prg->win.fps < FPS / 2)
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->map.p_img.img,
			prg->ply.pos.x * PLY_MVSPEED, prg->ply.pos.y * PLY_MVSPEED - 1);
	else
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->map.p_img.img,
			prg->ply.pos.x * PLY_MVSPEED, prg->ply.pos.y * PLY_MVSPEED + 1);
}

void	enemy_ani(t_prg *prg)
{
	if (prg->win.fps < FPS / 2)
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->map.e_img.img,
			prg->emy.x * PLY_MVSPEED, prg->emy.y * PLY_MVSPEED - 1);
	else
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->map.e_img.img,
			prg->emy.x * PLY_MVSPEED, prg->emy.y * PLY_MVSPEED + 1);
}

int	check_enemy(t_prg *prg)
{
	int	k;
	int	j;

	j = 0;
	while (j < prg->map.size.y)
	{
		k = 0;
		while (k < prg->map.size.x)
		{
			if (prg->map.map[j][k] == 'N')
				return (1);
			k++;
		}
		j++;
	}
	return (0);
}

void	display_image(t_prg *prg)
{
	sl_map_projection(prg);
	sl_player_ani(prg);
	if (sl_check_enemy(prg))
		sl_enemy_ani(prg);
	sl_on_screen_steps(prg);
}
