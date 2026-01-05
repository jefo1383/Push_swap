/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metrics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:24:04 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/05 14:19:56 by jfoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *a)
{
	long	mistakes;
	long	total;
    
	mistakes = 0;
	total = 0;

	for (int i = 0; i < a->size; i++)
	{
		for (int j = i + 1; j < a->size; j++)
		{
			total++;
			if (get_val(a, i) > get_val(a, j))
				mistakes++;
		}
	}
	if (total == 0) return (0.0f);
	return ((float)mistakes / total);
}
