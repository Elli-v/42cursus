/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:41:53 by soooh             #+#    #+#             */
/*   Updated: 2020/10/09 15:00:04 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	i = 0;
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < (n - 1) && (ps1[i] != '\0' && ps2[i] != '\0'))
	{
		if (ps1[i] != ps2[i])
			return (ps1[i] - ps2[i]);
		else
			i++;
	}
	return (ps1[i] - ps2[i]);
}
