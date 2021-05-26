/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:10:02 by soooh             #+#    #+#             */
/*   Updated: 2021/05/26 19:35:44 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int			main(int argc, char **argv)
{
	int		i;
	int		save[argc];

	i = -1;
	while (++i < argc - 1)
	{
		save[i] = ps_atoi(argv[i + 1]);
		printf("%d\n", save[i]);
	}
}