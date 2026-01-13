/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:24:17 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/13 13:25:58 by yafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_algo_name(int mode)
{
	if (mode == MODE_SIMPLE)
		ft_putstr_fd("Simple / O(n^2)");
	else if (mode == MODE_MEDIUM)
		ft_putstr_fd("Medium / O(n*sqrt(n))");
	else if (mode == MODE_COMPLEX)
		ft_putstr_fd("Complex / O(n log n)");
	else
		ft_putstr_fd("Adaptive");
}

static void	print_rotate_stats(t_data *data)
{
	ft_putstr_fd("[bench] ra: ");
	ft_putnbr_fd(data->count_ra);
	ft_putstr_fd(" rb: ");
	ft_putnbr_fd(data->count_rb);
	ft_putstr_fd(" rr: ");
	ft_putnbr_fd(data->count_rr);
	ft_putstr_fd("\n");
	ft_putstr_fd("[bench] rra: ");
	ft_putnbr_fd(data->count_rra);
	ft_putstr_fd(" rrb: ");
	ft_putnbr_fd(data->count_rrb);
	ft_putstr_fd(" rrr: ");
	ft_putnbr_fd(data->count_rrr);
	ft_putstr_fd("\n");
}

static void	print_swap_push(t_data *data)
{
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
}

void	print_bench(t_data *data)
{
	print_disorder(data->disorder);
	ft_putstr_fd("[bench] strategy:\n");
	print_algo_name(data->algo_mode);
	ft_putstr_fd("\n[bench] total_ops:\n");
	ft_putnbr_fd(data->total_ops);
	ft_putstr_fd("\n");
	print_swap_push(data);
	print_rotate_stats(data);
}
