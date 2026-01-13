/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:25:45 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/13 14:47:57 by yafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max_val)
{
	int	bits;

	bits = 0;
	while ((max_val >> bits) != 0)
		bits++;
	return (bits);
}

void	algo_complex(t_data *data)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;

	size = data->a.size;
	max_bits = get_max_bits(size - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((get_val(&data->a, 0) >> i) & 1) == 1)
				ra(data);
			else
				pb(data);
			j++;
		}
		while (data->b.size > 0)
			pa(data);
		if (is_sorted(&data->a))
			return ;
		i++;
	}
}
