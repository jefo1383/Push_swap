/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:52:37 by yafranco          #+#    #+#             */
/*   Updated: 2026/01/12 16:11:13 by jfoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr_fd(int n)
{
	long	nbr;
	char	c;

	nbr = n;
	if (nbr < 0)
	{
		write(2, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr >= 0 && nbr <= 9)
	{
		c = nbr + 48;
		write(2, &c, 1);
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10);
		ft_putnbr_fd(nbr % 10);
	}
}

void	ft_putstr_fd(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
}

void	print_disorder(double disorder)
{
	int		whole;
	int		dec;
	double	percent;

	percent = disorder * 100;
	whole = (int)percent;
	dec = (int)((percent - whole) * 100);
	ft_putstr_fd("[bench] disorder:\n");
	ft_putnbr_fd(whole);
	ft_putstr_fd(".");
	if (dec < 10)
		ft_putstr_fd("0");
	ft_putnbr_fd(dec);
	ft_putstr_fd("%\n");
}
