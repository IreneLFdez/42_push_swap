/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-f <ilopez-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:07:24 by ilopez-f          #+#    #+#             */
/*   Updated: 2026/11/16 12:06:08 by ilopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/// @brief función principal swap. Intercambia los dos primeros
///			nodos de una pila.
/// @param stack pila cuyos nodos intercambia.
void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2 || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	if (first->next)
		first->next->prev = first;
	else
		stack->bottom = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	stack->top = second;
}

/// @brief Wrapper para la pila a.
/// @sa swap();
/// @param a Puntero a la pila a que se desea modificar.
void	sa(t_stack *a, t_options *options, int is_ss)
{
	swap(a);
	if (options->bench == 0)
		write(1, "sa\n", 3);
	if (!is_ss)
		options->moves->sa++;
}

/// @brief Wrapper para la pila b.
/// @sa swap();
/// @param b Puntero a la pila b que se desea modificar.
void	sb(t_stack *b, t_options *options, int is_ss)
{
	swap(b);
	if (options->bench == 0)
		write(1, "sb\n", 3);
	if (!is_ss)
		options->moves->sb++;
}

/// @brief Intercambia los dos primeros nodos de dos pilas.
/// @param a Primera pila cuyos nodos se intercambian.
/// @param b Segunda pila cuyos nodos se intercambian.
void	ss(t_stack *a, t_stack *b, t_options *options)
{
	if (options->bench == 0)
		options->bench = 1;
	sa(a, &options, 1);
	sb(b, &options, 1);
	write(1, "ss\n", 3);
	options->moves->ss++;
}
