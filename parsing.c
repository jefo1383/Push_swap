/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:09:05 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/13 15:25:23 by yafranco         ###   ########.fr       */
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

int	ft_atoi_check(const char *str, t_data *data, char **tab)
{
	long long	res;
	int			sign;
	int			i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	if (!str[i])
		error_exit(data, tab);
	while (str[i])
	{
		if (!is_digit(str[i]))
			error_exit(data, tab);
		if (res > (LONG_MAX - (str[i] - '0')) / 10)
			error_exit(data, tab);
		res = res * 10 + (str[i++] - '0');
	}
	if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
		error_exit(data, tab);
	return ((int)(res * sign));
}

static int	parse_sub_args(t_data *data, char *arg, int current_k)
{
	char	**tab;
	int		j;

	tab = ft_split(arg);
	if (!tab)
		error_exit(data, NULL);
	j = 0;
	while (tab[j])
	{
		data->a.values[current_k] = ft_atoi_check(tab[j], data, tab);
		current_k++;
		j++;
	}
	free_split(tab);
	return (current_k);
}

void	parse_args(int ac, char **av, t_data *data)
{
	int		i;
	int		k;

	data->a.capacity = get_total_size(ac, av);
	data->a.values = malloc(sizeof(int) * data->a.capacity);
	if (!data->a.values)
		error_exit(NULL, NULL);
	data->a.size = data->a.capacity;
	data->a.head = 0;
	data->a.name = 'a';
	i = 1;
	k = 0;
	while (i < ac)
	{
		k = parse_sub_args(data, av[i], k);
		i++;
	}
}
