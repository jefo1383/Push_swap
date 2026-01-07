/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:22:27 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/07 17:04:26 by jfoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;
	
	if (ac < 2)
		return ;
	ft_memset(&data, 0, sizeof(t_data));
	parse_args(ac, av, &data.a);
	ft_init_data(&data, &data.a.capacity);
	return (0);
}