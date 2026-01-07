/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:22:45 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/07 14:34:54 by jfoeller         ###   ########.fr       */
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

void	error_exit(t_data *data, char **tab)
{
	if (data)
	{
		if (data->a.values)
			free(data->a.values);
		if (data->b.values)
			free(data->b.values);
	}
	if (tab)
		free_split(tab);
	write(2, "Error\n", 6);
	exit (1);
}