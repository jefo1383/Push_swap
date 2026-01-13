/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:35:41 by yafranco          #+#    #+#             */
/*   Updated: 2026/01/13 13:58:00 by yafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifdef DEBUG_MODE
# include <stdio.h> // On inclut stdio seulement ici

void	print_stack_debug(t_stack *s, char *name)
{
	int	i;
	int	index;
	int	tail_index;

	i = 0;
	tail_index = (s->head + s->size - 1) % s->capacity;
	printf("\033[0;33m\n--- STACK %s ", name);
	printf("(size: %d / cap: %d) ---\033[0m\n", s->size, s->capacity);
	if (s->size == 0)
		printf("  [ Empty ]\n");
	else
	{
		i = 0;
		while (i < s->size)
		{
			index = (s->head + i) % s->capacity;
			printf(" [%d] Values: %d", index, s->values[index]);
			if (index == s->head)
				printf("  \033[0;32m<--- TOP (head)\033[0m");
			if (index == tail_index)
				printf("  \033[0;31m<--- BOTTOM (tail)\033[0m");
			printf("\n");
			i++;
		}
	}
	printf("-----------------------------------------\n");
}

#else

void	print_stack_debug(t_stack *s, char *name)
{
	(void)s;
	(void)name;
}

#endif