/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:16:30 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/02 14:29:32 by jfoeller         ###   ########.fr       */
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

#endif