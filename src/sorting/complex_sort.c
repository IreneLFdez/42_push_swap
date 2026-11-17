/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-f <ilopez-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 12:16:05 by ilopez-f          #+#    #+#             */
/*   Updated: 2026/11/17 12:59:02 by ilopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	get_num_bits(int index)
{
	int	bits;

	bits = 0;
	if (index <= 0)
		return (0);
	while ((index >> bits) != 0)
		bits++;
	return (bits);
}

void	complex_sort(t_stack *a, t_options *options)
{
	t_stack	*b;
	int		num_bits;
	int		size_a;
	int		i;
	int		j;

	num_bits = get_num_bits(a->size - 1);
	size_a = a->size;
	i = 0;
	b = initialize_stack();
	while (i < num_bits)
	{
		j = 0;
		while (j < size_a)
		{
			if (((a->top->index >> i) & 1) == 0)
				pb (a, b, options);
			else
				ra (a, options, 0);
			j++;
		}
		push_back_to_a(a, b, options);
		i++;
	}
	free_stack(b);
}
