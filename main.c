#include "push_swap.h"

void    select_strategy(t_stack *stack_a, t_options options, float disorder)
{
    if (is_sorted(stack_a))
        return ;
    if (options.strategy == STRATEGY_SIMPLE)
        simple_sort(stack_a ,options);
    else if (options.strategy == STRATEGY_MEDIUM)
        medium_sort(stack_a, options);
    else if (options.strategy == STRATEGY_COMPLEX)
        complex_sort(stack_a, options);
    else
    {
        if (disorder < 0.2)
            simple_sort(stack_a, options);
        else if (disorder >= 0.2 && disorder < 0.5)
            medium_sort(stack_a, options);
        else
            complex_sort(stack_a, options);
    }
}
int		main(int argc, char **argv)
{
	int			current_arg;
	int			*arr_nums;
	int			*arr_nums_sorted;
	t_stack		*stack_a;
	t_options	options;
	t_error		err = SUCCESS;
	float		disorder;

	// --- 0. Check number of arguments ---
	if (argc < 2)
		return (print_err(ERR_INVALID_INPUT));

	// --- 1. Parse flags ---
	current_arg = parse_flags(argv, &options);
	if (err >= 0)
		return (print_err(err));

	// --- 2. Parse numbers into array of ints ---
	arr_nums = parse_numbers(argv, current_arg, &err);
	if (err >= 0)
		return (print_err(err)); // check duplicates and nan values

	// --- 3. Create new sorted array ---
	arr_nums_sorted = sort_array(arr_nums);

	// --- 4. Initialize stack_a ---

	// --- 5. List to array ---

	// --- 6. Compute disorder ---
	disorder = compute_disorder(stack_a, stack_a->size);

	// ---8. Execute sorting algorithm---
	// INPUT IS VALID
	// TODO: Assign sorted ranks to nodes.
	// TODO: Check if stack is already sorted.
	// TODO: Execute selected sorting algorithm.
	execute_sorting_strategy(stack_a, options, disorder);

	// n. Print benchmark information if options.bench == 1.
	if (options.bench == 1)
	{
		//print_bench(float disorder, t_options options, t_moves moves);
	}
	else
	{
		// print moves
	}

	// free_stack(stack_a);
	return (0);
}