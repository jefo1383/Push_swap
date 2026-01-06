/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:33:46 by yafranco          #+#    #+#             */
/*   Updated: 2026/01/06 11:34:40 by yafranco         ###   ########.fr       */
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
		if (sorted_tab[i] == sorted_tab[i - 1])
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

int	*ft_normalize_stack(int *raw_tab, int size)
{
	int	*copy;
	int	*ranks;
	int	i;

	i = 0;
	copy = ft_copy_array(raw_tab, size);
	ft_sort_in_tab(copy, size);
	ft_check_duplicates(copy, size);
	ranks = malloc(sizeof(int) * size);
	if (!ranks)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ranks[i] = ft_get_rank(raw_tab[i], copy, size);
		i++;
	}
	free(copy);
	return (ranks);
}
