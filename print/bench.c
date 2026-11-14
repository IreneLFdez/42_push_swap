/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helemart <helemart@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 14:52:57 by helemart          #+#    #+#             */
/*   Updated: 2026/11/14 14:53:03 by helemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_bench(float disorder, t_options options, t_moves moves)
{
	int		total_ops;
	char	*strategy;
	char	*complexity;

	total_ops = total_moves(moves);
	strategy = print_strategy(options);
	complexity = print_complexity(options, disorder);
	printf("[bench] disorder:\t%f%%\n", disorder);
	printf("[bench] strategy:\t%s / %s\n", strategy, complexity);
	printf("[bench] total_ops:\t%d\n", total_ops);
	printf("[bench] sa:\t%d sb:\t%d ss:\t%d", moves.sa, moves.sb, moves.ss);
	printf(" pa:\t%d pb:\t%d\n", moves.pa, moves.pb);
	printf("[bench] ra:\t%d rb:\t%d rr:\t%d", moves.ra, moves.rb, moves.rr);
	printf(" rra:\t%d rrb:\t%d rrr:\t%d\n", moves.rra, moves.rrb, moves.rrr);
}

char	*print_strategy(t_options options)
{
	if (options.strategy == STRATEGY_ADAPTIVE)
		return ("Adaptive");
	if (options.strategy == STRATEGY_SIMPLE)
		return ("Simple");
	if (options.strategy == STRATEGY_MEDIUM)
		return ("Medium");
	if (options.strategy == STRATEGY_COMPLEX)
		return ("Complex");
	return ("Error.");
}

char	*print_complexity(t_options options, float disorder)
{
	if (options.strategy == STRATEGY_ADAPTIVE)
		return (print_adaptive(disorder));
	if (options.strategy == STRATEGY_SIMPLE)
		return ("O(n2)");
	if (options.strategy == STRATEGY_MEDIUM)
		return ("O(n√n)");
	if (options.strategy == STRATEGY_COMPLEX)
		return ("O(n log n)");
	return ("Error.");
}

char	*print_adaptive(float disorder)
{
	if (disorder < 20.0)
		return ("O(n2)");
	if (disorder >= 20.0 && disorder < 50.0)
		return ("O(n√n)");
	if (disorder >= 50.0)
		return ("O(n log n)");
	return ("Error.");
}

int		total_moves(t_moves moves)
{
	int	total;

	total = 0;
	total += moves.sa + moves.sb + moves.ss;
	total += moves.pa + moves.pb;
	total += moves.ra + moves.rb + moves.rr;
	total += moves.rra + moves.rrb + moves.rrr;
	return (total);
}