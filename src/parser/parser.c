/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helemart <helemart@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:03:18 by helemart          #+#    #+#             */
/*   Updated: 2026/11/16 14:03:24 by helemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/// @brief Checks if string is a valid flag.
/// @param s String to check.
/// @return Integer corresponding to selected flag or -1 on error.
int	is_flag(char *s)
{
	if (!s)
		return (-1);
	if (ft_strncmp(s, "--adaptive", 11) == 0)
		return (0);
	if (ft_strncmp(s, "--simple", 9) == 0)
		return (1);
	if (ft_strncmp(s, "--medium", 9) == 0)
		return (2);
	if (ft_strncmp(s, "--complex", 10) == 0)
		return (3);
	if (ft_strncmp(s, "--bench", 8) == 0)
		return (4);
	if (ft_isdigit(s[0]))
		return (5);
	return (-1);
}

/// @brief Fills options struct with selected flags.
/// @param argv Parameters entered to the program.
/// @param options Struct that will be updated with information found in argv.
/// @return Index where array of numbers starts in argv.
int	parse_flags(char **argv, t_options *options)
{
	int	flag;
	int	index;

	index = 1;
	options->bench = 0;
	options->strategy = STRATEGY_ADAPTIVE;
	while (argv[index] && index < 3)
	{
		flag = is_flag(argv[index]);
		if (flag == 5)
			break ;
		if (flag == 4)
		{
			if (options->bench == 1)
				return (ERR_INVALID_INPUT);
			options->bench = 1;
		}
		else if (flag >= 0 && flag <= 3)
			options->strategy = flag;
		else
			return (ERR_INVALID_INPUT);
		index++;
	}
	return (index);
}

/// @brief Finds index of correct position for a given value in the stack.
/// @param value Value we are searching.
/// @param sorted_arr Array of sorted integers to search.
/// @param size Size of array.
/// @return Index of value in sorted array or -1 if not found.
int	find_index(int value, int *sorted_arr)
{
	int	i;

	i = 0;
	while (sorted_arr[i])
	{
		if (sorted_arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

/// @brief Parses numbers from multiple parameters to array of integers.
/// @param argv Parameters passed to program.
/// @param index Index where array starts (skip flags).
/// @param err Error type (by reference).
/// @param size Size of array (by reference).
/// @return Index of value in sorted array or -1 if not found.
int	*parse_numbers(char **argv, int index, t_error *err, int *size)
{
	int		i;
	int		j;
	int		*arr_nums;
	char	**split;

	i = 0;
	*size = count_numbers(argv, index);
	arr_nums = (int *) malloc ((*size) * sizeof(int));
	if (!arr_nums)
		return (*err = ERR_MEMORY, NULL);
	while (argv[index])
	{
		split = ft_split(argv[index], ' ');
		if (!split)
		{
			*err = ERR_MEMORY;
			return (free(arr_nums), NULL);
		}
		j = 0;
		while (split[j])
			arr_nums[i++] = ft_atoi(split[j++]);
		free_split(split);
		index++;
	}
	return (arr_nums);
}
