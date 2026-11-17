/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-f <ilopez-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:06:59 by helemart          #+#    #+#             */
/*   Updated: 2026/11/17 13:22:36 by ilopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- 1. Guards ---
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// --- 2. System Headers ---
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../libft/printf/ft_printf.h"

// --- 3. Custom Data Types (Enums & Structures) ---

typedef struct s_node
{
	int				value;		// Number to sort
	int				index;		// Final position in sorted stack
	struct s_node	*next;		// Next node in list
	struct s_node	*prev;		// Previous node in list
}					t_node;

typedef struct s_stack
{
	t_node			*top;		// First element in list
	t_node			*bottom;	// Last element in list
	int				size;		// Number of nodes
}					t_stack;

typedef enum e_error
{
	SUCCESS = 0,
	ERR_INVALID_INPUT = -1,
	ERR_MEMORY = -2,
	ERR_DUPLICATE = -3,
	ERR_NO_NUMBERS = -4,
	ERR_INVALID_FLAG = -5
}	t_error;

typedef enum e_strategy
{
	STRATEGY_ADAPTIVE = 0,
	STRATEGY_SIMPLE = 1,
	STRATEGY_MEDIUM = 2,
	STRATEGY_COMPLEX = 3
}	t_strategy;

typedef struct s_moves
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}			t_moves;

typedef struct s_options
{
	int			bench;
	t_strategy	strategy;
	t_moves		*moves;
}				t_options;

// --- 4. Function Prototypes (Declarations) ---

// === MAIN ===
void	select_strategy(t_stack *stack_a, t_options *options, float disorder);

// === ERRORS ===

// --- Error handler ---
int		print_err(t_error err);

// === OPERATIONS ===

// --- Push ---
void	push(t_stack *dest, t_stack *src);
void	pa(t_stack *a, t_stack *b, t_options *options);
void	pb(t_stack *a, t_stack *b, t_options *options);

// --- Swap ---
void	swap(t_stack *stack);
void	sa(t_stack *a, t_options *options, int is_ss);
void	sb(t_stack *b, t_options *options, int is_ss);
void	ss(t_stack *a, t_stack *b, t_options *options);

// --- Rotate ---
void	rotate(t_stack *stack);
void	ra(t_stack *a, t_options *options, int is_rr);
void	rb(t_stack *b, t_options *options, int is_rr);
void	rr(t_stack *a, t_stack *b, t_options *options);

// --- Reverse rotate ---
void	reverse_rotate(t_stack *stack);
void	rra(t_stack *a, t_options *options, int is_rrr);
void	rrb(t_stack *b, t_options *options, int is_rrr);
void	rrr(t_stack *a, t_stack *b, t_options *options);

// === PARSER ===

// --- Parser ---
int		is_flag(char *s);
int		parse_flags(char **argv, t_options *options);
int		find_index(int value, int *sorted_arr);
int		*parse_numbers(char **argv, int index, t_error *err, int *size);

// === SORTING ===

// --- Simple sort ---
int		get_min_position(t_stack *a);
void	sort_three(t_stack *a, t_options *options);
void	move_min_to_top(t_stack *a, t_options *options);
void	simple_sort(t_stack *a, t_options *options);

// --- Medium sort ---
void	assign_indexes(t_stack *a);
void	push_chunks_to_b(t_stack *a, t_stack *b, int chunk_size,
			t_options *options);
int		get_max_position(t_stack *stack);
void	push_back_to_a(t_stack *a, t_stack *b, t_options *options);
void	medium_sort(t_stack *a, t_options *options);

// --- Complex sort ---
int		get_num_bits(int index);
void	complex_sort(t_stack *a, t_options *options);

// === UTILS ===

// --- Bench ---
void	print_bench(float disorder, t_options *options);
char	*print_strategy(t_options *options);
char	*print_complexity(t_options *options, float disorder);
char	*print_adaptive(float disorder);
int		total_moves(t_moves *moves);

// --- Clean ---
void	free_split(char **split);
void	*free_node(t_node *node);
void	*free_stack(t_stack *stack);

// --- Stack ---
t_stack	*initialize_stack(void);
t_node	*initialize_node(int value, int index);
t_stack	*fill_stack(int *original, int *sorted, int size);
t_stack	*link_nodes(t_stack *stack, int *original, int *sorted, int size);

// --- Utils ---
int		*list_to_array(t_stack *stack);
int		count_numbers(char **argv, int index);
int		check_duplicates(int *nums, int size);
int		*sort_array(int *nums, int size);
float	compute_disorder(int *arr, int size);

#endif