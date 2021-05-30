/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:12:40 by soooh             #+#    #+#             */
/*   Updated: 2021/05/30 17:27:59 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_stack			*init_stack(void)
{
	t_stack		*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		ps_error(MALLOC_ERR);
	stack->head = NULL;
	stack->tail = NULL;
	stack->total = 0;
	return (stack);
}

t_node			*init_node(void)
{
	t_node		*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		ps_error(MALLOC_ERR);
	node->prev = NULL;
	node->next = NULL;
	node->data = 0;
	return (node);
}