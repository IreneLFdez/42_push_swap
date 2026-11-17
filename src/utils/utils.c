/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helemart <helemart@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:04:42 by helemart          #+#    #+#             */
/*   Updated: 2026/11/16 14:04:43 by helemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/// @brief Converts values in stack into array of integers.
/// @param stack Stack struct from which to extract each node's value.
/// @return Array of integer values from stack.
int	*list_to_array(t_stack *stack)
{
	int		i;
	int		*list_to_array;
	t_node	*current_node;

	if (!stack)
		return (NULL);
	i = 0;
	list_to_array = (int *) malloc ((stack->size) * sizeof(int));
	if (!list_to_array)
		return (NULL);
	current_node = stack->top;
	while (current_node->next)
	{
		list_to_array[i] = current_node->value;
		current_node = current_node->next;
		i++;
	}
	return (list_to_array);
}

/// @brief Counts total numbers passed for array.
/// @param argv Array of strings passed as arguments to program.
/// @param index Index where string of numbers starts (skip flags).
/// @return Total count of numbers in string array.
int	count_numbers(char **argv, int index)
{
	int		count;
	int		flag;
	int		i;

	count = 0;
	if (!*argv)
		return (0);
	while (argv[index])
	{
		i = 0;
		flag = 0;
		while (argv[index][i])
		{
			if (argv[index][i] != ' ' && flag == 0)
			{
				flag = 1;
				count++;
			}
			else if (argv[index][i] == ' ')
				flag = 0;
			i++;
		}
		index++;
	}
	return (count);
}

/// @brief Checks if there are duplicates in an array of integers.
/// @param nums Array of integers to check.
/// @param size Size of array.
/// @return Error code.
int	check_duplicates(int *nums, int size)
{
	int	i;
	int	j;

	if (!nums)
		return (ERR_INVALID_INPUT);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (nums[i] == nums[j])
				return (ERR_DUPLICATE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

/// @brief Sorts array of integers ascendingly.
/// @param nums Array of numbers to sort.
/// @param size Size of array.
/// @return Sorted array.
int	*sort_array(int *nums, int size)
{
	int	i;
	int	temp;
	int	*nums_sorted;

	i = 0;
	temp = 0;
	nums_sorted = nums;
	while (i < size)
	{
		if (nums_sorted[i + 1] && nums_sorted[i] > nums_sorted[i + 1])
		{
			temp = nums_sorted[i];
			nums_sorted[i] = nums_sorted[i + 1];
			nums_sorted[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (nums_sorted);
}

/// @brief Computes disorder of array of integers to sort.
/// @param arr Array of integers to check.
/// @param size Size of array.
/// @return Disorder value between 00.00 and 100.00.
float	compute_disorder(int *arr, int size)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (arr[i] > arr[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return (((float)mistakes / (float)total_pairs) * 100.00);
}
