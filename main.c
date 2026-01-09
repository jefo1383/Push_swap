/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:22:27 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/09 15:17:12 by jfoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;
	int	print;
	
	if (ac < 2)
		return (0);
	ft_memset(&data, 0, sizeof(t_data));
	parse_flags(&ac, &av, &data);
	parse_args(ac, av, &data);
	ft_init_data(&data, data.a.capacity);
	ft_normalize_stack(&data);
	if (is_sorted(&data.a))
	{
		free_data(&data);
		return (0);
	}
	data.disorder = compute_disorder(&data.a);
	if (data.is_bench == 1)
		print = 0;
	else
		print = 1;
	return (0);
}