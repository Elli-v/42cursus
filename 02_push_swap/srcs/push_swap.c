/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:10:02 by soooh             #+#    #+#             */
/*   Updated: 2021/05/31 02:09:49 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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
	printf("a head = %d\n", a->head->data);
	printf("a tail = %d\n", a->tail->data);
	printf("b head = %d\n", b->head->data);
	printf("b tail = %d\n", b->tail->data);
	printf("a head->next = %d\n", a->head->next->data);
}