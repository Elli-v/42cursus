/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:41:10 by soooh             #+#    #+#             */
/*   Updated: 2021/05/20 19:42:45 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	ft_atoi(const char *str)
{
	int	res;
	int	negative;
	int count;

	count = 0;
	negative = 1;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	negative = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
		count++;
	}
	res = res * negative;
	if (count >= 19 && negative == 1)
		return (-1);
	else if (count >= 19 && negative == -1)
		return (0);
	return (res);
}*/

int		ft_atoi(const char *str)
{
	int	a;
	int sign;

	a = 0;
	sign = 1;
	while (*str == 13 || *str == 12 || *str == 11 ||
			*str == 9 || *str == 10 || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			a = (a * 10) + *str - '0';
		else
			break ;
		str++;
	}
	return (sign * a);
}