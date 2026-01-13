/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:46:58 by yafranco          #+#    #+#             */
/*   Updated: 2026/01/13 14:19:50 by yafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_data(t_data *data, int capacity)
{
	data->b.capacity = capacity;
	data->b.values = malloc(sizeof(int) * capacity);
	if (!data->b.values)
		error_exit(data, NULL);
	data->b.size = 0;
	data->b.head = 0;
	data->b.name = 'b';
}
