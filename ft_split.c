/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:12:00 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/13 11:46:21 by jfoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sep(char c)
{
    return (c == ' ' || c == '\t');
}

int count_words(char *str)
{
    int i;
    int count;

	i = 0;
	count = 0;
    while (str[i])
    {
        while (str[i] && is_sep(str[i]))
            i++;
        if (str[i])
        {
            count++;
            while (str[i] && !is_sep(str[i]))
                i++;
        }
    }
    return (count);
}

static char *word_dup(char *str, int start, int end)
{
    char *word;
    int i;

	i = 0;
    word = malloc((end - start + 1) * sizeof(char));
    if (!word)
        return (NULL);
    while (start < end)
        word[i++] = str[start++];
    word[i] = '\0';
    return (word);
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
		while (str[i] && is_sep(str[i]))
			i++;
		if (str[i])
		{
			start = i;
			while (str[i] && !is_sep(str[i]))
				i++;
			tab[w] = word_dup(str, start, i);
			if (!tab[w])
			{
				free_split(tab);
				return (0);
			}
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