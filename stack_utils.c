/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:23:00 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/07 16:59:56 by jfoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_val(t_stack *s, int i)
{
    return (s->values[(s->head + i) % s->capacity]);
}

void	push_circular(t_stack *stack, int value)
{
	if (stack->size == stack->capacity)
		return ;
	stack->head = (stack->head - 1 + stack->capacity) % stack->capacity;
	stack->values[stack->head] = value;
	stack->size++;
}

int	pop_circular(t_stack *stack)
{
	int	val;

	if (stack->size == 0)
		return (0);
	val = stack->values[stack->head];
	stack->head = (stack->head + 1) % stack->capacity;
	stack->size--;
	return (val);
}

void	swap_stack(t_stack *s)
{
	int	idx1;
	int	idx2;
	int	tmp;
	
	if (s->size < 2)
		return ;
	idx1 = s->head;
	idx2 = (s->head + 1) % s->capacity;
	tmp = s->values[idx1];
	s->values[idx1] = s->values[idx2];
	s->values[idx2] = tmp;
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		*ptr = (unsigned char)c;
		i++;
		ptr++;
	}
	return (s);
}