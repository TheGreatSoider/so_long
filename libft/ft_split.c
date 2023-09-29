/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:11:42 by cocheong          #+#    #+#             */
/*   Updated: 2022/09/21 23:58:41 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//s = 0123456789876543210
//c = 9 
//
//str[0] = 

static int	word_count(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			j++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (j);
}

static void	seperator(const char *s, char c, char **str)
{
	int		i;
	int		j;
	int		l;
	int		old_i;

	i = 0;
	l = 0;
	while (s[i] != '\0')
	{
		j = 0;
		if (s[i] != c)
		{
			old_i = i;
			while (s[i] != '\0' && s[i] != c)
			{
				i++;
				j++;
			}
			str[l] = ft_substr(s, old_i, j);
			l++;
		}
		if (s[i] != '\0')
			i++;
	}
	str[l] = 0;
}

char	**ft_split(const char *s, char c)
{
	char	**str;

	if (s == 0)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (str == 0)
		return (NULL);
	seperator(s, c, str);
	return (str);
}

// int main (void)
// {
// 	char **sstr;
// 	char	str[] = "Matthew like Jay Chou according to Colin Cheong.";
// 	char	character = ' ';

// 	sstr = ft_split(str, character);
// 	printf("%s\n", sstr[0]);
// 	return (0);
// }
