/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:11:46 by cocheong          #+#    #+#             */
/*   Updated: 2022/08/26 20:07:08 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;
	int	j;

	if (s != NULL && f != NULL)
	{
		i = ft_strlen(s);
		j = 0;
		while (j < i)
		{
			(*f)(j, s);
			j++;
			s++;
		}
	}
}
