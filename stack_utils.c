/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:23:00 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/05 09:29:13 by jfoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Récupérer la valeur logique i (0 = top, size-1 = bottom)
int get_val(t_stack *s, int i)
{
    return (s->values[(s->head + i) % s->capacity]);
}
