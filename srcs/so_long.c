/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:58:08 by cocheong          #+#    #+#             */
/*   Updated: 2023/09/30 00:52:49 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_prg	prg;

	init_game(&prg);
	check_map(&prg, ac, av);
	init_window(&prg);
	loop_game(&prg);
	return (exit_success());
}
