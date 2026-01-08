/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metrics_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:24:04 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/08 15:18:27 by jfoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *a)
{
	long	mistakes;
	long	total_pairs;
	int		i;
	int		j;

	mistakes = 0;
	total_pairs = 0;
	
	if (a->size < 2)
		return (0.0f);

	i = 0;
	while (i < a->size - 1)
	{
		j = i + 1;
		while (j < a->size)
		{
			total_pairs++;
			if (get_val(a, i) > get_val(a, j))
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0f);
	return ((float)mistakes / (float)total_pairs);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	parse_flags(int *ac, char ***av, t_data *data)
{
	data->algo_mode = MODE_ADAPTIVE;
	data->is_bench = 0;
	while (*ac > 1 && (*av)[1][0] == '-' && (*av)[1][1] == '-')
	{
		if (ft_strcmp((*av)[1], "--simple") == 0)
			data->algo_mode = MODE_SIMPLE;
		else if (ft_strcmp((*av)[1], "--medium") == 0)
			data->algo_mode = MODE_MEDIUM;
		else if (ft_strcmp((*av)[1], "--complex") == 0)
			data->algo_mode = MODE_COMPLEX;
		else if (ft_strcmp((*av)[1], "--adaptive") == 0)
			data->algo_mode = MODE_ADAPTIVE;
		else if (ft_strcmp((*av)[1], "--bench") == 0)
			data->is_bench = 1;
		else
			return ;
		(*av)++;
		(*ac)--;
	}
}