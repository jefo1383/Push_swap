/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:35:41 by yafranco          #+#    #+#             */
/*   Updated: 2026/01/07 15:34:29 by yafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_debug(t_stack *s, char *name)
{
	int	i;
	int	index;

	i = 0;
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
			if (index == s->tail)
				printf("  \033[0;31m<--- BOTTOM (tail)\033[0m");
			printf("\n");
			i++;
		}
	}
	printf("-----------------------------------------\n");
}
