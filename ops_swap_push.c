/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:23:18 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/13 14:29:13 by yafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	swap_stack(&data->a);
	data->total_ops++;
	data->count_sa++;
	write(1, "sa\n", 3);
	print_stack_debug(&data->a, "A");
	print_stack_debug(&data->b, "B");
}

void	sb(t_data *data)
{
	swap_stack(&data->b);
	data->total_ops++;
	data->count_sb++;
	write(1, "sb\n", 3);
	print_stack_debug(&data->a, "A");
	print_stack_debug(&data->b, "B");
}

void	ss(t_data *data)
{
	swap_stack(&data->a);
	swap_stack(&data->b);
	data->total_ops++;
	data->count_ss++;
	write(1, "ss\n", 3);
	print_stack_debug(&data->a, "A");
	print_stack_debug(&data->b, "B");
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
	print_stack_debug(&data->a, "A");
	print_stack_debug(&data->b, "B");
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
	print_stack_debug(&data->a, "A");
	print_stack_debug(&data->b, "B");
}
