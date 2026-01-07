/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:33:46 by yafranco          #+#    #+#             */
/*   Updated: 2026/01/06 14:45:37 by yafranco         ###   ########.fr       */
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

static void	ft_check_duplicates(int *sorted_tab, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (sorted_tab[i] == sorted_tab[i + 1])
		{
			free(sorted_tab);
			ft_error();
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

void	ft_normalize_stack(t_stack *a)
{
	int	*copy;
	int	i;

	i = 0;
	copy = ft_copy_array(a->values, a->size);
	ft_sort_in_tab(copy, a->size);
	ft_check_duplicates(copy, a->size);

	i = 0;
	while (i < a->size)
	{
		a->values[i] = ft_get_rank(a->values[i], copy, a->size);
		i++;
	}
	free(copy);
}
