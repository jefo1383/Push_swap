/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:24:17 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/07 17:12:16 by yafranco         ###   ########.fr       */
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

void	print_benchmark_stats(t_data *data)
{
	print_disorder(data->disorder);
	ft_putstr_fd("[bench] strategy:\n");
	ft_putstr_fd(data->strategy_name);
	ft_putstr_fd("\n[bench] total_ops:\n");
	ft_putnbr_fd(data->total_ops);
	ft_putstr_fd("\n");
	ft_putstr_fd("[bench] sa: ");
	ft_putnbr_fd(data->count_sa);
	ft_putstr_fd(" sb: ");
	ft_putnbr_fd(data->count_sb);
	ft_putstr_fd(" ss: ");
	ft_putnbr_fd(data->count_ss);
	ft_putstr_fd("\n");
	ft_putstr_fd("[bench] pa: ");
	ft_putnbr_fd(data->count_pa);
	ft_putstr_fd(" pb: ");
	ft_putnbr_fd(data->count_pb);
	ft_putstr_fd("\n");
	print_rotate_stats(data);
}
