/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:11:58 by cocheong          #+#    #+#             */
/*   Updated: 2022/08/25 14:03:47 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	size_t	i;
	size_t	beg;
	size_t	end;

	beg = 0;
	if (s1 == 0 || set == 0)
		return (NULL);
	while (s1[beg] != '\0' && ft_in_set(s1[beg], set) != '\0')
		beg++;
	end = ft_strlen(s1);
	while (end > beg && ft_in_set(s1[end - 1], set) != '\0')
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - beg + 1));
	if (str == 0)
		return (NULL);
	i = 0;
	while (beg < end)
		str[i++] = s1[beg++];
	str[i] = '\0';
	return (str);
}
