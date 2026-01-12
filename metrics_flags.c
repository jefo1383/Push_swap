/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metrics_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:24:04 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/12 13:58:32 by jfoeller         ###   ########.fr       */
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

static int	get_mode_id(char *str)
{
	if (ft_strcmp(str, "--simple") == 0)
		return (MODE_SIMPLE);
	if (ft_strcmp(str, "--medium") == 0)
		return (MODE_MEDIUM);
	if (ft_strcmp(str, "--complex") == 0)
		return (MODE_COMPLEX);
	if (ft_strcmp(str, "--adaptive") == 0)
		return (MODE_ADAPTIVE);
	return (-1);
}

void	parse_flags(int *ac, char ***av, t_data *data)
{
	int	id;
	int	seen;
	
	seen = 0;
	while (*ac > 1 && (*av)[1][0] == '-' && (*av)[1][1] == '-')
	{
		if (ft_strcmp((*av)[1], "--bench") == 0)
			data->is_bench = 1;
		else
		{
			id = get_mode_id((*av)[1]);
			if (id == -1 || seen)
				error_exit(NULL, NULL);
			data->algo_mode = id;
			seen = 1;
		}
		(*av)++;
		(*ac)--;
	}
}