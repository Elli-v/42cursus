/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:41:10 by soooh             #+#    #+#             */
/*   Updated: 2021/05/26 21:03:15 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ps_putstr(char *s)
{
	int			i;

	if (s == NULL)
		return (void)(NULL);
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

void			ps_error(char *text)
{
	ps_putstr(text);
	exit(0);
}

int				ps_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	numb;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	numb = 0;
	i = -1;
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			ps_error("???\n");
		if (str[i] >= '0' && str[i] <= '9')
			numb = (numb * 10) + (str[i] - 48);
	}
	numb = sign * numb;
	if (numb > INT_MAX || numb < (- INT_MAX - 1))
		ps_error("오바햇슴니다\n");
	return (numb);
}
