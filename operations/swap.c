/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-f <ilopez-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:07:24 by ilopez-f          #+#    #+#             */
/*   Updated: 2026/11/06 13:19:16 by ilopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (second->next)
		second->next->prev = first;
	stack->top = second;
}

/// @brief Wrapper para la pila a.
/// @sa swap();
/// @param a Puntero a la pila a que se desea modificar.
void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

/// @brief Wrapper para la pila b.
/// @sa swap();
/// @param b Puntero a la pila b que se desea modificar.
void	sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

/// @brief Intercambia los dos primeros nodos de dos pilas.
/// @param a Primera pila cuyos nodos se intercambian.
/// @param b Segunda pila cuyos nodos se intercambian.
void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
