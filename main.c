/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:22:27 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/07 14:35:34 by jfoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;
	
	if (ac < 2)
		return ;
	if (ac > 1)
	{
		parse_args(ac, av, &data.a);
		if (!ft_init_data(&data.b, data.a.capacity, 'b'))
			error_exit(&data, NULL);
	}
	return (0);
}