/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:25:34 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/09 19:19:14 by jfoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(t_data *data)
{
	int	x;
	int	chunk_size;

	x = 1;
	while ((x * x) < data->a.size)
		x++;
	chunk_size = data->a.size / x;
	if (chunk_size < 5)
		chunk_size = 5;
	return (chunk_size);
}

static void	a_to_b(t_data *data, int print, int chunk_size, int *limit)
{
	pb(data, print);
	if (get_val(&data->b, 0) < (*limit - (chunk_size / 2)))
		rb(data, print);
	if (data->b.size >= *limit && data->b.size < data->a.capacity)
		*limit += chunk_size;
}

static void	b_to_a(t_data *data, int print)
{
	int	max_pos;

	max_pos = get_max_pos(&data->b);
	while (max_pos-- > 0)
		rb(data, print);
	pa(data, print);
}

void    algo_medium(t_data *data, int print)
{
	int	limit;
	int	chunk_size;

	chunk_size = get_chunk_size(data);
	limit = chunk_size;
	while (data->a.size > 0)
	{
		if (get_val(&data->a, 0) < limit)
			a_to_b(data, print, chunk_size, &limit);
		else
			ra(data, print);
	}
	while (data->b.size > 0)
		b_to_a(data, print);
}