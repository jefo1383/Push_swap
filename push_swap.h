/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoeller <jeremy.foeller@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 14:16:30 by jfoeller          #+#    #+#             */
/*   Updated: 2026/01/08 10:52:30 by jfoeller         ###   ########.fr       */
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
	float	disorder;
}	t_data;

// Utils & Stack Basics
int		get_val(t_stack *s, int i);
void	push_circular(t_stack *stack, int value);
int		pop_circular(t_stack *stack);
void	swap_stack(t_stack *s);
void	*ft_memset(void *s, int c, size_t n);

// Parsing & Init
int		count_words(char *str);
int		is_sep(char c);
char	**ft_split(char *str);
void	free_split(char **tab);
void	error_exit(t_data *data, char **tab);
void	parse_args(int ac, char **av, t_data *data);
void	ft_init_data(t_data *data, int capacity);
void	ft_normalize_stack(t_data *data);
void	free_data(t_data *data);

// Operations
void	sa(t_data *data, int print);
void	sb(t_data *data, int print);
void	ss(t_data *data, int print);
void	pa(t_data *data, int print);
void	pb(t_data *data, int print);
void	ra(t_data *data, int print);
void	rb(t_data *data, int print);
void	rr(t_data *data, int print);
void	rra(t_data *data, int print);
void	rrb(t_data *data, int print);
void	rrr(t_data *data, int print);

// Metrics
float	compute_disorder(t_stack *a);
int		is_sorted(t_stack *stack);

// Algorithms

#endif