/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:03:30 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/09 18:52:26 by jfoeller         ###   ########.fr       */
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
	while(i < s->size)
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