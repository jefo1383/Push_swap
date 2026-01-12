/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:24:17 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/12 13:28:26 by jfoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_benchmark_stats(t_data *data)
{
	print_disorder(data->disorder);
	ft_putstr_fd("[bench] strategy:\n");
	ft_putstr_fd(data->algo_mode);
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
