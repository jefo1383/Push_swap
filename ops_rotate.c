/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:23:39 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/13 14:35:23 by yafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *s)
{
	int	val;
	int	tail_pos;

	if (s->size < 2)
		return ;
	val = s->values[s->head];
	s->head = (s->head + 1) % s->capacity;
	tail_pos = (s->head + s->size - 1) % s->capacity;
	s->values[tail_pos] = val;
}

void	ra(t_data *data)
{
	ft_rotate(&data->a);
	data->total_ops++;
	data->count_ra++;
	write(1, "ra\n", 3);
	print_stack_debug(&data->a, "A");
	print_stack_debug(&data->b, "B");
}

void	rb(t_data *data)
{
	ft_rotate(&data->b);
	data->total_ops++;
	data->count_rb++;
	write(1, "rb\n", 3);
	print_stack_debug(&data->a, "A");
	print_stack_debug(&data->b, "B");
}

void	rr(t_data *data)
{
	ft_rotate(&data->a);
	ft_rotate(&data->b);
	data->total_ops++;
	data->count_rr++;
	write(1, "rr\n", 3);
	print_stack_debug(&data->a, "A");
	print_stack_debug(&data->b, "B");
}
