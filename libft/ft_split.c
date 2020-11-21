/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:18:39 by soooh             #+#    #+#             */
/*   Updated: 2020/11/21 14:17:10 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wcount(char const *s, char c)
{
	int		flag;
	int		n;

	n = 0;
	flag = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s++ == c)
		{
			if (flag == 1)
			{
				n++;
				flag = 0;
			}
		}
		else
			flag = 1;
	}
	if (flag == 1)
		n++;
	return (n);
}

static char		*ft_wlen(int *a, const char *s, char c)
{
	int		i;
	int		k;
	char	*ret;

	i = 0;
	while (s[*a + i] && s[*a + i] != c)
		i++;
	if (!(ret = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	ret[i] = 0;
	*a += i;
	k = 0;
	while (--i >= 0)
		ret[i] = s[*a - ++k];
	return (ret);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	int		k;
	int		i;
	int		n;

	n = ft_wcount(s, c);
	if (!(ret = (char **)ft_calloc((n + 1), sizeof(char *))))
		return (0);
	i = -1;
	k = 0;
	while (++i < n)
	{
		while (s[k] && s[k] == c)
			k++;
		if (!(ret[i] = ft_wlen(&k, s, c)))
		{
			n = 0;
			while (ret[n])
				free(ret[n++]);
			free(ret);
			return (0);
		}
	}
	return (ret);
}
