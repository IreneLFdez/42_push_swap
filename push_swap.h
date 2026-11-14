// this is a temporary file that needs to be merged with other implementations of the final header file

// --- 1. Guards ---
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// --- 2. System Headers ---
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

// --- 3. Custom Data Types (Enums & Structures) ---

typedef struct s_node
{
	int				value;		// Number to sort
	int				index;		// (does not change)
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

typedef struct s_options
{
	int			bench;
	t_strategy	strategy;
}				t_options;

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


// --- 4. Function Prototypes (Declarations) ---

// === PARSING ===

// --- Parser ---
int		is_flag(const char *s);
int		parse_flags(char **argv, t_options *options);
int		*parse_numbers(char **argv, int index, t_error *err);
void	free_split(char **split);

// --- Stack utils ---
t_stack	*initialize_stack(t_stack *stack);
t_node	*initialize_node(t_stack *stack, int value, int *arr_nums_ordered);
void	*free_node(t_node *node);
void	*free_stack(t_stack *stack);
int		fill_stack(int *nums, t_stack *stack_a);

// --- Utils ---
int		is_valid_char(int c);
int		count_numbers(char **argv, int index);
int		check_duplicates(int *nums);
int		*sort_array(int *nums);

// --- Error handler ---
int		print_err(t_error err);

// --- Compute disorder ---
float	compute_disorder(int *arr, int size);

// === OPERATIONS ===

// --- Push ---
void	push(t_stack *dest, t_stack *src);
void	pa(t_stack *a, t_stack *b, t_options options);
void	pb(t_stack *a, t_stack *b, t_options options);

// --- Swap ---
void	swap(t_stack *stack);
void	sa(t_stack *a, t_options options);
void	sb(t_stack *b, t_options options);
void	ss(t_stack *a, t_stack *b, t_options options);

// --- Rotate ---
void	rotate(t_stack *stack);
void	ra(t_stack *a, t_options options);
void	rb(t_stack *b, t_options options);
void	rr(t_stack *a, t_stack *b, t_options options);

// --- Reverse rotate ---
void	reverse_rotate(t_stack *stack);
void	rra(t_stack *a, t_options options);
void	rrb(t_stack *b, t_options options);
void	rrr(t_stack *a, t_stack *b, t_options options);

// === SORTING STRATEGIES ===

// --- Simple sort ---
int 	get_min_position(t_node *a);
void	simple_sort(t_stack *a, t_options options);


// --- Medium sort ---
void	medium_sort(t_stack *a, t_options options);

// === BENCH ===

void	print_bench(float disorder, t_options options, t_moves moves);
char	*print_strategy(t_options options);
char	*print_complexity(t_options options, float disorder);
char	*print_adaptive(float disorder);
int		total_moves(t_moves moves);

#endif