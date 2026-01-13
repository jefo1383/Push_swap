/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:23:53 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/13 14:37:34 by yafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_stack *s)
{
	int	val;
	int	tail_pos;

	if (s->size < 2)
		return ;
	tail_pos = (s->head + s->size -1) % s->capacity;
	val = s->values[tail_pos];
	s->head = (s->head - 1 + s->capacity) % s->capacity;
	s->values[s->head] = val;
}

void	rra(t_data *data)
{
	ft_rev_rotate(&data->a);
	data->total_ops++;
	data->count_rra++;
	write(1, "rra\n", 4);
	print_stack_debug(&data->a, "A");
	print_stack_debug(&data->b, "B");
}

void	rrb(t_data *data)
{
	ft_rev_rotate(&data->b);
	data->total_ops++;
	data->count_rrb++;
	write(1, "rrb\n", 4);
	print_stack_debug(&data->a, "A");
	print_stack_debug(&data->b, "B");
}

void	rrr(t_data *data)
{
	ft_rev_rotate(&data->a);
	ft_rev_rotate(&data->b);
	data->total_ops++;
	data->count_rrr++;
	write(1, "rrr\n", 4);
	print_stack_debug(&data->a, "A");
	print_stack_debug(&data->b, "B");
}
