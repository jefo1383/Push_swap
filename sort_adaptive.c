/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:26:00 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/12 13:41:15 by jfoeller         ###   ########.fr       */
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