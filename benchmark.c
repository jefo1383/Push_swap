/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:24:17 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/07 13:36:02 by yafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_sorted(t_stack *s)
{
	int	i;
	int	current_index;
	int	next_index;

	i = 0;
	current_index = s->head;
	while (i < (s->size - 1))
	{
		next_index = (current_index +1) % s->capacity;
		if (s->values[current_index] > s->values[next_index])
			return (0);
		current_index = next_index;
		i++;
	}
	return (1);
}

