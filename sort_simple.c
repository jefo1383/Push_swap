/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:25:22 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/08 17:33:49 by jfoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data, int print)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = get_val(&data->a, 0);
	v2 = get_val(&data->a, 1);
	v3 = get_val(&data->a, 2);
	if (v1 > v2 && v1 > v3)
	{
		ra(data, print);
		if (v2 < v3)
			sa(data, print);
	}
	else if (v2 > v1 && v2 > v3)
	{
		rra(data, print);
		if (v1 < v3)
			sa(data, print);
	}
	else if (v3 > v2 && v3 > v1)
		sa(data, print);
}

void	selection_sort(t_data *data, int print)
{
	int	min_pos;

	while (data->a.size > 0)
	{
		min_pos = get_min_pos(&data->a);
		if (min_pos <= data->a.size / 2)
		{
			while (min_pos > 0)
			{
				ra(data, print);
				min_pos--;
			}
		}
		else
		{
			while (min_pos < data->a.size)
			{
				rra(data, print);
				min_pos++;
			}
		}
		pb(data, print);
	}
	while (data->b.size > 0)
		pa(data, print);
}

void	algo_simple(t_data *data, int print)
{
	if (data->a.size == 2)
		sa(data, print);
	else if(data->a.size == 3)
		sort_three(data, print);
	else
		selection_sort(data, print);
}