/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helemart <helemart@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:53:39 by helemart          #+#    #+#             */
/*   Updated: 2026/11/16 14:53:41 by helemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	*free_node(t_node *node)
{
	if (!node)
		return (NULL);
	node->value = 0;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	free(node);
	return (NULL);
}

void	*free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return (NULL);
	current = stack->top;
	while (current)
	{
		next = current->next;
		free_node(current);
		current = next;
	}
	free(stack);
	return (NULL);
}
