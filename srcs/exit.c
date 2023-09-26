/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:20:48 by cocheong          #+#    #+#             */
/*   Updated: 2023/09/24 15:20:48 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error_exit(char *error)
{
	ft_printf("ERROR: %s\n", error);
	exit(1);
	return (1);
}

int	victory(void)
{
	ft_printf("You win!\n");
	exit(0);
	return (0);
}

int	exit_success(void)
{
	ft_printf("Why you close?\n");
	exit(0);
	return (0);
}
