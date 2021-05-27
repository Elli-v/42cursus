/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:10:02 by soooh             #+#    #+#             */
/*   Updated: 2021/05/28 01:28:20 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_node			*init_node(void)
{
	t_node		*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;
	node->data = 0;
	return (node);
}

void			connect_node(t_node *temp, t_node **node, t_stack *a)
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

int				make_node(char *argv, t_node **node, t_stack *a)
{
	t_node		*temp;


	temp = init_node();
	if (!temp)
		return (0);
	temp->data = ps_atoi(argv);
	printf("argc = %d\n", temp->data);
	connect_node(temp, node, a);
	return (1);
}

void			set_stack(int argc, char **argv, t_stack *a)
{
	int			i;
	int			stack;
	t_node		*node;
	t_node		*temp;

	i = 0;
	node = NULL;
	while (++i < argc)
	{
		stack = make_node(argv[i], &node, a);
		if (!stack)
			ps_error("ERROR !\n");
		a->total++;
	}
	temp = a->head;
	while (temp)
	{
		printf("temp = %d\n", temp->data);
		temp = temp->next;
	}
	printf("head = %d\n", ((t_node *)a->head)->data);
	if (node->next == NULL)
		a->tail = node;
	printf("tail = %d\n", ((t_node *)a->tail)->data);
	while(node->prev)
		node = node->prev;
}

int				main(int argc, char **argv)
{
	t_stack		a;
// 	int			i;
// 	int			save[argc];
// 
// 	i = -1;
// 	while (++i < argc - 1)
// 	{
// 		save[i] = ps_atoi(argv[i + 1]);
// 		printf("%d\n", save[i]);
// 	}
	printf("main argc = %d\n", argc);
	set_stack(argc, argv, &a);
}