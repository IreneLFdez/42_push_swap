/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helemart <helemart@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:05:18 by helemart          #+#    #+#             */
/*   Updated: 2026/11/16 14:05:20 by helemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	select_strategy(t_stack *stack_a, t_options *options, float disorder)
{
	if (is_sorted(stack_a))
		return ;
	if (options->strategy == STRATEGY_SIMPLE)
		simple_sort(stack_a, &options);
	else if (options->strategy == STRATEGY_MEDIUM)
		medium_sort(stack_a, &options);
	else if (options->strategy == STRATEGY_COMPLEX)
		complex_sort(stack_a, &options);
	else
	{
		if (disorder < 0.2)
			simple_sort(stack_a, &options);
		else if (disorder >= 0.2 && disorder < 0.5)
			medium_sort(stack_a, &options);
		else
			complex_sort(stack_a, &options);
	}
}

int		main(int argc, char **argv)
{
	int			index;
	int			*original_arr;
	int			*sorted_arr;
	int			size;
	t_stack		*stack_a;
	t_options	options;
	t_error		err;
	float		disorder;

	err = SUCCESS;
	if (argc < 2)
		return (print_invalid_input(argv[0]));
	index = parse_flags(argv, &options);
	if (index < 0)
		return (print_err(err));
	original_arr = parse_numbers(argv, index, &err, &size);
	if (err < 0)
		return (print_err(err));
	err = check_duplicates(original_arr, size);
	if (err < 0)
		return (print_err(err));
	sorted_arr = sort_array(original_arr, size);
	stack_a = fill_stack(original_arr, sorted_arr, size);
	disorder = compute_disorder(stack_a, size);
	select_strategy(stack_a, &options, disorder);
	if (options.bench == 1)
		print_bench(disorder * 100 / 100, &options);
	free_stack(stack_a);
	return (0);
}
