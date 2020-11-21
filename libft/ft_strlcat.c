/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 10:53:44 by soooh             #+#    #+#             */
/*   Updated: 2020/10/07 12:19:58 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dest_len >= size)
		return (src_len + size);
	else
	{
		i = 0;
		j = dest_len;
		while (size - dest_len - 1 > 0 && src[i] != '\0')
		{
			dest[j] = src[i];
			j++;
			i++;
			size--;
		}
		dest[j] = '\0';
		return (dest_len + src_len);
	}
}
