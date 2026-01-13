/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:12:00 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/13 15:15:32 by yafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && (str[i] != ' ' && str[i] != '\t'))
				i++;
		}
	}
	return (count);
}

static char	*word_dup(char *str, int len)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	safe_word_add(char **tab, int idx, char *str, int len)
{
	tab[idx] = word_dup(str, len);
	if (!tab[idx])
	{
		free_split(tab);
		return (0);
	}
	return (1);
}

static int	fill_tab(char **tab, char *str)
{
	int	i;
	int	w;
	int	start;

	i = 0;
	w = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i])
		{
			start = i;
			while (str[i] && (str[i] != ' ' && str[i] != '\t'))
				i++;
			if (!safe_word_add(tab, w, str + start, i - start))
				return (0);
			w++;
		}
	}
	tab[w] = NULL;
	return (1);
}

char	**ft_split(char *str)
{
	char	**tab;

	if (!str)
		return (NULL);
	tab = malloc((count_words(str) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (!fill_tab(tab, str))
		return (NULL);
	return (tab);
}
