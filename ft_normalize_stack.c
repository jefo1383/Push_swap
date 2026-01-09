/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:33:46 by yafranco          #+#    #+#             */
/*   Updated: 2026/01/09 19:23:50 by jfoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	ft_get_rank(int value, int *sorted_tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted_tab[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static void	ft_check_duplicates(t_data *data, int *sorted_tab, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (sorted_tab[i] == sorted_tab[i + 1])
		{
			free(sorted_tab);
			error_exit(data, NULL);
		}
		i++;
	}
}

int	*ft_copy_array(int *raw_tab, int size)
{
	int	*tab_copy;
	int	i;

	i = 0;
	tab_copy = malloc(sizeof(int) * size);
	if (!tab_copy)
		return (NULL);
	while (i < size)
	{
		tab_copy[i] = raw_tab[i];
		i++;
	}
	return (tab_copy);
}

void	ft_normalize_stack(t_data *data)
{
	int	*copy;
	int	i;

	copy = ft_copy_array(data->a.values, data->a.size);
	if (!copy)
		error_exit(data, NULL);
	ft_sort_int_tab(copy, data->a.size);
	ft_check_duplicates(data, copy, data->a.size);
	i = 0;
	while (i < data->a.size)
	{
		data->a.values[i] = ft_get_rank(data->a.values[i], copy, data->a.size);
		i++;
	}
	free(copy);
	data->disorder = compute_disorder(&data->a);
}
