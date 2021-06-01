/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:10:02 by soooh             #+#    #+#             */
/*   Updated: 2021/06/02 00:25:17 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int					max(t_node *node, int total)
{
	int				max;

	max = node->data;
	while (total--)
	{
		if (max < node->data)
			max = node->data;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	return (max);
}

void				test(t_node *node, t_stack *stack)
{
	int				index;
	int				i;
	int				min;
	int				x_min;

	index = 0;
	i = 0;
	while (index++ < stack->total)
	{
		if (index == 1)
		{
			min = max(node, stack->total);
			while (i++ <= stack->total)
			{
				if (min > node->data)
					min = node->data;
				if (node->next)
					node = node->next;
			}
			while (node->prev)
				node = node->prev;
			while (i-- >= 0)
			{
				if (min == node->data)
					node->index = index;
				if (node->next)
					node = node->next;
			}
			while (node->prev)
				node = node->prev;
			x_min = min;
		}
		if (index > 1)
		{
			min = max(node, stack->total);
			while (i++ < stack->total)
			{
				if (min > node->data && x_min < node->data)
						min = node->data;
				if (node->next)
					node = node->next;
			}
			while (node->prev)
				node = node->prev;
			while (i-- >= 0)
			{
				if (min == node->data)
					node->index = index;
				if (node->next)
					node = node->next;
			}
			while (node->prev)
				node = node->prev;
			x_min = min;
		}
	}
	//제대로 부여 됐는지 확인하는 반복문 룰루~
	while (node->next)
	{
		printf("data = %d **** index = %d\n", node->data, node->index);
		node = node->next;
	}
	printf("data = %d **** index = %d\n", stack->tail->data, stack->tail->index);
}

int					main(int argc, char *argv[])
{
	t_stack			*a;
	t_stack			*b;

	// 메모리 누수 검사는 했나요? >> 다 만들고 할게요옹~
	// printf("main argc = %d\n", argc);
	if (argc == 1)
		ps_error(BASIC);
	a = init_stack();
	b = init_stack();
	// printf("값 넣기 전 total = %d\n", (&a)->total);
	set_stack(argc, argv, a);	
	// swap_stack(a, A);
	// push_stack(a, b, A);
	// push_stack(b, a, B);
	// reverse_rotate_stack(a, A);
	// rotate_stack(a, A);
	// swap_swap(a, b, ALL);
	// printf("a head = %d\n", a->head->data);
	// printf("a tail = %d\n", a->tail->data);
	// printf("b head = %d\n", b->head->data);
	// printf("b tail = %d\n", b->tail->data);
	// printf("a head->next = %d\n", a->head->next->data);
	test(a->head, a);
}
