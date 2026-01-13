/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:03:30 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/13 16:20:47 by yafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_pos(t_stack *s)
{
	int	i;
	int	min_val;
	int	min_pos;

	i = 0;
	min_val = 2147483647;
	min_pos = 0;
	while (i < s->size)
	{
		if (get_val(s, i) < min_val)
		{
			min_val = get_val(s, i);
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}

int	get_max_pos(t_stack *s)
{
	int	i;
	int	max_val;
	int	max_pos;

	i = 0;
	max_val = -2147483648;
	max_pos = 0;
	while (i < s->size)
	{
		if (get_val(s, i) > max_val)
		{
			max_val = get_val(s, i);
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}

int	get_pos_of_val(t_stack *s, int target)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		if (get_val(s, i) == target)
			return (i);
		i++;
	}
	return (-1);
}

int	is_sorted(t_stack *s)
{
	int	i;
	int	current_index;
	int	next_index;

	i = 0;
	current_index = s->head;
	while (i < (s->size - 1))
	{
		next_index = (current_index + 1) % s->capacity;
		if (s->values[current_index] > s->values[next_index])
			return (0);
		current_index = next_index;
		i++;
	}
	return (1);
}
