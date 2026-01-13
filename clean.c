/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:22:45 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/13 14:41:19 by yafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_data(t_data *data)
{
	if (data->a.values)
		free(data->a.values);
	if (data->b.values)
		free(data->b.values);
}

void	error_exit(t_data *data, char **tab)
{
	if (data)
		free_data(data);
	if (tab)
		free_split(tab);
	write(2, "Error\n", 6);
	exit(1);
}
