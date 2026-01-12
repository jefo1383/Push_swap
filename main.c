/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:22:27 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/12 14:58:44 by jfoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_algo(t_data *data)
{
	if (data->algo_mode == MODE_SIMPLE)
		algo_simple(&data);
	else if (data->algo_mode == MODE_MEDIUM)
		algo_medium(&data);
	else if (data->algo_mode == MODE_COMPLEX)
		algo_complex(&data);
	else
		algo_adaptive(&data);
}

int	main(int ac, char **av)
{
	t_data	data;
	
	if (ac < 2)
		return (0);
	ft_memset(&data, 0, sizeof(t_data));
	parse_flags(&ac, &av, &data);
	parse_args(ac, av, &data);
	ft_init_data(&data, data.a.capacity);
	ft_normalize_stack(&data);
	if (is_sorted(&data.a))
	{
		if (data.is_bench)
			print_benchmark_stats(&data);
		free_data(&data);
		return (0);
	}
	run_algo(&data);
	if (data.is_bench)
		print_benchmark_stats(&data);
	free_data(&data);
	return (0);
}