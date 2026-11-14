/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-f <ilopez-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:54:53 by ilopez-f          #+#    #+#             */
/*   Updated: 2026/11/14 16:31:07 by ilopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/// @brief Rota los nodos de la pila, de forma que el primero pasa a ser
///			el último.
/// @param stack Pila cuyo orden se modifica.
void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	last = stack->bottom;
	stack->top = first->next;
	stack->top->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	stack->bottom = first;
}

/// @brief Rota la pila a.
/// @param a Pila que se rota.
void	ra(t_stack *a, t_options options)
{
	rotate(a);
	if (options.bench == 0)
		write(1, "ra\n", 3);
}

/// @brief Rota la pila b.
/// @param b Pila que se rota.
void	rb(t_stack *b, t_options options)
{
	rotate(b);
	if (options.bench == 0)
		write(1, "rb\n", 3);
}

/// @brief rota dos pilas.
/// @param a Primera pila que se rota.
/// @param b Segunda pila que se nota.
void	rr(t_stack *a, t_stack *b, t_options options)
{
	if (options.bench == 0)
		options.bench = 1;
	ra(a, options);
	rb(b, options);
	write(1, "rr\n", 3);
}
