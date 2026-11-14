/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-f <ilopez-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 12:32:56 by ilopez-f          #+#    #+#             */
/*   Updated: 2026/11/14 17:36:12 by ilopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/// @brief Encuentra el nodo con el valor mínimo de la lista.
/// @param a Lista en la que buscar el mínimo.
/// @return Poicion del nodo con el valor mínimo.
static int	get_min_position(t_stack *a)
{
	int		min_val;
	int		min_pos;
	int		i;
	t_node	*tmp;

	if (!a || !a->top)
		return (-1);
	min_val = a->top->value;
	min_pos = 0;
	i = 0;
	tmp = a->top;
	while (tmp)
	{
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_pos);
}

/// @brief Ordena un stack de 3 elementos.
/// @param a Lista a ordenar.
static void	sort_three(t_stack *a, t_options options)
{
	int	first;
	int	second;
	int	third;

	if (!a || a->size < 2)
		return ;
	first = a->top->value;
	second = a->top->next->value;
	third = a->bottom->value;
	if (first > second && second < third && first < third)
		sa(a, options);
	else if (first > second && second > third)
	{
		sa(a, options);
		rra(a, options);
	}
	else if (first > second && second < third && first > third)
		ra(a, options);
	else if (first < second && second > third && first < third)
	{
		sa(a, options);
		ra(a, options);
	}
	else if (first < second && second > third && first > third)
		rra(a,options);
}

/// @brief Busca el elemento minimo de la pila y lo rota
///			haata llevarlo al primer nodo.
/// @param a Pila a ordenar.
static void	move_min_to_top(t_stack *a, t_options options)
{
	int	min_pos;

	min_pos = get_min_position(a);
	if (min_pos <= a->size / 2)
	{
		while (min_pos-- > 0)
			ra(a, options);
	}
	else
	{
		min_pos = a->size - min_pos;
		while (min_pos-- > 0)
			rra(a, options);
	}
}

/// @brief Ordena la pila a.
/// @param a  Pila a ordenar.
/// @param b Pila auxiliar para ordenar la a.
void	simple_sort(t_stack *a, t_options options)
{
	t_stack b;
	
	b.top = NULL;
	b.bottom = NULL;
	b.size = 0;
	if (!a || a->size <= 1)
		return ;
	if (a->size <= 3)
	{
		sort_three(a, options);
		return ;
	}
	while (a->size > 3)
	{
		move_min_to_top(a, options);
		pb(a, &b, options);
	}
	sort_three(a, options);
	while (&b && b.size > 0)
		pa(a, &b, options);
}
