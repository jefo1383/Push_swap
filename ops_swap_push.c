/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:23:18 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/12 09:53:13 by jfoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	swap_stack(&data->a);
	data->total_ops++;
	data->count_sa++;
	write(1, "sa\n", 3);
}

void	sb(t_data *data)
{
	swap_stack(&data->b);
	data->total_ops++;
	data->count_sb++;
	write(1, "sb\n", 3);
}

void	ss(t_data *data)
{
	swap_stack(&data->a);
	swap_stack(&data->b);
	data->total_ops++;
	data->count_ss++;
	write(1, "ss\n", 3);
}

void	pa(t_data *data)
{
	int	val;
	
	if (data->b.size == 0)
		return ;
	val = pop_circular(&data->b);
	push_circular(&data->a, val);
	data->total_ops++;
	data->count_pa++;
	write(1, "pa\n", 3);
}

void	pb(t_data *data)
{
	int	val;

	if (data->a.size == 0)
		return ;
	val = pop_circular(&data->a);
	push_circular(&data->b, val);
	data->total_ops++;
	data->count_pb++;
	write(1, "pb\n", 3);
}