/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafranco <yafranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:16:30 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/07 14:47:18 by yafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_stack
{
	int		*values;// Le tableau contenant les rangs
	int		head;// Index du "haut" de la pile
	int		tail;// Index du "bas" de la pile (où on écrit le prochain)
	int		size;// Nombre d'éléments actuels
	int		capacity;// Taille max allouée (nb total d'args)
	char	name;// 'a' ou 'b' (pour l'affichage)
}	t_stack;

typedef struct s_data
{
	t_stack	a;
	t_stack	b;
	int		total_ops;// Compteur d'opérations
	int		count_ra;// Compteur d'opérations ra
	int		count_rb;// Compteur d'opérations rb
	int		count_rr;// Compteur d'opérations rr
	int		count_sa;// Compteur d'opérations sa
	int		count_sb;// Compteur d'opérations sb
	int		count_ss;// Compteur d'opérations ss
	int		count_pa;// Compteur d'opérations pa
	int		count_pb;// Compteur d'opérations pb
	int		count_rra;// Compteur d'opérations rra
	int		count_rrb;// Compteur d'opérations rrb
	int		count_rrr;// Compteur d'opérations rrr
	int		is_bench;// 1 si flag --bench actif
	int		disorder;
}	t_data;

void	ft_rev_rotate(t_stack *s);
void	rra(t_data *data, int print);
void	rrb(t_data *data, int print);
void	rrr(t_data *data, int print);
void	ft_rotate(t_stack *s);
void	ra(t_data *data, int print);
void	rb(t_data *data, int print);
void	rr(t_data *data, int print);
void	ft_sort_int_tab(int *tab, int size);
int		*ft_copy_array(int *raw_tab, int size);
void	ft_normalize_stack(t_stack *a);
t_stack	*ft_init_data(t_data *data, int capacity);

#endif