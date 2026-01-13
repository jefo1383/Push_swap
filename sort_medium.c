/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:25:34 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/13 17:25:40 by yafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(t_data *data)
{
	int	chunk_size;

	if (data->a.size <= 100)
		chunk_size = 19;
	else
		chunk_size = 52;
	return (chunk_size);
}

static void	a_to_b(t_data *data, int chunk_size, int *limit)
{
	pb(data);
	if (get_val(&data->b, 0) < (*limit - (chunk_size / 2)))
		rb(data);
	if (data->b.size >= *limit && data->b.size < data->a.capacity)
		*limit += chunk_size;
}

static void	move_max_to_top(t_data *data, int max_pos)
{
	int	size;

	size = data->b.size;
	if (max_pos <= size / 2)
	{
		while (max_pos-- > 0)
			rb(data);
	}
	else
	{
		while (max_pos++ < size)
			rrb(data);
	}
}

static void	b_to_a(t_data *data)
{
	int	max;
	int	max_m1_pos;

	max = get_val(&data->b, get_max_pos(&data->b));
	max_m1_pos = get_pos_of_val(&data->b, max - 1);
	if (max_m1_pos == 0)
		pa(data);
	move_max_to_top(data, get_max_pos(&data->b));
	pa(data);
	if (data->a.size >= 2 && get_val(&data->a, 0) > get_val(&data->a, 1))
		sa(data);
}

void	algo_medium(t_data *data)
{
	int	limit;
	int	chunk_size;

	chunk_size = get_chunk_size(data);
	limit = chunk_size;
	while (data->a.size > 0)
	{
		if (get_val(&data->a, 0) < limit)
			a_to_b(data, chunk_size, &limit);
		else if (get_val(&data->a, data->a.size - 1) < limit)
			rra(data);
		else
			ra(data);
	}
	while (data->b.size > 0)
		b_to_a(data);
}
