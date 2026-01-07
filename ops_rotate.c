/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:23:39 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/07 14:11:55 by yafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *s)
{
	if (s->size > 1)
	{
		s->head = (s->head + 1) % s->capacity;
		s->tail = (s->tail + 1) % s->capacity;
	}
}

void	ra(t_data *data, int print)
{
	ft_rotate(&data->a);
	data->total_ops++;
	data->count_ra++;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_data *data, int print)
{
	ft_rotate(&data->b);
	data->total_ops++;
	data->count_rb++;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_data *data, int print)
{
	ft_rotate(&data->a);
	ft_rotate(&data->b);
	data->total_ops++;
	data->count_rr++;
	if (print)
		write(1, "rr\n", 3);
}
