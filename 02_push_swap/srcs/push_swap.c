/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:10:02 by soooh             #+#    #+#             */
/*   Updated: 2021/05/30 18:03:33 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int					main(int argc, char *argv[])
{
	t_stack			*a;
	t_stack			*b;

	// 메모리 누수 검사는 했나요? >> 다 만들고 할게요옹~
	// 에러 메세지 출력은 fd로 해야 한다고 함둥
	// printf("main argc = %d\n", argc);
	if (argc == 1)
		ps_error(BASIC);
	a = init_stack();
	b = init_stack();
	// printf("값 넣기 전 total = %d\n", (&a)->total);
	set_stack(argc, argv, a);
	// swap_stack(a);
	// push_stack(a, b);
	// reverse_rotate_stack(a);
	// rotate_stack(a);
	// printf("a head = %d\n", a->head->data);
	// printf("a head->next = %d\n", a->head->next->data);
	// printf("b head = %d\n", b->head->data);
	// printf("a tail = %d\n", a->tail->data);
	
}