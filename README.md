*This project has been created as part of the 42 curriculum by ilopez-f and helemart*

# push_swap

## Because Swap_push doesn’t feel as natural

### Description

Presentation of the project, goal, and brief overlook.

### Instructions

Information about compilation, installation, and/or execution.

### Resources

References related to the topic and use of AI.

## main()

Pending tasks:

- Reduce number of variables
- Update error_handler.c file to carry main() logic
- Separate any other logic into auxiliary functions
- Test functioning

```
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
	// --- 0. Check number of arguments ---
	if (argc < 2)
		return (print_invalid_input(argv[0]));

	// --- 1. Parse flags ---
	index = parse_flags(argv, &options);
	if (index < 0)
		return (print_err(err));

	// --- 2. Parse numbers into array of ints ---
	original_arr = parse_numbers(argv, index, &err, &size);
	if (err < 0)
		return (print_err(err));

	// --- 3. Check for duplicates
	err = check_duplicates(original_arr, size);
	if (err < 0)
		return (print_err(err));

	// --- 4. Create new sorted array ---
	sorted_arr = sort_array(original_arr, size);

	// --- 5. Initialize stack_a ---
	fill_stack(original_arr, sorted_arr, size);

	// --- 6. Compute disorder ---
	disorder = compute_disorder(stack_a, size);

	// ---7. Execute sorting algorithm---
		// TODO: Check if stack is already sorted.
	select_strategy(stack_a, options, disorder);

	free_stack(stack_a);
	return (0);
}
```