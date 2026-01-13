/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:25:22 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/13 15:36:38 by yafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_data *data)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = get_val(&data->a, 0);
	v2 = get_val(&data->a, 1);
	v3 = get_val(&data->a, 2);
	if (v1 > v2 && v1 > v3)
		ra(data);
	else if (v2 > v1 && v2 > v3)
		rra(data);
	if (get_val(&data->a, 0) > get_val(&data->a, 1))
		sa(data);
}

static void	selection_sort(t_data *data)
{
	int	min_pos;

	while (data->a.size > 0)
	{
		min_pos = get_min_pos(&data->a);
		if (min_pos <= data->a.size / 2)
		{
			while (min_pos-- > 0)
				ra(data);
		}
		else
		{
			while (min_pos++ < data->a.size)
				rra(data);
		}
		pb(data);
	}
	while (data->b.size > 0)
		pa(data);
}

void	algo_simple(t_data *data)
{
	if (data->a.size == 2)
		sa(data);
	else if (data->a.size == 3)
		sort_three(data);
	else
		selection_sort(data);
}
