/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helemart <helemart@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:04:27 by helemart          #+#    #+#             */
/*   Updated: 2026/11/16 14:04:29 by helemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*initialize_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *) malloc ((sizeof(t_stack)));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*initialize_node(int value, int index)
{
	t_node	*node;

	node = (t_node *) malloc ((sizeof(t_node)));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_stack	*link_nodes(t_stack *stack, int *original, int *sorted, int size)
{
	int		i;
	t_node	*current_node;
	t_node	*prev_node;

	i = 0;
	prev_node = NULL;
	while (i < size)
	{
		current_node = initialize_node(original[i],
				find_index(original[i], sorted));
		if (!current_node)
			return (free_stack(stack));
		if (stack->size == 0)
			stack->top = current_node;
		else
		{
			current_node->prev = prev_node;
			prev_node->next = current_node;
		}
		stack->bottom = current_node;
		prev_node = current_node;
		stack->size++;
		i++;
	}
	return (stack);
}

t_stack	*fill_stack(int *original, int *sorted, int size)
{
	t_stack	*stack;

	stack = initialize_stack();
	if (!stack)
		return (NULL);
	stack = link_nodes(stack, original, sorted, size);
	return (stack);
}
