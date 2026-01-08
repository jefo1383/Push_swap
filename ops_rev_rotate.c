/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:23:53 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/08 10:55:41 by jfoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_stack *s)
{
	if (s->size < 2)
		return ;
	s->head = (s->head - 1 + s->capacity) % s->capacity;
}

void	rra(t_data *data, int print)
{
	ft_rev_rotate(&data->a);
	data->total_ops++;
	data->count_rra++;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_data *data, int print)
{
	ft_rev_rotate(&data->b);
	data->total_ops++;
	data->count_rrb++;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_data *data, int print)
{
	ft_rev_rotate(&data->a);
	ft_rev_rotate(&data->b);
	data->total_ops++;
	data->count_rrr++;
	if (print)
		write(1, "rrr\n", 4);
}
