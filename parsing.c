/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:09:05 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/07 16:57:57 by jfoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_total_size(int ac, char **av)
{
	int	i;
	int	total;

	i = 1;
	total = 0;
	while (i < ac)
	{
		total += count_words(av[i]);
		i++;
	}
	return (total);
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi_check(const char *str, t_stack *a, char **tab)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		error_exit(a, tab);
	while (str[i])
	{
		if (!is_digit(str[i]))
			error_exit(a, tab);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
		error_exit(a, tab);
	return ((int)(result * sign));
}

void	parse_args(int ac, char **av, t_stack *a)
{
	int	i;
	int	j;
	int	k;
	char	**tab;

	a->capacity = get_total_size(ac, av);
	a->values = malloc(sizeof(int) * a->capacity);
	if (!a->values)
		error_exit(NULL, NULL);
	a->size = a->capacity;
	a->head = 0;
	a->tail = a->size - 1;
	a->name = 'a';
	i = 1;
	k = 0;
	while (i < ac)
	{
		tab = ft_split(av[i]);
		if (!tab)
			error_exit(a, NULL);
		j = 0;
		while (tab[j])
		{
			a->values[k] = ft_atoi_check(tab[j], a, tab);
			k++;
			j++;
		}
		free_split(tab);
		i++;
	}
}

void	ft_init_data(t_data *data, int capacity)
{
	data->b.capacity = capacity;
	data->b.values = malloc(sizeof(int) * capacity);
	if (!data->b.values)
		exit_error(data, NULL);
	data->b.size = 0;
	data->b.head = 0;
	data->b.tail = 0;
	data->b.name = 'b';
}
