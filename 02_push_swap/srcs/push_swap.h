/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:10:51 by soooh             #+#    #+#             */
/*   Updated: 2021/05/29 16:43:50 by soooh            ###   ########.fr       */
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

typedef struct		s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				data;
}					t_node;

typedef struct		s_stack
{
	t_node			*head;
	t_node			*tail;
	int				total;
}					t_stack;


/*
** ps_init.c
*/
t_stack				*init_stack(void);
t_node				*init_node(void);

/*
** ps_utils.c
*/
void				ps_putstr(char *s);
void				ps_error(char *text);
int					ps_atoi(const char *str);

/*
** ps_node.c
*/
void				connect_node(t_node *temp, t_node **node, t_stack *a);
int					make_node(char *argv, t_node **node, t_stack *a);
void				duplicate_data(t_node *node);
void				set_stack(int argc, char **argv, t_stack *a);

/*
** push_swap.c
*/
int					main(int argc, char **argv);

#endif