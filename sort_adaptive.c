/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:26:00 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/13 14:46:55 by yafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_adaptive(t_data *data)
{
	if (data->a.size <= 5)
	{
		algo_simple(data);
		return ;
	}
	if (data->disorder < 0.2f)
		algo_complex(data);
	else if (data->disorder < 0.5f)
		algo_medium(data);
	else
		algo_complex(data);
}
