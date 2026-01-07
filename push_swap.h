/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:16:30 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/07 14:36:03 by jfoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_stack
{
    int     *values;      // Le tableau contenant les rangs
    int     head;         // Index du "haut" de la pile
    int     tail;         // Index du "bas" de la pile (où on écrit le prochain)
    int     size;         // Nombre d'éléments actuels
    int     capacity;     // Taille max allouée (nb total d'args)
    char    name;         // 'a' ou 'b' (pour l'affichage)
} t_stack;

typedef struct s_data
{
    t_stack a;
    t_stack b;
    int     total_ops;    // Compteur d'opérations
    int     is_bench;     // 1 si flag --bench actif
} t_data;

int count_words(char *str);
int is_sep(char c);
char **ft_split(char *str);
void	free_split(char **tab);
void	error_exit(t_data *data, char **tab);
void	parse_args(int ac, char **av, t_stack *a);
int get_val(t_stack *s, int i);
void	push_circular(t_stack *stack, int value);
int	pop_circular(t_stack *stack);
void	swap_stack(t_stack *s);

#endif