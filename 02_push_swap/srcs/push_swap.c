/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:10:02 by soooh             #+#    #+#             */
/*   Updated: 2021/05/29 19:28:02 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void				swap_ab(t_stack *stack)
{
	t_node			*temp;
	t_node			*post_head;

	if (stack->total < 2)
		return ;
	post_head = stack->head->next;
	temp = stack->head;
	temp->next = post_head->next;
	stack->head = post_head;
	stack->head->prev = NULL;
	stack->head->next = temp;
	temp->prev = stack->head;
	if (stack->total == 2)
		stack->tail = stack->head->next;
}

void				push_ab_total_one(t_stack *from, t_stack *to)
{
	if (to->total == 0)
		{
			to->head = from->head;
			to->tail = to->head;
		}
		else
		{
			to->head->prev = from->head;
			from->head->next = to->head;
			to->head = to->head->prev;
		}
		from->head = NULL;
		from->tail = NULL;
}
void				push_ab(t_stack *from, t_stack *to)
{
	if (from->total == 1)
		push_ab_total_one(from, to);
	if (to->total == 0)
	{
		to->head = from->head;
		to->tail = to->head;
		from->head = from->head->next;
		from->head->prev = NULL;
		to->head->next = NULL;
	}
	else
	{
		to->head->prev = from->head;
		from->head = from->head->next;
		from->head->prev = NULL;
		to->head->prev->next = to->head;
		to->head = to->head->prev;
	}
}

int					main(int argc, char *argv[])
{
	t_stack			*a;
	t_stack			*b;

	// 메모리 누수 검사는 했나요? >> 다 만들고 할게요옹~
	// 에러 메세지 출력은 fd로 해야 한다고 함둥
	// printf("main argc = %d\n", argc);
	if (argc == 1)
		ps_error("암것도없다\n");
	a = init_stack();
	b = init_stack();
	// printf("값 넣기 전 total = %d\n", (&a)->total);
	set_stack(argc, argv, a);
}