/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:12:00 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/06 10:08:17 by jfoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sep(char c)
{
    return (c == ' ' || c == '\t');
}

int count_words(char *str)
{
    int i = 0;
    int count = 0;

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
    return count;
}

static char *word_dup(char *str, int start, int end)
{
    char *word;
    int i = 0;

    word = malloc((end - start + 1) * sizeof(char));
    if (!word)
        return NULL;

    while (start < end)
        word[i++] = str[start++];
    word[i] = '\0';
    return word;
}

char **ft_split(char *str)
{
    int i = 0, w = 0, start;
    char **tab;

    tab = malloc((count_words(str) + 1) * sizeof(char *));
    if (!tab)
        return NULL;

    while (str[i])
    {
        while (str[i] && is_sep(str[i]))
            i++;
        if (str[i])
        {
            start = i;
            while (str[i] && !is_sep(str[i]))
                i++;
            tab[w++] = word_dup(str, start, i);
        }
    }
    tab[w] = NULL;
    return tab;
}