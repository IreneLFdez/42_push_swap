/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-f <ilopez-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:25:26 by ilopez-f          #+#    #+#             */
/*   Updated: 2026/11/06 13:20:32 by ilopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Mueve el primer nodo de una lista al inicio de otra.
/// @param dest Puntero a la pila de destino.
/// @param src Puntero a la pila de origen.
void	push(t_stack *dest, t_stack *src)
{
	t_node	*to_move;

	if (!src || !dest || src->size == 0)
		return ;
	to_move = src->top;
	src->top = to_move->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	src->size--;
	to_move->next = dest->top;
	to_move->prev = NULL;
	if (dest->top)
		dest->top->prev = to_move;
	else
		dest->bottom = to_move;
	dest->top = to_move;
	dest->size++;
}

/// @brief Mueve el primer nodo de b a a.
/// @param a lista a.
/// @param b lista b.
void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

/// @brief Mueve el primer nodo de a a b.
/// @param a lista a.
/// @param b lista b.
void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
