/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_linked.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:15:42 by soooh             #+#    #+#             */
/*   Updated: 2021/05/30 17:25:21 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void				connect_node(t_node *temp, t_node **node, t_stack *a)
{
	if (!*node)
	{
		*node = temp;
		a->head = temp;
	}
	else
	{
		(*node)->next = temp;
		temp->prev = *node;
		*node = (*node)->next;
	}
}

int					make_node(char *argv, t_node **node, t_stack *a)
{
	t_node			*temp;


	temp = init_node();
	if (!temp)
		return (0);
	temp->data = ps_atoi(argv);
	// printf("argc = %d\n", temp->data);
	connect_node(temp, node, a);
	return (1);
}

void				duplicate_data(t_node *node)
{
	int				data;
	t_node			*temp;

	while (node->next)
	{
		temp = node->next;
		data = node->data;
		while (temp)
		{
			if (temp->data == data)
				ps_error(SAME_NUM);
			if (temp->next)
				temp = temp->next;
			else
				break ;
		}
		node = node->next;
	}
	
}

void				set_stack(int argc, char **argv, t_stack *a)
{
	int				i;
	int				stack;
	t_node			*node;
	t_node			*temp;

	i = 0;
	node = NULL;
	while (++i < argc)
	{
		stack = make_node(argv[i], &node, a);
		if (!stack)
			ps_error(BASIC);
		a->total++;
	}
	temp = a->head;
	while (temp)
	{
		// printf("temp = %d\n", temp->data);
		temp = temp->next;
	}
	printf("head = %d\n", ((t_node *)a->head)->data);
	if (node->next == NULL)
		a->tail = node;
	printf("tail = %d\n", ((t_node *)a->tail)->data);
	printf("total = %d\n", (a->total));
	while(node->prev)
		node = node->prev;
	// printf("head->next->data = %d\n", ((t_node *)a->head)->next->data);
	// printf("head->next->next->data = %d\n", ((t_node *)a->head)->next->next->data);
	duplicate_data((t_node *)a->head);
}
