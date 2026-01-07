/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:23:53 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/06 15:44:44 by yafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_stack *s)
{
	if (s->size > 1)
	{
		s->head = (s->head - 1 + s->capacity) % s->capacity;
		s->tail = (s->tail - 1 + s->capacity) % s->capacity;
	}
}

void	rra(t_stack *a)
{
	ft_rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	ft_rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	write(1, "rrr\n", 4);
}
