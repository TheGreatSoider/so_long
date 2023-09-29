/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:10:46 by cocheong          #+#    #+#             */
/*   Updated: 2022/09/01 15:36:33 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 123456789
// -99999999

static size_t	length(long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n != 0)
	{
		n = (n / 10);
		len++;
	}
	return (len);
}

static void	string(long nb, size_t i, char *str)
{
	str[i--] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return ;
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char		*str;
	long		nb;
	size_t		i;

	nb = (long)n;
	i = length(nb);
	str = (char *)malloc((sizeof(char)) * (i + 1));
	if (str == NULL)
		return (NULL);
	string(nb, i, str);
	return (str);
}
