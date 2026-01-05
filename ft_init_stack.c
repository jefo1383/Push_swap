/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:46:58 by yafranco          #+#    #+#             */
/*   Updated: 2026/01/05 15:50:08 by yafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_init_stack(int capacity, char name)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->values = malloc(sizeof(int) * capacity);
	if (!stack->values)
	{
		free(stack);
		return (NULL);
	}
	stack->capacity = capacity;
	stack->size = 0;
	stack->head = 0;
	stack->tail = capacity - 1;
	stack->name = name;
	return (stack);
}

void	ft_fill_stack_a(t_stack *stack_a, int *ranks, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		stack_a->values[i] = ranks[i];
		i++;
	}
	stack_a->size = count;
	stack_a->head = 0;
	stack_a->tail = count - 1;
}

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

char	*ft_normalize_stack()