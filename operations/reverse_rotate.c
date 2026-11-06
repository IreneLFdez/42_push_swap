/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-f <ilopez-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:04:00 by ilopez-f          #+#    #+#             */
/*   Updated: 2026/11/06 13:22:43 by ilopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Rota los nodos de la pila, de forma que el último pasa a
///			ser el primero.
/// @param stack Pila cuyo orden se modifica.
void	reverse_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	last = stack->bottom;
	stack->bottom = last->prev;
	stack->bottom->next = NULL;
	stack->top = last;
	stack->top->next = first;
	stack->top->prev = NULL;
	first->prev = last;
}

/// @brief Rota la pila a.
/// @param a Pila que se rota.
void	rra(t_stack *a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

/// @brief Rota la pila b.
/// @param b Pila que se rota.
void	rrb(t_stack *b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

/// @brief rota dos pilas.
/// @param a Primera pila que se rota.
/// @param b Segunda pila que se nota.
void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
