/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-f <ilopez-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 13:13:15 by ilopez-f          #+#    #+#             */
/*   Updated: 2026/11/17 12:57:16 by ilopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/// @brief Asigna un índice ordenado a cada nodo según su valor.
/// @param a Pila a cuyos nodos se asigna el índice.
void	assign_indexes(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	if (!a || !a->top)
		return ;
	current = a->top;
	while (current)
	{
		index = 0;
		compare = a->top;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

/// @brief Pasa los elementos de a a b agrupándolos en chunks.
/// @param a Pila de la que se extraen los nodos.
/// @param b Pila a la que van los nodos.
/// @param chunk_size Tamaño del chunk.
void	push_chunks_to_b(t_stack *a, t_stack *b, int chunk_size,
	t_options *options)
{
	int	i;

	i = 0;
	while (a->size > 0)
	{
		if (a->top->index <= i)
		{
			pb(a, b, &options);
			i++;
		}
		else if (a->top->index <= i + chunk_size)
		{
			pb(a, b, &options);
			rb(b, &options, 0);
			i++;
		}
		else
			ra(a, &options, 0);
	}
}

/// @brief Encuentra la posición del nodo con el índice máximo en la pila.
/// @param stack Pila donde buscar.
/// @return Índice del nodo máximo.
int	get_max_position(t_stack *stack)
{
	int		max_val;
	int		max_pos;
	int		i;
	t_node	*tmp;

	max_val = -1;
	max_pos = 0;
	i = 0;
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->index > max_val)
		{
			max_val = tmp->index;
			max_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (max_pos);
}

/// @brief Devuelve todos los elementos de b a a ordenados de mayor a menor.
/// @param a Pila que recibe los nodos.
/// @param b Pila de la que parten los nodos.
void	push_back_to_a(t_stack *a, t_stack *b, t_options *options)
{
	int	max_pos;

	while (b->size > 0)
	{
		max_pos = get_max_position(b);
		if (max_pos <= b->size / 2)
		{
			while (max_pos-- > 0)
				rb(b, &options, 0);
		}
		else
		{
			max_pos = b->size - max_pos;
			while (max_pos-- > 0)
				rrb(b, &options, 0);
		}
		pa(a, b, &options);
	}
}

/// @brief Ordena la pila a.
/// @param a  Pila a ordenar.
/// @param b Pila auxiliar para ordenar la a.
void	medium_sort(t_stack *a, t_options *options)
{
	t_stack	*b;
	int		chunk_size;

	b = initialize_stack();
	if (!a || a->size <= 1 || is_sorted(a))
		return ;
	assign_indexes(a);
	if (a->size <= 100)
		chunk_size = 15;
	else
		chunk_size = 35;
	push_chunks_to_b(a, &b, chunk_size, &options);
	push_back_to_a(a, &b, &options);
	if (b->size == 0)
		free_stack(&b);
}
