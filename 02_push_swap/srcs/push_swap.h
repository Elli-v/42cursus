/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:10:51 by soooh             #+#    #+#             */
/*   Updated: 2021/05/27 20:39:39 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdio.h> // 나중에 꼭 지우셈 꼭..
#include <stdlib.h>
#include <unistd.h> 

# define INT_MAX	2147483647
//INT_MIN = -INT_MAX -1

typedef struct	s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				data;
}					t_node;

typedef struct		s_stack
{
	void			*head;
	void			*tail;
	int				total;
}					t_stack;

/*
** ps_utils.c
*/
void				ps_putstr(char *s);
void				ps_error(char *text);
int					ps_atoi(const char *str);

#endif