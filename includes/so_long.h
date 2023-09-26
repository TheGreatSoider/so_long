/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:01:53 by cocheong          #+#    #+#             */
/*   Updated: 2023/08/17 17:01:53 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
// # include "../libft/get_next_line.h"
// # include "../libft/ft_printf.h"
# include <mlx.h>

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_LEFT		123
# define KEY_RIGHT		124

# define MLX_PRESS 		2	
# define MLX_MASK 		0
# define EXIT_PRESS		17
# define EXIT_MASK		0

# define PLY_MVSPEED	64
# define FPS			50
# define WHITE			0xffffff

typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

typedef struct s_win
{
	void	*win;
	t_vec	size;
	int		fps;
}	t_win;

typedef struct s_img
{
	void	*img;
	t_vec	size;
}	t_img;

typedef struct s_map
{
	t_img	c_img;
	t_img	d_img;
	t_img	e_img;
	t_img	f_img;
	t_img	p_img;
	t_img	w_img;
	t_vec	size;
	t_vec	exit_pos;
	char	**map;
	int		max_col;
}	t_map;

typedef struct s_ply
{
	int		steps;
	int		col;
	t_vec	pos;
}	t_ply;

typedef struct s_prg
{
	void	*mlx;
	t_win	win;
	t_map	map;
	t_ply	ply;
	t_vec	emy;
}	t_prg;

void	init_game(t_prg *prg);
void	init_sprites(t_prg *prg);
void	init_mlx(t_prg *prg);
void	loop_game(t_prg *prg);
int		user_input(int keycode, t_prg *prg);
void	check_map(t_prg *prg, int ac, char **av);
void	check_valid_path(t_prg *prg);
void	get_data(t_prg *prg);
void	check_each_line(t_prg *prg, char *path);
void	display_image(t_prg *prg);
int		check_enemy(t_prg *prg);
void	check_state(t_prg *prg);
int		exit_success(void);
int		error_exit(char *error);
int		victory(void);

#endif