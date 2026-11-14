#include "../push_swap.h"

/// @brief Checks if character is valid for array of ints (string).
/// @param c Integer (character) to check.
/// @return 1 if character is valid. 0 if not.
int		is_valid_char(int c)
{
	if (ft_isdigit(c) || c == ' ' || c == '+' || c == '-')
		return (1);
	return (0);
}

/// @brief Counts total numbers passed for array.
/// @param argv Array of strings passed as arguments to program.
/// @param index Index where string of numbers starts (skip flags).
/// @return Total count of numbers in string array.
int		count_numbers(char **argv, int index)
{
	int		count;
	int		flag;
	int		i;

	count = 0;
	flag = 0;
	if (!*argv)
		return (0);
	while (argv[index])
	{
		i = 0;
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

/// @brief Computes disorder of array of integers to sort.
/// @param arr Array of integers to check.
/// @param size Size of array.
/// @return Disorder value between 0 and 1.
float	compute_disorder(int *arr, int size)
{
	int	mistakes;
	int	total_pairs;
	int i;
	int j;

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
	return (((float)mistakes / (float)total_pairs) * 100);
}

/// @brief Checks if there are duplicates in an array of integers.
/// @param nums Array of integers to check.
/// @return Error code.
int		check_duplicates(int *nums)
{
	int	i;
	int	j;

	if (!nums)
		return (ERR_INVALID_INPUT);
	i = 0;
	while (nums[i])
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
/// @return Sorted array.
int		*sort_array(int *nums)
{
	int	i;
	int	temp;
	int	*nums_sorted;

	i = 0;
	temp = 0;
	nums_sorted = nums;
	while (nums_sorted[i])
	{
		if(nums_sorted[i + 1] && nums_sorted[i] > nums_sorted[i + 1])
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

// int		*substr_array()
// {

// }
