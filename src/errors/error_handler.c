/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helemart <helemart@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:06:19 by helemart          #+#    #+#             */
/*   Updated: 2026/11/16 14:06:31 by helemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/// @brief Prints out error in terminal and returns error number.
/// @param err t_error enum for error types.
/// @return Integer unsigned value of error.
int	print_err(t_error err)
{
	write(2, "Error\n", 6);
	return (-err);
}

int	print_invalid_input(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(2, &s[i], 1);
	write(2, '\n', 1);
	return (ERR_INVALID_INPUT);
}
