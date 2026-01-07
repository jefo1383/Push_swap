/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:23:39 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/06 15:45:29 by yafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *s)
{
	if (s->size > 1)
	{
		s->head = (s->head + 1) % s->capacity;
		s->tail = (s->tail + 1) % s->capacity;
	}
}

void	ra(t_stack *a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}
