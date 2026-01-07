/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:46:58 by yafranco          #+#    #+#             */
/*   Updated: 2026/01/07 15:40:49 by yafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_init_data(t_data *data, int capacity)
{
	ft_memset(data, 0, sizeof(t_data));
	data->b.capacity = capacity;
	data->b.values = malloc(sizeof(int) * capacity);
	if (!data->b.values)
		exit_error(data);
	data->b.size = 0;
	data->b.head = 0;
	data->b.tail = 0;
	data->b.name = 'b';
}
